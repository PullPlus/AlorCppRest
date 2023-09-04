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



#include "AlorCppRest/model/Bodyrequest_OrdersActionsStopLimitTVWarp.h"

namespace alormodel {



Bodyrequest_OrdersActionsStopLimitTVWarp::Bodyrequest_OrdersActionsStopLimitTVWarp()
{
    m_SideIsSet = false;
    m_ConditionIsSet = false;
    m_TriggerPrice = 0.0;
    m_TriggerPriceIsSet = false;
    m_StopEndUnixTime = 0L;
    m_StopEndUnixTimeIsSet = false;
    m_Price = 0.0;
    m_PriceIsSet = false;
    m_Quantity = 0;
    m_QuantityIsSet = false;
    m_InstrumentIsSet = false;
    m_UserIsSet = false;
    m_TimeInForceIsSet = false;
    m_IcebergFixed = 0;
    m_IcebergFixedIsSet = false;
    m_IcebergVariance = 0.0;
    m_IcebergVarianceIsSet = false;
    m_Activate = false;
    m_ActivateIsSet = false;
}

Bodyrequest_OrdersActionsStopLimitTVWarp::~Bodyrequest_OrdersActionsStopLimitTVWarp()
{
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::validate()
{
    // TODO: implement validation
}

web::json::value Bodyrequest_OrdersActionsStopLimitTVWarp::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_SideIsSet)
    {
        val[utility::conversions::to_string_t(U("side"))] = ModelBase::toJson(m_Side);
    }
    if(m_ConditionIsSet)
    {
        val[utility::conversions::to_string_t(U("condition"))] = ModelBase::toJson(m_Condition);
    }
    if(m_TriggerPriceIsSet)
    {
        val[utility::conversions::to_string_t(U("triggerPrice"))] = ModelBase::toJson(m_TriggerPrice);
    }
    if(m_StopEndUnixTimeIsSet)
    {
        val[utility::conversions::to_string_t(U("stopEndUnixTime"))] = ModelBase::toJson(m_StopEndUnixTime);
    }
    if(m_PriceIsSet)
    {
        val[utility::conversions::to_string_t(U("price"))] = ModelBase::toJson(m_Price);
    }
    if(m_QuantityIsSet)
    {
        val[utility::conversions::to_string_t(U("quantity"))] = ModelBase::toJson(m_Quantity);
    }
    if(m_InstrumentIsSet)
    {
        val[utility::conversions::to_string_t(U("instrument"))] = ModelBase::toJson(m_Instrument);
    }
    if(m_UserIsSet)
    {
        val[utility::conversions::to_string_t(U("user"))] = ModelBase::toJson(m_User);
    }
    if(m_TimeInForceIsSet)
    {
        val[utility::conversions::to_string_t(U("timeInForce"))] = ModelBase::toJson(m_TimeInForce);
    }
    if(m_IcebergFixedIsSet)
    {
        val[utility::conversions::to_string_t(U("icebergFixed"))] = ModelBase::toJson(m_IcebergFixed);
    }
    if(m_IcebergVarianceIsSet)
    {
        val[utility::conversions::to_string_t(U("icebergVariance"))] = ModelBase::toJson(m_IcebergVariance);
    }
    if(m_ActivateIsSet)
    {
        val[utility::conversions::to_string_t(U("activate"))] = ModelBase::toJson(m_Activate);
    }

