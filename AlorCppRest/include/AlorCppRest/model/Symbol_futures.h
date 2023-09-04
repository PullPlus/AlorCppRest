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
 * Symbol_futures.h
 *
 * 
 */

#ifndef ALORMODEL_Symbol_futures_H_
#define ALORMODEL_Symbol_futures_H_


#include "AlorCppRest/ModelBase.h"

#include "AlorCppRest/model/Exchange.h"
#include <cpprest/details/basic_types.h>

namespace alormodel {


/// <summary>
/// 
/// </summary>
class  Symbol_futures
    : public ModelBase
{
public:
    Symbol_futures();
    virtual ~Symbol_futures();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Symbol_futures members

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
    /// Короткое описание на русском языке
    /// </summary>
    utility::string_t getDescription() const;
    bool descriptionIsSet() const;
    void unsetDescription();

    void setDescription(const utility::string_t& value);

    /// <summary>
    /// Аск
    /// </summary>
    double getAsk() const;
    bool askIsSet() const;
    void unsetAsk();

    void setAsk(double value);

    /// <summary>
    /// Бид
    /// </summary>
    double getBid() const;
    bool bidIsSet() const;
    void unsetBid();

    void setBid(double value);

    /// <summary>
    /// Цена предыдущего закрытия
    /// </summary>
    double getPrevClosePrice() const;
    bool prevClosePriceIsSet() const;
    void unsetPrev_close_price();

    void setPrevClosePrice(double value);

    /// <summary>
    /// Последняя цена
    /// </summary>
    double getLastPrice() const;
    bool lastPriceIsSet() const;
    void unsetLast_price();

    void setLastPrice(double value);

    /// <summary>
    /// Время последней цены (UTC)
    /// </summary>
    int64_t getLastPriceTimestamp() const;
    bool lastPriceTimestampIsSet() const;
    void unsetLast_price_timestamp();

    void setLastPriceTimestamp(int64_t value);

    /// <summary>
    /// Разность цены и цены предыдущего закрытия
    /// </summary>
    double getChange() const;
    bool changeIsSet() const;
    void unsetChange();

    void setChange(double value);

    /// <summary>
    /// Относительное изменение цены
    /// </summary>
    double getChangePercent() const;
    bool changePercentIsSet() const;
    void unsetChange_percent();

    void setChangePercent(double value);

    /// <summary>
    /// Максимальная цена
    /// </summary>
    double getHighPrice() const;
    bool highPriceIsSet() const;
    void unsetHigh_price();

    void setHighPrice(double value);

    /// <summary>
    /// Минимальная цена
    /// </summary>
    double getLowPrice() const;
    bool lowPriceIsSet() const;
    void unsetLow_price();

    void setLowPrice(double value);

    /// <summary>
    /// Начислено (НКД)
    /// </summary>
    double getAccruedInt() const;
    bool accruedIntIsSet() const;
    void unsetAccruedInt();

    void setAccruedInt(double value);

    /// <summary>
    /// Начислено (НКД)
    /// </summary>
    double getAccruedInterest() const;
    bool accruedInterestIsSet() const;
    void unsetAccrued_interest();

    void setAccruedInterest(double value);

    /// <summary>
    /// Объём
    /// </summary>
    double getVolume() const;
    bool volumeIsSet() const;
    void unsetVolume();

    void setVolume(double value);

    /// <summary>
    /// Цена открытия
    /// </summary>
    double getOpenPrice() const;
    bool openPriceIsSet() const;
    void unsetOpen_price();

    void setOpenPrice(double value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getYield() const;
    bool yieldIsSet() const;
    void unsetYield();

    void setYield(int32_t value);

    /// <summary>
    /// Размер лота
    /// </summary>
    double getLotsize() const;
    bool lotsizeIsSet() const;
    void unsetLotsize();

    void setLotsize(double value);

    /// <summary>
    /// 
    /// </summary>
    double getLotvalue() const;
    bool lotvalueIsSet() const;
    void unsetLotvalue();

    void setLotvalue(double value);

    /// <summary>
    /// 
    /// </summary>
    double getFacevalue() const;
    bool facevalueIsSet() const;
    void unsetFacevalue();

    void setFacevalue(double value);

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getType() const;
    bool typeIsSet() const;
    void unsetType();

    void setType(const utility::string_t& value);


protected:
    utility::string_t m_Symbol;
    bool m_SymbolIsSet;
    std::shared_ptr<Exchange> m_Exchange;
    bool m_ExchangeIsSet;
    utility::string_t m_Description;
    bool m_DescriptionIsSet;
    double m_Ask;
    bool m_AskIsSet;
    double m_Bid;
    bool m_BidIsSet;
    double m_Prev_close_price;
    bool m_Prev_close_priceIsSet;
    double m_Last_price;
    bool m_Last_priceIsSet;
    int64_t m_Last_price_timestamp;
    bool m_Last_price_timestampIsSet;
    double m_Change;
    bool m_ChangeIsSet;
    double m_Change_percent;
    bool m_Change_percentIsSet;
    double m_High_price;
    bool m_High_priceIsSet;
    double m_Low_price;
    bool m_Low_priceIsSet;
    double m_AccruedInt;
    bool m_AccruedIntIsSet;
    double m_Accrued_interest;
    bool m_Accrued_interestIsSet;
    double m_Volume;
    bool m_VolumeIsSet;
    double m_Open_price;
    bool m_Open_priceIsSet;
    int32_t m_Yield;
    bool m_YieldIsSet;
    double m_Lotsize;
    bool m_LotsizeIsSet;
    double m_Lotvalue;
    bool m_LotvalueIsSet;
    double m_Facevalue;
    bool m_FacevalueIsSet;
    utility::string_t m_Type;
    bool m_TypeIsSet;
};


}

#endif /* ALORMODEL_Symbol_futures_H_ */
