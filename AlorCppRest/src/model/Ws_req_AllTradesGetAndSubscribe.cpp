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



#include "AlorCppRest/model/Ws_req_AllTradesGetAndSubscribe.h"

namespace alormodel {



Ws_req_AllTradesGetAndSubscribe::Ws_req_AllTradesGetAndSubscribe()
{
    m_Opcode = utility::conversions::to_string_t("");
    m_OpcodeIsSet = false;
    m_Token = utility::conversions::to_string_t("");
    m_TokenIsSet = false;
    m_Code = utility::conversions::to_string_t("");
    m_CodeIsSet = false;
    m_ExchangeIsSet = false;
    m_FormatIsSet = false;
    m_Depth = 0;
    m_DepthIsSet = false;
    m_IncludeVirtualTrades = false;
    m_IncludeVirtualTradesIsSet = false;
    m_Guid = utility::conversions::to_string_t("");
    m_GuidIsSet = false;
}

Ws_req_AllTradesGetAndSubscribe::~Ws_req_AllTradesGetAndSubscribe()
{
}

void Ws_req_AllTradesGetAndSubscribe::validate()
{
    // TODO: implement validation
}

web::json::value Ws_req_AllTradesGetAndSubscribe::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_OpcodeIsSet)
    {
        val[utility::conversions::to_string_t(U("opcode"))] = ModelBase::toJson(m_Opcode);
    }
    if(m_TokenIsSet)
    {
        val[utility::conversions::to_string_t(U("token"))] = ModelBase::toJson(m_Token);
    }
    if(m_CodeIsSet)
    {
        val[utility::conversions::to_string_t(U("code"))] = ModelBase::toJson(m_Code);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_FormatIsSet)
    {
        val[utility::conversions::to_string_t(U("format"))] = ModelBase::toJson(m_Format);
    }
    if(m_DepthIsSet)
    {
        val[utility::conversions::to_string_t(U("depth"))] = ModelBase::toJson(m_Depth);
    }
    if(m_IncludeVirtualTradesIsSet)
    {
        val[utility::conversions::to_string_t(U("includeVirtualTrades"))] = ModelBase::toJson(m_IncludeVirtualTrades);
    }
    if(m_GuidIsSet)
    {
        val[utility::conversions::to_string_t(U("guid"))] = ModelBase::toJson(m_Guid);
    }

    return val;
}

bool Ws_req_AllTradesGetAndSubscribe::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("opcode"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("opcode")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setOpcode;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOpcode);
            setOpcode(refVal_setOpcode);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("token"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("token")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setToken;
            ok &= ModelBase::fromJson(fieldValue, refVal_setToken);
            setToken(refVal_setToken);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("code"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("code")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCode;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCode);
            setCode(refVal_setCode);
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
    if(val.has_field(utility::conversions::to_string_t(U("format"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("format")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Format> refVal_setFormat;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFormat);
            setFormat(refVal_setFormat);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("depth"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("depth")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setDepth;
            ok &= ModelBase::fromJson(fieldValue, refVal_setDepth);
            setDepth(refVal_setDepth);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("includeVirtualTrades"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("includeVirtualTrades")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIncludeVirtualTrades;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIncludeVirtualTrades);
            setIncludeVirtualTrades(refVal_setIncludeVirtualTrades);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("guid"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("guid")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setGuid;
            ok &= ModelBase::fromJson(fieldValue, refVal_setGuid);
            setGuid(refVal_setGuid);
        }
    }
    return ok;
}

void Ws_req_AllTradesGetAndSubscribe::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_OpcodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("opcode")), m_Opcode));
    }
    if(m_TokenIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("token")), m_Token));
    }
    if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("code")), m_Code));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_FormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("format")), m_Format));
    }
    if(m_DepthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("depth")), m_Depth));
    }
    if(m_IncludeVirtualTradesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("includeVirtualTrades")), m_IncludeVirtualTrades));
    }
    if(m_GuidIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("guid")), m_Guid));
    }
}

