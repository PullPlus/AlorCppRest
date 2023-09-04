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



#include "AlorCppRest/model/Bodyrequest_OrdersActionsStop.h"

namespace alormodel {



Bodyrequest_OrdersActionsStop::Bodyrequest_OrdersActionsStop()
{
    m_Quantity = 0;
    m_QuantityIsSet = false;
    m_SideIsSet = false;
    m_TriggerPrice = 0.0;
    m_TriggerPriceIsSet = false;
    m_InstrumentIsSet = false;
    m_UserIsSet = false;
    m_OrderEndUnixTime = 0L;
    m_OrderEndUnixTimeIsSet = false;
}

Bodyrequest_OrdersActionsStop::~Bodyrequest_OrdersActionsStop()
{
}

void Bodyrequest_OrdersActionsStop::validate()
{
    // TODO: implement validation
}

web::json::value Bodyrequest_OrdersActionsStop::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_QuantityIsSet)
    {
        val[utility::conversions::to_string_t(U("Quantity"))] = ModelBase::toJson(m_Quantity);
    }
    if(m_SideIsSet)
    {
        val[utility::conversions::to_string_t(U("Side"))] = ModelBase::toJson(m_Side);
    }
    if(m_TriggerPriceIsSet)
    {
        val[utility::conversions::to_string_t(U("TriggerPrice"))] = ModelBase::toJson(m_TriggerPrice);
    }
    if(m_InstrumentIsSet)
    {
        val[utility::conversions::to_string_t(U("Instrument"))] = ModelBase::toJson(m_Instrument);
    }
    if(m_UserIsSet)
    {
        val[utility::conversions::to_string_t(U("User"))] = ModelBase::toJson(m_User);
    }
    if(m_OrderEndUnixTimeIsSet)
    {
        val[utility::conversions::to_string_t(U("OrderEndUnixTime"))] = ModelBase::toJson(m_OrderEndUnixTime);
    }

    return val;
}

bool Bodyrequest_OrdersActionsStop::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("Quantity"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Quantity")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setQuantity;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQuantity);
            setQuantity(refVal_setQuantity);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("Side"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Side")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Side> refVal_setSide;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSide);
            setSide(refVal_setSide);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("TriggerPrice"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("TriggerPrice")));
        if(!fieldValue.is_null())
        {
            double refVal_setTriggerPrice;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTriggerPrice);
            setTriggerPrice(refVal_setTriggerPrice);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("Instrument"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Instrument")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Bodyrequest_OrdersActionsStop_Instrument> refVal_setInstrument;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInstrument);
            setInstrument(refVal_setInstrument);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("User"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("User")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Bodyrequest_OrdersActionsStop_User> refVal_setUser;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUser);
            setUser(refVal_setUser);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("OrderEndUnixTime"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("OrderEndUnixTime")));
        if(!fieldValue.is_null())
        {
            int64_t refVal_setOrderEndUnixTime;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOrderEndUnixTime);
            setOrderEndUnixTime(refVal_setOrderEndUnixTime);
        }
    }
    return ok;
}

void Bodyrequest_OrdersActionsStop::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_QuantityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Quantity")), m_Quantity));
    }
    if(m_SideIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Side")), m_Side));
    }
    if(m_TriggerPriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("TriggerPrice")), m_TriggerPrice));
    }
    if(m_InstrumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Instrument")), m_Instrument));
    }
    if(m_UserIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("User")), m_User));
    }
    if(m_OrderEndUnixTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("OrderEndUnixTime")), m_OrderEndUnixTime));
    }
}

bool Bodyrequest_OrdersActionsStop::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("Quantity"))))
    {
        int32_t refVal_setQuantity;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Quantity"))), refVal_setQuantity );
        setQuantity(refVal_setQuantity);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("Side"))))
    {
        std::shared_ptr<Side> refVal_setSide;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Side"))), refVal_setSide );
        setSide(refVal_setSide);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("TriggerPrice"))))
    {
        double refVal_setTriggerPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("TriggerPrice"))), refVal_setTriggerPrice );
        setTriggerPrice(refVal_setTriggerPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("Instrument"))))
    {
        std::shared_ptr<Bodyrequest_OrdersActionsStop_Instrument> refVal_setInstrument;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Instrument"))), refVal_setInstrument );
        setInstrument(refVal_setInstrument);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("User"))))
    {
        std::shared_ptr<Bodyrequest_OrdersActionsStop_User> refVal_setUser;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("User"))), refVal_setUser );
        setUser(refVal_setUser);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("OrderEndUnixTime"))))
    {
        int64_t refVal_setOrderEndUnixTime;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("OrderEndUnixTime"))), refVal_setOrderEndUnixTime );
        setOrderEndUnixTime(refVal_setOrderEndUnixTime);
    }
    return ok;
}

int32_t Bodyrequest_OrdersActionsStop::getQuantity() const
{
    return m_Quantity;
}

void Bodyrequest_OrdersActionsStop::setQuantity(int32_t value)
{
    m_Quantity = value;
    m_QuantityIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::quantityIsSet() const
{
    return m_QuantityIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetQuantity()
{
    m_QuantityIsSet = false;
}
std::shared_ptr<Side> Bodyrequest_OrdersActionsStop::getSide() const
{
    return m_Side;
}

void Bodyrequest_OrdersActionsStop::setSide(const std::shared_ptr<Side>& value)
{
    m_Side = value;
    m_SideIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::sideIsSet() const
{
    return m_SideIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetSide()
{
    m_SideIsSet = false;
}
double Bodyrequest_OrdersActionsStop::getTriggerPrice() const
{
    return m_TriggerPrice;
}

void Bodyrequest_OrdersActionsStop::setTriggerPrice(double value)
{
    m_TriggerPrice = value;
    m_TriggerPriceIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::triggerPriceIsSet() const
{
    return m_TriggerPriceIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetTriggerPrice()
{
    m_TriggerPriceIsSet = false;
}
std::shared_ptr<Bodyrequest_OrdersActionsStop_Instrument> Bodyrequest_OrdersActionsStop::getInstrument() const
{
    return m_Instrument;
}

void Bodyrequest_OrdersActionsStop::setInstrument(const std::shared_ptr<Bodyrequest_OrdersActionsStop_Instrument>& value)
{
    m_Instrument = value;
    m_InstrumentIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::instrumentIsSet() const
{
    return m_InstrumentIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetInstrument()
{
    m_InstrumentIsSet = false;
}
std::shared_ptr<Bodyrequest_OrdersActionsStop_User> Bodyrequest_OrdersActionsStop::getUser() const
{
    return m_User;
}

void Bodyrequest_OrdersActionsStop::setUser(const std::shared_ptr<Bodyrequest_OrdersActionsStop_User>& value)
{
    m_User = value;
    m_UserIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::userIsSet() const
{
    return m_UserIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetUser()
{
    m_UserIsSet = false;
}
int64_t Bodyrequest_OrdersActionsStop::getOrderEndUnixTime() const
{
    return m_OrderEndUnixTime;
}

void Bodyrequest_OrdersActionsStop::setOrderEndUnixTime(int64_t value)
{
    m_OrderEndUnixTime = value;
    m_OrderEndUnixTimeIsSet = true;
}

bool Bodyrequest_OrdersActionsStop::orderEndUnixTimeIsSet() const
{
    return m_OrderEndUnixTimeIsSet;
}

void Bodyrequest_OrdersActionsStop::unsetOrderEndUnixTime()
{
    m_OrderEndUnixTimeIsSet = false;
}
}

