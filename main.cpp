#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include "alorcpp.h"

using namespace std;
using namespace web;
using namespace json;
using namespace utility;

void printJsonVec(shared_ptr<vector<value>> vec);

int main(int argc, char **argv) {
    string_t token = "";//Здесь можно указать свой токен.
    string_t portfolio = "";
    
    if (token==""){//Если токен не указан, программа предложит его вести.
        cout << "Enter the token:";
        cin >> token; std::cout << std::endl;
    }
    
    AlorCpp *cli = new AlorCpp(token);//Инициализация AlorCpp с токеном, можно и без него для неавторизованных запросов.
    cli->refreshJwt();//Обновление/Получение AccessToken
    vector<utility::string_t> portfolios = cli->getPortfolios(); //Парсинг AccessToken на список портфелей.

    printJsonVec( cli->securitiesSearch("Сбер"));//Вывод найденных инструментов, неавторизованный запрос.
    
    for (int i =0 ; i < portfolios.size(); i++){//Вывод позиций по портфелям, авторизованный запрос. 
        cout << portfolios.at(i) << std::endl;
        //cli->securitiesSearch("Сбер");
        printJsonVec(cli->getAllPositions("MOEX", portfolios.at(i)));
    }

    for (int i=0; i<portfolios.size(); i++){ //Выбор портфеля фондового рынка, по признаку D...
        if (portfolios[i][0] == 'D'){
            portfolio= portfolios[i];
            std::cout << portfolios[i] << std::endl;
            break;
        }
    }
    
    auto wsPositionsTable = cli->getWsPositions("MOEX", portfolio);//Получение ссылки на вектор, наполняемый websoket'ом.
        
    chrono::milliseconds timespan(15000); //Ожидание получения информации через websocket.
    this_thread::sleep_for(timespan);
    
    cout<< wsPositionsTable->size() <<endl;
    
    for(auto it = wsPositionsTable->cbegin(); it!=wsPositionsTable->cend(); it++){//Вывод данных, полученных через websocket.
        cout<< it->second.serialize() << std::endl;
    }
    
    delete cli;
    return 0;
}

void printJsonVec(shared_ptr<vector<value>> vec){
    for (int i=0; i<vec->size(); i++)
        cout << vec->at(i) << endl;
}