    return val;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("side"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("side")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Side> refVal_setSide;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSide);
            setSide(refVal_setSide);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("condition"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("condition")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Condition> refVal_setCondition;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCondition);
            setCondition(refVal_setCondition);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("triggerPrice"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("triggerPrice")));
        if(!fieldValue.is_null())
        {
            double refVal_setTriggerPrice;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTriggerPrice);
            setTriggerPrice(refVal_setTriggerPrice);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("stopEndUnixTime"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("stopEndUnixTime")));
        if(!fieldValue.is_null())
        {
            int64_t refVal_setStopEndUnixTime;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStopEndUnixTime);
            setStopEndUnixTime(refVal_setStopEndUnixTime);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("price"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("price")));
        if(!fieldValue.is_null())
        {
            double refVal_setPrice;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPrice);
            setPrice(refVal_setPrice);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("quantity"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("quantity")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setQuantity;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQuantity);
            setQuantity(refVal_setQuantity);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("instrument"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("instrument")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_instrument> refVal_setInstrument;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInstrument);
            setInstrument(refVal_setInstrument);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("user"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("user")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_user> refVal_setUser;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUser);
            setUser(refVal_setUser);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("timeInForce"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("timeInForce")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TimeInForce> refVal_setTimeInForce;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTimeInForce);
            setTimeInForce(refVal_setTimeInForce);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("icebergFixed"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("icebergFixed")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setIcebergFixed;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIcebergFixed);
            setIcebergFixed(refVal_setIcebergFixed);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("icebergVariance"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("icebergVariance")));
        if(!fieldValue.is_null())
        {
            double refVal_setIcebergVariance;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIcebergVariance);
            setIcebergVariance(refVal_setIcebergVariance);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("activate"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("activate")));
        if(!fieldValue.is_null())
        {
            bool refVal_setActivate;
            ok &= ModelBase::fromJson(fieldValue, refVal_setActivate);
            setActivate(refVal_setActivate);
        }
    }
    return ok;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_SideIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("side")), m_Side));
    }
    if(m_ConditionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("condition")), m_Condition));
    }
    if(m_TriggerPriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("triggerPrice")), m_TriggerPrice));
    }
    if(m_StopEndUnixTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("stopEndUnixTime")), m_StopEndUnixTime));
    }
    if(m_PriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("price")), m_Price));
    }
    if(m_QuantityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("quantity")), m_Quantity));
    }
    if(m_InstrumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("instrument")), m_Instrument));
    }
    if(m_UserIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("user")), m_User));
    }
    if(m_TimeInForceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("timeInForce")), m_TimeInForce));
    }
    if(m_IcebergFixedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("icebergFixed")), m_IcebergFixed));
    }
    if(m_IcebergVarianceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("icebergVariance")), m_IcebergVariance));
    }
    if(m_ActivateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("activate")), m_Activate));
    }
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("side"))))
    {
        std::shared_ptr<Side> refVal_setSide;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("side"))), refVal_setSide );
        setSide(refVal_setSide);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("condition"))))
    {
        std::shared_ptr<Condition> refVal_setCondition;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("condition"))), refVal_setCondition );
        setCondition(refVal_setCondition);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("triggerPrice"))))
    {
        double refVal_setTriggerPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("triggerPrice"))), refVal_setTriggerPrice );
        setTriggerPrice(refVal_setTriggerPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("stopEndUnixTime"))))
    {
        int64_t refVal_setStopEndUnixTime;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("stopEndUnixTime"))), refVal_setStopEndUnixTime );
        setStopEndUnixTime(refVal_setStopEndUnixTime);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("price"))))
    {
        double refVal_setPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("price"))), refVal_setPrice );
        setPrice(refVal_setPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("quantity"))))
    {
        int32_t refVal_setQuantity;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("quantity"))), refVal_setQuantity );
        setQuantity(refVal_setQuantity);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("instrument"))))
    {
        std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_instrument> refVal_setInstrument;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("instrument"))), refVal_setInstrument );
        setInstrument(refVal_setInstrument);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("user"))))
    {
        std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_user> refVal_setUser;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("user"))), refVal_setUser );
        setUser(refVal_setUser);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("timeInForce"))))
    {
        std::shared_ptr<TimeInForce> refVal_setTimeInForce;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("timeInForce"))), refVal_setTimeInForce );
        setTimeInForce(refVal_setTimeInForce);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("icebergFixed"))))
    {
        int32_t refVal_setIcebergFixed;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("icebergFixed"))), refVal_setIcebergFixed );
        setIcebergFixed(refVal_setIcebergFixed);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("icebergVariance"))))
    {
        double refVal_setIcebergVariance;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("icebergVariance"))), refVal_setIcebergVariance );
        setIcebergVariance(refVal_setIcebergVariance);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("activate"))))
    {
        bool refVal_setActivate;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("activate"))), refVal_setActivate );
        setActivate(refVal_setActivate);
    }
    return ok;
}

