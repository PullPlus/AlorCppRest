#include "alorcpp.h"

AlorCpp::AlorCpp()
{
    _init("");
}
    
AlorCpp::AlorCpp(utility::string_t refreshToken)
{
    _init(refreshToken);
}

void AlorCpp::_init(utility::string_t refreshToken){
    this->apiConf = new std::shared_ptr<alorapi::ApiConfiguration> (new alorapi::ApiConfiguration());
    //Выбор контура
    this->apiConf->get()->setBaseUrl("https://api.alor.ru");
    //this->apiConf->get()->setBaseUrl("https://apidev.alor.ru");
    std::cout << apiConf->get()->getBaseUrl() << std::endl;
    this->refreshToken = refreshToken;
    this->apiConf->get()->setApiKey("", "");
    this->httpConf = web::http::client::http_client_config();
    std::map<utility::string_t, utility::string_t> defHeaders = this->apiConf->get()->getDefaultHeaders();
    std::map<utility::string_t, utility::string_t>::iterator it = defHeaders.begin();
    std::cout << defHeaders.size() << std::endl;
    for (int i=0; i<defHeaders.size(); i++){
        std::cout << it->first << std::endl;
        it++;
    }
    
    this->apiConf->get()->setHttpConfig(httpConf);
    this->apiCli = new std::shared_ptr<alorapi::ApiClient> (new alorapi::ApiClient(*this->apiConf));
    this->instrumentsApi = new alorapi::InstrumentsApi(*this->apiCli);
    this->subscriptionsApi = new alorapi::SubscriptionsApi(*this->apiCli);   
    this->clientInfoApi = new alorapi::ClientInfoApi(*this->apiCli);   
    
}

AlorCpp::~AlorCpp()
{
    
    auto wsCliIt = wsClients.begin(); //Дисконнект всех вебсокетов
    for(int i =0; i<wsClients.size(); i++){
        try{
            wsCliIt->second->close().then([&](){ // Successfully closed the connection. 
                std::cout << "WS disconnected: " + wsCliIt->first << std::endl;
            }).wait();
        }
        catch (web::websockets::client::websocket_exception ex){
            std::cout << ex.what() << std::endl;
        }
        delete(wsCliIt->second);
        wsCliIt++;
    }
    
    
    delete instrumentsApi;
    delete subscriptionsApi;
    delete apiCli;
    delete apiConf;
    //delete httpConf;
}

void AlorCpp::refreshJwt()
{
    utility::string_t jwt= _getNewJwt();
    //std::cout << jwt << std::endl;
    _setJwt(jwt);
}


std::vector<utility::string_t> AlorCpp::getPortfolios(){
    std::vector<utility::string_t> res;
    try{
        utility::string_t portfoliosStr = _getJwtPayload()[U("portfolios")].as_string();
        boost::split(res, portfoliosStr, boost::is_any_of(" "));
    }
    catch (web::json::json_exception ex){
        std::cout << ex.what() << std::endl;
    }
    return res;
}

std::vector<utility::string_t> AlorCpp::_parseJwt(utility::string_t jwt)
{
    std::vector<utility::string_t> mas;
    //Своеобразный split.
    int i=0, j=0; mas.push_back(""); //Инициализируем счётчики и строку для вывода
    while(jwt[i] != L'\0'){ //Пока не дойдём до конца строки
        if (jwt[i]=='.'){ i++; j++; mas.push_back(""); continue;} //Разделять по символу '.' и создавать новый отрезок
        mas.at(j)+=jwt[i]; //и сохранять символ в текущий отрезок
        i++;
    }
    
    for (i=0;i<mas.size();i++){
        try {
            utility::string_t strBase64 = mas.at(i);
            while(strBase64.length() % 4 != 0) strBase64 += '=';
            /* Иные преобразования.
            for (int k=0; k < mas.at(i).length(); k++) {
                if (mas.at(i)[k]=='-') mas.at(i)[k] = '+';
                if (mas.at(i)[k]=='_') mas.at(i)[k] = '/';
            }
            */
            std::vector<unsigned char> str = utility::conversions::from_base64(strBase64);
            mas.at(i) = "";
            for (int k=0; k < str.size(); k++) {
                mas.at(i) += str.at(k);
            }
        }
        catch (std::runtime_error err){
            std::cout<<err.what()<<std::endl;
            std::vector<utility::string_t>::iterator it = mas.begin() + i;
            mas.erase(it);
        }
    }  

    for (i=0;i<mas.size();i++){
        std::cout<< mas.at(i).length()  << " " <<mas.at(i)<<std::endl; 
    }
    
    return mas;
}

web::json::value AlorCpp::_getJwtPayload(){
    web::json::value payload;
    utility::string_t jwt = jwtToken;
    std::vector<utility::string_t> jwtStrings = _parseJwt(jwt);
    if (jwtStrings.size() >= 2)
        payload = web::json::value::parse(jwtStrings.at(1));
    return payload;
}


utility::string_t AlorCpp::_getNewJwt(){
    utility::string_t url = "";
    if (this->apiConf->get()->getBaseUrl()=="https://api.alor.ru")
        url = "https://oauth.alor.ru";
    if (this->apiConf->get()->getBaseUrl()=="https://apidev.alor.ru")
        url = "https://oauthdev.alor.ru";
    
    web::http::client::http_client client(U(url + "/refresh?token=" + this->refreshToken));    
    try{
        web::http::http_response response = client.request(web::http::methods::POST).get();
        if(response.status_code() == web::http::status_codes::OK)
        {
            try{
                utility::string_t body = response.extract_string().get();
                web::json::value obj = web::json::value::parse(body);
                return obj["AccessToken"].as_string();
            }
            catch (web::json::json_exception ex){
                std::cout << ex.what() << std::endl;
            }
        }
    } 
    catch (web::uri_exception ex){
        std::cout<< ex.what() << std::endl;
    }
    return "";
}

