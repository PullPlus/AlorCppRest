/**
 * Alor OpenAPI V2
 * API для работы с торговой системой АЛОР Брокер. Предоставляет интерфейсы для выставления заявок и получения биржевой информации.  Данные для неавторизованных запросов предоставляются с задержкой от 15 минут, для авторизованных - без задержек.   Публичная биржевая информация может быть получена через HTTP(S) API, а также доступна через однократно установленное WebSocket соединение. <br> **Внимание!** WebSocket соединения могут и будут разрываться *(например, если клиент не успевает обрабатывать сообщения и на стороне API в буфере накопится более 5000 событий)*. <br> Во внешнем ПО необходимо предусмотреть механизмы переподключения и переподписки (при необходимости)! <br> <br>  В OpenAPI V2 доступны \"Московская Биржа\" (MOEX) и \"Биржа СПБ\" (SPBX).   <h4> Доступные типы данных </h4>  * Все сделки  * Все заявки  * Информация по инструментам  * Котировки  * Биржевые стаканы  * Исторические данные  * Позиции  * Информация о клиенте  <h4>Поддерживаемые виды заявок</h4>  * рыночные  * лимитные  * стоп-лосс  * тейк-профит  * стоп-лосс лимит  * тейк-профит лимит  <h4>    Ограничения по частоте запросов     </h4> <p>На текущий момент ограничений по количеству запросов в минуту нет, однако есть ограничение на общее количество подписок (сотни тысяч). При достижении лимита подписок клиент будет заблокирован и в течение нескольких минут не сможет создавать новые подписки. Уже существующие подписки продолжат работать. <br/>  Сервер может обрабатывать \"тяжелые\" запросы (пример - история за все время) и запросы без авторизации с меньшим приоритетом.<br/> </p>  <h4>Получение списка портфелей</h4> <p>Получить список доступных портфелей можно из JWT токена</p> <p>Для получения списка доступных портфелей необходимо декодировать JWT токен. Портфели находятся в поле <b>portfolios</b>.</p> <br/>  <h2> Авторизация </h2>  <h4>OAuth</h4>  <b>Внимание!</b>   JWT и refresh token — равносильны логину и паролю. Их нужно скрывать от публичного доступа.  <h4>Для разработчиков сторонних приложений, в которых торговлю будут вести их пользователи.</h4>  Мы предоставляем сервис для авторизации сторониих приложений по стандарту OAuth 2.0. С примером приложения, использующего OAuth сервис для авторизации пользователей можно ознакомиться в разделе  <a href=\"/examples\">Примеры</a>.  Список разрешений (scopes), которые могут быть выданы приложению: <table>   <tr>     <td><b>OrdersRead</b></td>     <td>Чтение выставленных заявок</td>   </tr>   <tr>     <td><b>OrdersCreate</b></td>     <td>Выставление заявок</td>   </tr>   <tr>     <td><b>Trades</b></td>     <td>Чтение совершенных сделок</td>   </tr>   <tr>     <td><b>Personal</b></td>     <td>Персональная информация: ФИО, почта и т.п.</td>   </tr>   <tr>     <td><b>Stats</b></td>     <td>Статистика: прибыль, средние цены и т.п.</td>   </tr> </table>  <h4>Для ведения операций от своего имени</h4>  Выписать себе <b>refresh token</b> для ведения операций от своего имени [можно здесь](https://alor.dev/open-api-tokens).  <h2>Краткое описание работы с авторизацией</h2>  Чтобы выполнить авторизованный запрос, добавьте в запрос заголовок с именем \"Authorization\" и значением, состоящим из префикса `\"Bearer \"` и валидного JWT токена.  Срок жизни JWT короткий: это сделано для безопасности.  Для большинства вариантов использования API мы рекоммендуем использовать механизм  <b>refresh token</b> .  Механизм  <b>refresh token</b>  позволяет получать JWT с новым сроком жизни. Для этого отправьте POST запрос на адрес `https://oauthdev.alor.ru/refresh?token={refreshToken}` *(тестовый контур)* или `https://oauth.alor.ru/refresh?token={refreshToken}` *(боевой контур)*. Если у  <b>refresh token</b>  не истек срок жизни и не он не был отозван, то в теле ответа в поле AccessToken вернётся свежий JWT токен.   Срок жизни  <b>refresh token</b>, получаемого обычным способом — 1 месяц.   Срок жизни  <b>refresh token</b>, получаемого самостоятельным выписыванием — год.  | |-  > Если мы для вас не завели портфели для ведения торговли в игровом контуре, оставьте заявку на <a href=\"mailto:openapi@alor.ru\">openapi@alor.ru</a> или свяжитесь с нами в [телеграме](https://t.me/AlorOpenAPI).  </br></br> Тестовый контур: `https://apidev.alor.ru`  Боевой контур: `https://api.alor.ru` 
 *
 * The version of the OpenAPI document: 1.0
 * Contact: openapi@alor.ru
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.6.0.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * DeprecatedApi.h
 *
 * 
 */

#ifndef ALORAPI_DeprecatedApi_H_
#define ALORAPI_DeprecatedApi_H_



#include "AlorCppRest/ApiClient.h"

#include "AlorCppRest/model/Bodyrequest_OrdersActionsStop.h"
#include "AlorCppRest/model/Bodyrequest_OrdersActionsStoplimit.h"
#include "AlorCppRest/model/Money.h"
#include "AlorCppRest/model/Orders_actions_400.h"
#include "AlorCppRest/model/Orders_actions_StopProfitLoss.h"
#include "AlorCppRest/model/Ws_req_StopOrdersGetAndSubscribe.h"
#include "AlorCppRest/model/Ws_res_HandledSuccessfully.h"
#include "AlorCppRest/model/Ws_res_StopOrdersGetAndSubscribe.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace alorapi {