std::shared_ptr<Side> Bodyrequest_OrdersActionsStopLimitTVWarp::getSide() const
{
    return m_Side;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setSide(const std::shared_ptr<Side>& value)
{
    m_Side = value;
    m_SideIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::sideIsSet() const
{
    return m_SideIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetSide()
{
    m_SideIsSet = false;
}
std::shared_ptr<Condition> Bodyrequest_OrdersActionsStopLimitTVWarp::getCondition() const
{
    return m_Condition;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setCondition(const std::shared_ptr<Condition>& value)
{
    m_Condition = value;
    m_ConditionIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::conditionIsSet() const
{
    return m_ConditionIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetCondition()
{
    m_ConditionIsSet = false;
}
double Bodyrequest_OrdersActionsStopLimitTVWarp::getTriggerPrice() const
{
    return m_TriggerPrice;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setTriggerPrice(double value)
{
    m_TriggerPrice = value;
    m_TriggerPriceIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::triggerPriceIsSet() const
{
    return m_TriggerPriceIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetTriggerPrice()
{
    m_TriggerPriceIsSet = false;
}
int64_t Bodyrequest_OrdersActionsStopLimitTVWarp::getStopEndUnixTime() const
{
    return m_StopEndUnixTime;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setStopEndUnixTime(int64_t value)
{
    m_StopEndUnixTime = value;
    m_StopEndUnixTimeIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::stopEndUnixTimeIsSet() const
{
    return m_StopEndUnixTimeIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetStopEndUnixTime()
{
    m_StopEndUnixTimeIsSet = false;
}
double Bodyrequest_OrdersActionsStopLimitTVWarp::getPrice() const
{
    return m_Price;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setPrice(double value)
{
    m_Price = value;
    m_PriceIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::priceIsSet() const
{
    return m_PriceIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetPrice()
{
    m_PriceIsSet = false;
}
int32_t Bodyrequest_OrdersActionsStopLimitTVWarp::getQuantity() const
{
    return m_Quantity;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setQuantity(int32_t value)
{
    m_Quantity = value;
    m_QuantityIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::quantityIsSet() const
{
    return m_QuantityIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetQuantity()
{
    m_QuantityIsSet = false;
}
std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_instrument> Bodyrequest_OrdersActionsStopLimitTVWarp::getInstrument() const
{
    return m_Instrument;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setInstrument(const std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_instrument>& value)
{
    m_Instrument = value;
    m_InstrumentIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::instrumentIsSet() const
{
    return m_InstrumentIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetInstrument()
{
    m_InstrumentIsSet = false;
}
std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_user> Bodyrequest_OrdersActionsStopLimitTVWarp::getUser() const
{
    return m_User;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setUser(const std::shared_ptr<Bodyrequest_OrdersActionsStopMarketTVWarp_user>& value)
{
    m_User = value;
    m_UserIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::userIsSet() const
{
    return m_UserIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetUser()
{
    m_UserIsSet = false;
}
std::shared_ptr<TimeInForce> Bodyrequest_OrdersActionsStopLimitTVWarp::getTimeInForce() const
{
    return m_TimeInForce;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setTimeInForce(const std::shared_ptr<TimeInForce>& value)
{
    m_TimeInForce = value;
    m_TimeInForceIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::timeInForceIsSet() const
{
    return m_TimeInForceIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetTimeInForce()
{
    m_TimeInForceIsSet = false;
}
int32_t Bodyrequest_OrdersActionsStopLimitTVWarp::getIcebergFixed() const
{
    return m_IcebergFixed;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setIcebergFixed(int32_t value)
{
    m_IcebergFixed = value;
    m_IcebergFixedIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::icebergFixedIsSet() const
{
    return m_IcebergFixedIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetIcebergFixed()
{
    m_IcebergFixedIsSet = false;
}
double Bodyrequest_OrdersActionsStopLimitTVWarp::getIcebergVariance() const
{
    return m_IcebergVariance;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setIcebergVariance(double value)
{
    m_IcebergVariance = value;
    m_IcebergVarianceIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::icebergVarianceIsSet() const
{
    return m_IcebergVarianceIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetIcebergVariance()
{
    m_IcebergVarianceIsSet = false;
}
bool Bodyrequest_OrdersActionsStopLimitTVWarp::isActivate() const
{
    return m_Activate;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::setActivate(bool value)
{
    m_Activate = value;
    m_ActivateIsSet = true;
}

bool Bodyrequest_OrdersActionsStopLimitTVWarp::activateIsSet() const
{
    return m_ActivateIsSet;
}

void Bodyrequest_OrdersActionsStopLimitTVWarp::unsetActivate()
{
    m_ActivateIsSet = false;
}
}


