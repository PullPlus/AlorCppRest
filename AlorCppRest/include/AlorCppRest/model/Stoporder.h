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
 * Stoporder.h
 *
 * 
 */

#ifndef ALORMODEL_Stoporder_H_
#define ALORMODEL_Stoporder_H_


#include "AlorCppRest/ModelBase.h"

#include "AlorCppRest/model/Exchange.h"
#include "AlorCppRest/model/Side.h"
#include <cpprest/details/basic_types.h>
#include "AlorCppRest/model/OrderStatus.h"

namespace alormodel {


/// <summary>
/// 
/// </summary>
class  Stoporder
    : public ModelBase
{
public:
    Stoporder();
    virtual ~Stoporder();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Stoporder members

    /// <summary>
    /// Уникальный идентификатор стоп-заявки
    /// </summary>
    double getId() const;
    bool idIsSet() const;
    void unsetId();

    void setId(double value);

    /// <summary>
    /// Тикер (Код финансового инструмента)
    /// </summary>
    utility::string_t getSymbol() const;
    bool symbolIsSet() const;
    void unsetSymbol();

    void setSymbol(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Exchange> getExchange() const;
    bool exchangeIsSet() const;
    void unsetExchange();

    void setExchange(const std::shared_ptr<Exchange>& value);

    /// <summary>
    /// Пара Биржа:Тикер
    /// </summary>
    utility::string_t getBrokerSymbol() const;
    bool brokerSymbolIsSet() const;
    void unsetBrokerSymbol();

    void setBrokerSymbol(const utility::string_t& value);

    /// <summary>
    /// Тип заявки:   * &#x60;stop&#x60; - Стоп-заявка   * &#x60;stoplimit&#x60; - Стоп-лимитная заявка 
    /// </summary>
    utility::string_t getType() const;
    bool typeIsSet() const;
    void unsetType();

    void setType(const utility::string_t& value);

    /// <summary>
    /// Условная цена
    /// </summary>
    double getStopPrice() const;
    bool stopPriceIsSet() const;
    void unsetStopPrice();

    void setStopPrice(double value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Side> getSide() const;
    bool sideIsSet() const;
    void unsetSide();

    void setSide(const std::shared_ptr<Side>& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<OrderStatus> getStatus() const;
    bool statusIsSet() const;
    void unsetStatus();

    void setStatus(const std::shared_ptr<OrderStatus>& value);

    /// <summary>
    /// Время действия заявки (UTC)
    /// </summary>
    utility::datetime getEndTime() const;
    bool endTimeIsSet() const;
    void unsetEndTime();

    void setEndTime(const utility::datetime& value);

    /// <summary>
    /// Количество
    /// </summary>
    double getQty() const;
    bool qtyIsSet() const;
    void unsetQty();

    void setQty(double value);

    /// <summary>
    /// Количество исполненных
    /// </summary>
    double getFilledQtyBatch() const;
    bool filledQtyBatchIsSet() const;
    void unsetFilledQtyBatch();

    void setFilledQtyBatch(double value);

    /// <summary>
    /// Цена(Лимит)
    /// </summary>
    double getPrice() const;
    bool priceIsSet() const;
    void unsetPrice();

    void setPrice(double value);

    /// <summary>
    /// True - для данных из \&quot;снепшота\&quot;, то есть из истории. False - для новых событий
    /// </summary>
    bool isExisting() const;
    bool existingIsSet() const;
    void unsetExisting();

    void setExisting(bool value);


protected:
    double m_Id;
    bool m_IdIsSet;
    utility::string_t m_Symbol;
    bool m_SymbolIsSet;
    std::shared_ptr<Exchange> m_Exchange;
    bool m_ExchangeIsSet;
    utility::string_t m_BrokerSymbol;
    bool m_BrokerSymbolIsSet;
    utility::string_t m_Type;
    bool m_TypeIsSet;
    double m_StopPrice;
    bool m_StopPriceIsSet;
    std::shared_ptr<Side> m_Side;
    bool m_SideIsSet;
    std::shared_ptr<OrderStatus> m_Status;
    bool m_StatusIsSet;
    utility::datetime m_EndTime;
    bool m_EndTimeIsSet;
    double m_Qty;
    bool m_QtyIsSet;
    double m_FilledQtyBatch;
    bool m_FilledQtyBatchIsSet;
    double m_Price;
    bool m_PriceIsSet;
    bool m_Existing;
    bool m_ExistingIsSet;
};


}

#endif /* ALORMODEL_Stoporder_H_ */