void AlorCpp::_setJwt(utility::string_t jwt){
    jwtToken = jwt;
    this->apiConf->get()->getDefaultHeaders()["Authorization"] = "Bearer "+jwt;
}

std::shared_ptr< std::vector< web::json::value > > AlorCpp::securitiesSearch(utility::string_t query)
{
    std::shared_ptr< std::vector< web::json::value > > resOut (new std::vector< web::json::value >());
    try{
        pplx::task<std::vector<std::shared_ptr<alormodel::Security>>> taskResult = this->instrumentsApi->devSecuritiesSearch(query, 10, 0, (utility::string_t)"", (utility::string_t)"", (utility::string_t)"", (utility::string_t)"");
        std::vector<std::shared_ptr<alormodel::Security>> res = taskResult.get();
        std::cout<<  "   res vector size:" << std::to_string(res.size()) << std::endl;
        if (res.size() > 0)
            for(int i =0 ; i<res.size(); i++)
                resOut->push_back(web::json::value(res.at(i).get()->toJson()));
    }
    catch(alorapi::ApiException ex){
        std::cout << ex.getContent(); 
    }
    return resOut;
}

std::shared_ptr< std::vector< web::json::value > > AlorCpp::getAllPositions(utility::string_t exchange, utility::string_t portfolio)
{
    std::shared_ptr<std::vector<web::json::value>> resOut (new std::vector<web::json::value>());
    try{
        pplx::task<std::vector<std::shared_ptr<alormodel::Position>>> taskResult = this->clientInfoApi->devGetAllPositions(exchange, portfolio, boost::optional<utility::string_t>("simple"), boost::optional<bool>(false));
        std::vector<std::shared_ptr<alormodel::Position>> res = taskResult.get();
        std::cout<<  "   res vector size:" << std::to_string(res.size()) << std::endl;
        if (res.size() > 0)
            for(int i =0 ; i<res.size(); i++)
                resOut->push_back(web::json::value(res.at(i).get()->toJson()));
    }
    catch(alorapi::ApiException ex){
        std::cout << ex.what() << std::endl;
    }
    return resOut;
}

std::shared_ptr<std::map<utility::string_t, web::json::value>>  AlorCpp::getWsPositions(utility::string_t exchange, utility::string_t portfolio){
    static utility::string_t tableName = "positions," + portfolio + "," + exchange;
    if (!this->wsTables[tableName].get()){
        wsTables.insert(wsTablePair(tableName, nullptr));
        wsTables[tableName]=std::make_shared<std::map<utility::string_t, web::json::value>>();
        std:: cout << "insert wsTable: " + tableName << std::endl;
    }
    try{

        alormodel::Ws_req_PositionsGetAndSubscribe wsReqPos = alormodel::Ws_req_PositionsGetAndSubscribe();

        std::shared_ptr<alormodel::Exchange> ptrEx (new alormodel::Exchange());
        ptrEx->setValue(alormodel::Exchange::eExchange::Exchange_MOEX);
        std::shared_ptr<alormodel::Format> ptrFt (new alormodel::Format());
        ptrFt->setValue(alormodel::Format::eFormat::Format_SIMPLE);
        
        boost::uuids::random_generator uuid_gen;
        boost::uuids::uuid u = uuid_gen();
        std::cout << "UUID: " << u << std::endl;
        
        wsReqPos.setGuid(boost::uuids::to_string(u));
        wsReqPos.setPortfolio(portfolio);
        wsReqPos.setToken(this->jwtToken);
        wsReqPos.setExchange(ptrEx);
        wsReqPos.setFormat(ptrFt);
        wsReqPos.setOpcode("PositionsGetAndSubscribeV2");
        
        web::json::value reqJson = wsReqPos.toJson();
        web::websockets::client::websocket_outgoing_message wsMsg;
        wsMsg.set_utf8_message(reqJson.serialize());
        
        std::cout << reqJson.serialize() << std::endl;
        
        web::websockets::client::websocket_callback_client *wsCli = new web::websockets::client::websocket_callback_client();
        if (!wsClients[tableName]){
            wsClients.insert(wsCliPair(tableName, nullptr));
            wsClients[tableName]=wsCli;
            std::cout << "insert wsClient: " + tableName << std::endl;
        }             
        
        // set receive handler
        wsClients[tableName]->set_message_handler([&](web::websockets::client::websocket_incoming_message msg){
            utility::string_t str (msg.extract_string().get());
            try{
                web::json::value val1 = web::json::value::parse(str)["data"];
                if (!val1.is_null()){
                    wsTables[tableName]->insert(std::pair<utility::string_t, web::json::value>(val1["brokerSymbol"].as_string(), val1));
                }
            }
            catch (web::json::json_exception ex){
                std::cout << ex.what() << std::endl;
            }
        });
        
        wsClients[tableName]->connect(U("wss://api.alor.ru/ws")).then([](){// We've finished connecting. 
            std::cout << "WS connected" << std::endl;
        }).wait();
        
        wsClients[tableName]->send(wsMsg).then([](){ // Successfully sent the message.
            std::cout << "WS send message " << std::endl;
        }).wait();
        //while(true){}
        }
    catch (web::websockets::client::websocket_exception ex){
        std::cout << ex.what() << std::endl;
    }
    
    return wsTables[tableName];
}
