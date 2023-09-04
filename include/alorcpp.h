#ifndef AlorCpp_H
#define AlorCpp_H

#include <iostream>
#include <vector>
#include <iterator>

#include "AlorCppRest/ApiClient.h"
#include "AlorCppRest/ApiConfiguration.h"
#include "AlorCppRest/api/InstrumentsApi.h"
#include "AlorCppRest/api/SubscriptionsApi.h"
#include "AlorCppRest/api/ClientInfoApi.h"
#include "AlorCppRest/model/Ws_req_PositionsGetAndSubscribe.h"
//#include "AlorCppRest/api/OrdersWebSocketApi.h"

#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cpprest/ws_client.h>
#include <map>

/**
 * @todo write docs
 */

typedef std::pair <utility::string_t, std::shared_ptr<std::map<utility::string_t, web::json::value>>> wsTablePair;
typedef std::pair <utility::string_t, web::websockets::client::websocket_callback_client*> wsCliPair;

class AlorCpp
{
public:
    AlorCpp();
    AlorCpp(utility::string_t refreshToken);
    ~AlorCpp();
    
    void refreshJwt();//Обновление/Получение AccessToken
    std::vector<utility::string_t> getPortfolios();//Получение портфелей, из AccessToken.
    std::shared_ptr< std::vector< web::json::value > > getAllPositions(utility::string_t exchange, utility::string_t portfolio);//Получение позиций, по HTTP.
    std::shared_ptr< std::vector< web::json::value > > securitiesSearch(utility::string_t query);//Поиск инструментов, по HTTP.
    std::shared_ptr<std::map<utility::string_t, web::json::value>> getWsPositions(utility::string_t exchange, utility::string_t portfolio);//Получение позиций, по Websocket.

private:
    
    void _init(utility::string_t refreshToken); //Инициализация экзепляра данного класса.
    void _setJwt(utility::string_t jwt); //Установка текущего AccessToken
    std::vector<utility::string_t> _parseJwt(utility::string_t jwt);
    utility::string_t _getNewJwt();//Запрос нового JWT с сервера
    web::json::value _getJwtPayload();//Получение нагрузки из текущего JWT
    
    utility::string_t refreshToken;
    utility::string_t jwtToken;
    web::http::client::http_client_config httpConf;
    std::shared_ptr<alorapi::ApiClient> *apiCli;
    std::shared_ptr<alorapi::ApiConfiguration>  *apiConf;
    alorapi::InstrumentsApi *instrumentsApi;
    alorapi::SubscriptionsApi *subscriptionsApi;
    alorapi::ClientInfoApi *clientInfoApi;

    std::map<utility::string_t, std::shared_ptr<std::map<utility::string_t, web::json::value>>> wsTables; //Хранилище данных, полученных через Websocket.
    std::map<utility::string_t, web::websockets::client::websocket_callback_client*> wsClients; //Хранилище созданных Websocket-подключений.
};

#endif // AlorCpp_H

