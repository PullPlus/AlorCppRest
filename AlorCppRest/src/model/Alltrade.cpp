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



#include "AlorCppRest/model/Alltrade.h"

namespace alormodel {



Alltrade::Alltrade()
{
    m_Id = 0L;
    m_IdIsSet = false;
    m_Orderno = 0L;
    m_OrdernoIsSet = false;
    m_Symbol = utility::conversions::to_string_t("");
    m_SymbolIsSet = false;
    m_Qty = 0;
    m_QtyIsSet = false;
    m_Price = 0.0;
    m_PriceIsSet = false;
    m_Time = utility::datetime();
    m_TimeIsSet = false;
    m_Timestamp = 0L;
    m_TimestampIsSet = false;
    m_SideIsSet = false;
    m_Oi = 0;
    m_OiIsSet = false;
    m_Existing = false;
    m_ExistingIsSet = false;
}

Alltrade::~Alltrade()
{
}

void Alltrade::validate()
{
    // TODO: implement validation
}

web::json::value Alltrade::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_OrdernoIsSet)
    {
        val[utility::conversions::to_string_t(U("orderno"))] = ModelBase::toJson(m_Orderno);
    }
    if(m_SymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("symbol"))] = ModelBase::toJson(m_Symbol);
    }
    if(m_QtyIsSet)
    {
        val[utility::conversions::to_string_t(U("qty"))] = ModelBase::toJson(m_Qty);
    }
    if(m_PriceIsSet)
    {
        val[utility::conversions::to_string_t(U("price"))] = ModelBase::toJson(m_Price);
    }
    if(m_TimeIsSet)
    {
        val[utility::conversions::to_string_t(U("time"))] = ModelBase::toJson(m_Time);
    }
    if(m_TimestampIsSet)
    {
        val[utility::conversions::to_string_t(U("timestamp"))] = ModelBase::toJson(m_Timestamp);
    }
    if(m_SideIsSet)
    {
        val[utility::conversions::to_string_t(U("side"))] = ModelBase::toJson(m_Side);
    }
    if(m_OiIsSet)
    {
        val[utility::conversions::to_string_t(U("oi"))] = ModelBase::toJson(m_Oi);
    }
    if(m_ExistingIsSet)
    {
        val[utility::conversions::to_string_t(U("existing"))] = ModelBase::toJson(m_Existing);
    }

    return val;
}

bool Alltrade::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("id")));
        if(!fieldValue.is_null())
        {
            int64_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("orderno"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("orderno")));
        if(!fieldValue.is_null())
        {
            int64_t refVal_setOrderno;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOrderno);
            setOrderno(refVal_setOrderno);
        }
    }
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
    if(val.has_field(utility::conversions::to_string_t(U("qty"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qty")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setQty;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQty);
            setQty(refVal_setQty);
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
    if(val.has_field(utility::conversions::to_string_t(U("time"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("time")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setTime;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTime);
            setTime(refVal_setTime);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("timestamp"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("timestamp")));
        if(!fieldValue.is_null())
        {
            int64_t refVal_setTimestamp;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTimestamp);
            setTimestamp(refVal_setTimestamp);
        }
    }
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
    if(val.has_field(utility::conversions::to_string_t(U("oi"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("oi")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setOi;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOi);
            setOi(refVal_setOi);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("existing"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("existing")));
        if(!fieldValue.is_null())
        {
            bool refVal_setExisting;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExisting);
            setExisting(refVal_setExisting);
        }
    }
    return ok;
}

void Alltrade::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("id")), m_Id));
    }
    if(m_OrdernoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("orderno")), m_Orderno));
    }
    if(m_SymbolIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("symbol")), m_Symbol));
    }
    if(m_QtyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qty")), m_Qty));
    }
    if(m_PriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("price")), m_Price));
    }
    if(m_TimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("time")), m_Time));
    }
    if(m_TimestampIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("timestamp")), m_Timestamp));
    }
    if(m_SideIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("side")), m_Side));
    }
    if(m_OiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("oi")), m_Oi));
    }
    if(m_ExistingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("existing")), m_Existing));
    }
}

