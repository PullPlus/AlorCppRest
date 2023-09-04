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



#include "AlorCppRest/model/Bodyrequest_OrdersActionsStopMarketTVWarp_instrument.h"

namespace alormodel {



Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::Bodyrequest_OrdersActionsStopMarketTVWarp_instrument()
{
    m_Symbol = utility::conversions::to_string_t("");
    m_SymbolIsSet = false;
    m_ExchangeIsSet = false;
    m_InstrumentGroup = utility::conversions::to_string_t("");
    m_InstrumentGroupIsSet = false;
}

Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::~Bodyrequest_OrdersActionsStopMarketTVWarp_instrument()
{
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::validate()
{
    // TODO: implement validation
}

web::json::value Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_SymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("symbol"))] = ModelBase::toJson(m_Symbol);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_InstrumentGroupIsSet)
    {
        val[utility::conversions::to_string_t(U("instrumentGroup"))] = ModelBase::toJson(m_InstrumentGroup);
    }

    return val;
}

bool Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("symbol"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("symbol")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSymbol;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSymbol);
            setSymbol(refVal_setSymbol);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("exchange"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("exchange")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Exchange> refVal_setExchange;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExchange);
            setExchange(refVal_setExchange);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("instrumentGroup"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("instrumentGroup")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setInstrumentGroup;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInstrumentGroup);
            setInstrumentGroup(refVal_setInstrumentGroup);
        }
    }
    return ok;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_SymbolIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("symbol")), m_Symbol));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_InstrumentGroupIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("instrumentGroup")), m_InstrumentGroup));
    }
}

bool Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("symbol"))))
    {
        utility::string_t refVal_setSymbol;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("symbol"))), refVal_setSymbol );
        setSymbol(refVal_setSymbol);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exchange"))))
    {
        std::shared_ptr<Exchange> refVal_setExchange;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exchange"))), refVal_setExchange );
        setExchange(refVal_setExchange);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("instrumentGroup"))))
    {
        utility::string_t refVal_setInstrumentGroup;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("instrumentGroup"))), refVal_setInstrumentGroup );
        setInstrumentGroup(refVal_setInstrumentGroup);
    }
    return ok;
}

utility::string_t Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::getSymbol() const
{
    return m_Symbol;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::setSymbol(const utility::string_t& value)
{
    m_Symbol = value;
    m_SymbolIsSet = true;
}

bool Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::symbolIsSet() const
{
    return m_SymbolIsSet;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::unsetSymbol()
{
    m_SymbolIsSet = false;
}
std::shared_ptr<Exchange> Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::getExchange() const
{
    return m_Exchange;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::unsetExchange()
{
    m_ExchangeIsSet = false;
}
utility::string_t Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::getInstrumentGroup() const
{
    return m_InstrumentGroup;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::setInstrumentGroup(const utility::string_t& value)
{
    m_InstrumentGroup = value;
    m_InstrumentGroupIsSet = true;
}

bool Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::instrumentGroupIsSet() const
{
    return m_InstrumentGroupIsSet;
}

void Bodyrequest_OrdersActionsStopMarketTVWarp_instrument::unsetInstrumentGroup()
{
    m_InstrumentGroupIsSet = false;
}
}