using namespace alormodel;



class  DeprecatedApi 
{
public:

    explicit DeprecatedApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~DeprecatedApi();

    /// <summary>
    /// Снятие стоп-заявки
    /// </summary>
    /// <remarks>
    /// Снятие стоп-заявки с указанным идентификатором
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="orderId">Идентификатор заявки</param>
    /// <param name="portfolio">Идентификатор клиентского портфеля</param>
    /// <param name="stop">Является стоп-заявкой?</param>
    pplx::task<utility::string_t> _v2_client_orders_actions_orderId(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        int64_t orderId,
        utility::string_t portfolio,
        bool stop
    ) const;
    /// <summary>
    /// Создание стоп-лосс заявки
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="bodyrequestOrdersActionsStop">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_stopLoss(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        std::shared_ptr<Bodyrequest_OrdersActionsStop> bodyrequestOrdersActionsStop
    ) const;
    /// <summary>
    /// Создание стоп-лосс лимит заявки
    /// </summary>
    /// <remarks>
    /// Создание стоп-лосс лимит заявки
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="bodyrequestOrdersActionsStoplimit">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_stopLossLimit(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        std::shared_ptr<Bodyrequest_OrdersActionsStoplimit> bodyrequestOrdersActionsStoplimit
    ) const;
    /// <summary>
    /// Изменение стоп-лосс лимит заявки
    /// </summary>
    /// <remarks>
    /// Изменение стоп-лосс лимит заявки с указанным номером
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="orderId">Идентификатор заявки</param>
    /// <param name="bodyrequestOrdersActionsStoplimit">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_stopLossLimit_orderId(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        int64_t orderId,
        std::shared_ptr<Bodyrequest_OrdersActionsStoplimit> bodyrequestOrdersActionsStoplimit
    ) const;
    /// <summary>
    /// Изменение стоп-лосс заявки
    /// </summary>
    /// <remarks>
    /// Изменение стоп-лосс заявки с указанным номером
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="orderId">Идентификатор заявки</param>
    /// <param name="bodyrequestOrdersActionsStop">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_stopLoss_orderId(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        int64_t orderId,
        std::shared_ptr<Bodyrequest_OrdersActionsStop> bodyrequestOrdersActionsStop
    ) const;
    /// <summary>
    /// Создание стоп-заявки
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="bodyrequestOrdersActionsStop">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_takeProfit(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        std::shared_ptr<Bodyrequest_OrdersActionsStop> bodyrequestOrdersActionsStop
    ) const;
    /// <summary>
    /// Создание стоп-лимит заявки
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="bodyrequestOrdersActionsStoplimit">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_takeProfitLimit(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        std::shared_ptr<Bodyrequest_OrdersActionsStoplimit> bodyrequestOrdersActionsStoplimit
    ) const;
    /// <summary>
    /// Изменение стоп-лимит заявки
    /// </summary>
    /// <remarks>
    /// Изменение стоп-лимит заявки с указанным номером
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="orderId">Идентификатор заявки</param>
    /// <param name="bodyrequestOrdersActionsStoplimit">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_takeProfitLimit_orderId(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        int64_t orderId,
        std::shared_ptr<Bodyrequest_OrdersActionsStoplimit> bodyrequestOrdersActionsStoplimit
    ) const;
    /// <summary>
    /// Изменение стоп-заявки
    /// </summary>
    /// <remarks>
    /// Изменение стоп-заявки с указанным номером
    /// </remarks>
    /// <param name="xALORREQID">Требуется уникальная случайная строка в качестве идентификатора запроса. Если уже приходил запрос с таким идентификатором, то заявка не будет исполнена повторно, а в качестве ответа будет возвращена копия ответа на первый запрос с таким значением идентификатора</param>
    /// <param name="tradeServerCode">Код торгового сервера</param>
    /// <param name="orderId">Идентификатор заявки</param>
    /// <param name="bodyrequestOrdersActionsStop">Тело заявки</param>
    pplx::task<std::shared_ptr<Orders_actions_StopProfitLoss>> _v2_client_orders_actions_takeProfit_orderId(
        utility::string_t xALORREQID,
        utility::string_t tradeServerCode,
        int64_t orderId,
        std::shared_ptr<Bodyrequest_OrdersActionsStop> bodyrequestOrdersActionsStop
    ) const;
    /// <summary>
    /// Получение информации по деньгам для выбранного портфеля
    /// </summary>
    /// <remarks>
    /// Запрос информации о позиции по деньгам. Вызов существует для обратной совместимости с API v1, предпочтительно использовать другие вызовы (/summary, /risk, /positions)
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="portfolio">Идентификатор клиентского портфеля</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<Money>> exchangePortfolioMoney(
        utility::string_t exchange,
        utility::string_t portfolio,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// WebSocket подписка на информацию о стоп-заявках
    /// </summary>
    /// <remarks>
    /// **Web Socket** запрос выполняется по URL &#x60;wss://api.alor.ru/ws&#x60; (бой) или &#x60;wss://apidev.alor.ru/ws&#x60; (тест).&lt;br&gt; Подписка на информацию о текущих заявках на рынке для выбранных биржи и финансового инструмента. 
    /// </remarks>
    /// <param name="wsReqStopOrdersGetAndSubscribe"></param>
    pplx::task<std::shared_ptr<Ws_res_HandledSuccessfully>> wSProdStopOrdersSubscribe(
        std::shared_ptr<Ws_req_StopOrdersGetAndSubscribe> wsReqStopOrdersGetAndSubscribe
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}

#endif /* ALORAPI_DeprecatedApi_H_ */