bool Alltrade::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("id"))))
    {
        int64_t refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("id"))), refVal_setId );
        setId(refVal_setId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("orderno"))))
    {
        int64_t refVal_setOrderno;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("orderno"))), refVal_setOrderno );
        setOrderno(refVal_setOrderno);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("symbol"))))
    {
        utility::string_t refVal_setSymbol;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("symbol"))), refVal_setSymbol );
        setSymbol(refVal_setSymbol);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qty"))))
    {
        int32_t refVal_setQty;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qty"))), refVal_setQty );
        setQty(refVal_setQty);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("price"))))
    {
        double refVal_setPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("price"))), refVal_setPrice );
        setPrice(refVal_setPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("time"))))
    {
        utility::datetime refVal_setTime;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("time"))), refVal_setTime );
        setTime(refVal_setTime);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("timestamp"))))
    {
        int64_t refVal_setTimestamp;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("timestamp"))), refVal_setTimestamp );
        setTimestamp(refVal_setTimestamp);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("side"))))
    {
        std::shared_ptr<Side> refVal_setSide;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("side"))), refVal_setSide );
        setSide(refVal_setSide);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("oi"))))
    {
        int32_t refVal_setOi;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("oi"))), refVal_setOi );
        setOi(refVal_setOi);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("existing"))))
    {
        bool refVal_setExisting;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("existing"))), refVal_setExisting );
        setExisting(refVal_setExisting);
    }
    return ok;
}

int64_t Alltrade::getId() const
{
    return m_Id;
}

void Alltrade::setId(int64_t value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool Alltrade::idIsSet() const
{
    return m_IdIsSet;
}

void Alltrade::unsetId()
{
    m_IdIsSet = false;
}
int64_t Alltrade::getOrderno() const
{
    return m_Orderno;
}

void Alltrade::setOrderno(int64_t value)
{
    m_Orderno = value;
    m_OrdernoIsSet = true;
}

bool Alltrade::ordernoIsSet() const
{
    return m_OrdernoIsSet;
}

void Alltrade::unsetOrderno()
{
    m_OrdernoIsSet = false;
}
utility::string_t Alltrade::getSymbol() const
{
    return m_Symbol;
}

void Alltrade::setSymbol(const utility::string_t& value)
{
    m_Symbol = value;
    m_SymbolIsSet = true;
}

bool Alltrade::symbolIsSet() const
{
    return m_SymbolIsSet;
}

void Alltrade::unsetSymbol()
{
    m_SymbolIsSet = false;
}
int32_t Alltrade::getQty() const
{
    return m_Qty;
}

void Alltrade::setQty(int32_t value)
{
    m_Qty = value;
    m_QtyIsSet = true;
}

bool Alltrade::qtyIsSet() const
{
    return m_QtyIsSet;
}

void Alltrade::unsetQty()
{
    m_QtyIsSet = false;
}
double Alltrade::getPrice() const
{
    return m_Price;
}

void Alltrade::setPrice(double value)
{
    m_Price = value;
    m_PriceIsSet = true;
}

bool Alltrade::priceIsSet() const
{
    return m_PriceIsSet;
}

void Alltrade::unsetPrice()
{
    m_PriceIsSet = false;
}
utility::datetime Alltrade::getTime() const
{
    return m_Time;
}

void Alltrade::setTime(const utility::datetime& value)
{
    m_Time = value;
    m_TimeIsSet = true;
}

bool Alltrade::timeIsSet() const
{
    return m_TimeIsSet;
}

void Alltrade::unsetTime()
{
    m_TimeIsSet = false;
}
int64_t Alltrade::getTimestamp() const
{
    return m_Timestamp;
}

void Alltrade::setTimestamp(int64_t value)
{
    m_Timestamp = value;
    m_TimestampIsSet = true;
}

bool Alltrade::timestampIsSet() const
{
    return m_TimestampIsSet;
}

void Alltrade::unsetTimestamp()
{
    m_TimestampIsSet = false;
}
std::shared_ptr<Side> Alltrade::getSide() const
{
    return m_Side;
}

void Alltrade::setSide(const std::shared_ptr<Side>& value)
{
    m_Side = value;
    m_SideIsSet = true;
}

bool Alltrade::sideIsSet() const
{
    return m_SideIsSet;
}

void Alltrade::unsetSide()
{
    m_SideIsSet = false;
}
int32_t Alltrade::getOi() const
{
    return m_Oi;
}

void Alltrade::setOi(int32_t value)
{
    m_Oi = value;
    m_OiIsSet = true;
}

bool Alltrade::oiIsSet() const
{
    return m_OiIsSet;
}

void Alltrade::unsetOi()
{
    m_OiIsSet = false;
}
bool Alltrade::isExisting() const
{
    return m_Existing;
}

void Alltrade::setExisting(bool value)
{
    m_Existing = value;
    m_ExistingIsSet = true;
}

bool Alltrade::existingIsSet() const
{
    return m_ExistingIsSet;
}

void Alltrade::unsetExisting()
{
    m_ExistingIsSet = false;
}
}