bool Ws_req_AllTradesGetAndSubscribe::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("opcode"))))
    {
        utility::string_t refVal_setOpcode;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("opcode"))), refVal_setOpcode );
        setOpcode(refVal_setOpcode);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("token"))))
    {
        utility::string_t refVal_setToken;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("token"))), refVal_setToken );
        setToken(refVal_setToken);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("code"))))
    {
        utility::string_t refVal_setCode;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("code"))), refVal_setCode );
        setCode(refVal_setCode);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exchange"))))
    {
        std::shared_ptr<Exchange> refVal_setExchange;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exchange"))), refVal_setExchange );
        setExchange(refVal_setExchange);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("format"))))
    {
        std::shared_ptr<Format> refVal_setFormat;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("format"))), refVal_setFormat );
        setFormat(refVal_setFormat);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("depth"))))
    {
        int32_t refVal_setDepth;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("depth"))), refVal_setDepth );
        setDepth(refVal_setDepth);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("includeVirtualTrades"))))
    {
        bool refVal_setIncludeVirtualTrades;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("includeVirtualTrades"))), refVal_setIncludeVirtualTrades );
        setIncludeVirtualTrades(refVal_setIncludeVirtualTrades);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("guid"))))
    {
        utility::string_t refVal_setGuid;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("guid"))), refVal_setGuid );
        setGuid(refVal_setGuid);
    }
    return ok;
}

utility::string_t Ws_req_AllTradesGetAndSubscribe::getOpcode() const
{
    return m_Opcode;
}

void Ws_req_AllTradesGetAndSubscribe::setOpcode(const utility::string_t& value)
{
    m_Opcode = value;
    m_OpcodeIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::opcodeIsSet() const
{
    return m_OpcodeIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetOpcode()
{
    m_OpcodeIsSet = false;
}
utility::string_t Ws_req_AllTradesGetAndSubscribe::getToken() const
{
    return m_Token;
}

void Ws_req_AllTradesGetAndSubscribe::setToken(const utility::string_t& value)
{
    m_Token = value;
    m_TokenIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::tokenIsSet() const
{
    return m_TokenIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetToken()
{
    m_TokenIsSet = false;
}
utility::string_t Ws_req_AllTradesGetAndSubscribe::getCode() const
{
    return m_Code;
}

void Ws_req_AllTradesGetAndSubscribe::setCode(const utility::string_t& value)
{
    m_Code = value;
    m_CodeIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::codeIsSet() const
{
    return m_CodeIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetCode()
{
    m_CodeIsSet = false;
}
std::shared_ptr<Exchange> Ws_req_AllTradesGetAndSubscribe::getExchange() const
{
    return m_Exchange;
}

void Ws_req_AllTradesGetAndSubscribe::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetExchange()
{
    m_ExchangeIsSet = false;
}
std::shared_ptr<Format> Ws_req_AllTradesGetAndSubscribe::getFormat() const
{
    return m_Format;
}

void Ws_req_AllTradesGetAndSubscribe::setFormat(const std::shared_ptr<Format>& value)
{
    m_Format = value;
    m_FormatIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::formatIsSet() const
{
    return m_FormatIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetFormat()
{
    m_FormatIsSet = false;
}
int32_t Ws_req_AllTradesGetAndSubscribe::getDepth() const
{
    return m_Depth;
}

void Ws_req_AllTradesGetAndSubscribe::setDepth(int32_t value)
{
    m_Depth = value;
    m_DepthIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::depthIsSet() const
{
    return m_DepthIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetDepth()
{
    m_DepthIsSet = false;
}
bool Ws_req_AllTradesGetAndSubscribe::isIncludeVirtualTrades() const
{
    return m_IncludeVirtualTrades;
}

void Ws_req_AllTradesGetAndSubscribe::setIncludeVirtualTrades(bool value)
{
    m_IncludeVirtualTrades = value;
    m_IncludeVirtualTradesIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::includeVirtualTradesIsSet() const
{
    return m_IncludeVirtualTradesIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetIncludeVirtualTrades()
{
    m_IncludeVirtualTradesIsSet = false;
}
utility::string_t Ws_req_AllTradesGetAndSubscribe::getGuid() const
{
    return m_Guid;
}

void Ws_req_AllTradesGetAndSubscribe::setGuid(const utility::string_t& value)
{
    m_Guid = value;
    m_GuidIsSet = true;
}

bool Ws_req_AllTradesGetAndSubscribe::guidIsSet() const
{
    return m_GuidIsSet;
}

void Ws_req_AllTradesGetAndSubscribe::unsetGuid()
{
    m_GuidIsSet = false;
}
}


