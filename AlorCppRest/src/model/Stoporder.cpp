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



#include "AlorCppRest/model/Stoporder.h"

namespace alormodel {



Stoporder::Stoporder()
{
    m_Id = 0.0;
    m_IdIsSet = false;
    m_Symbol = utility::conversions::to_string_t("");
    m_SymbolIsSet = false;
    m_ExchangeIsSet = false;
    m_BrokerSymbol = utility::conversions::to_string_t("");
    m_BrokerSymbolIsSet = false;
    m_Type = utility::conversions::to_string_t("");
    m_TypeIsSet = false;
    m_StopPrice = 0.0;
    m_StopPriceIsSet = false;
    m_SideIsSet = false;
    m_StatusIsSet = false;
    m_EndTime = utility::datetime();
    m_EndTimeIsSet = false;
    m_Qty = 0.0;
    m_QtyIsSet = false;
    m_FilledQtyBatch = 0.0;
    m_FilledQtyBatchIsSet = false;
    m_Price = 0.0;
    m_PriceIsSet = false;
    m_Existing = false;
    m_ExistingIsSet = false;
}

Stoporder::~Stoporder()
{
}

void Stoporder::validate()
{
    // TODO: implement validation
}

web::json::value Stoporder::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_SymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("symbol"))] = ModelBase::toJson(m_Symbol);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_BrokerSymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("brokerSymbol"))] = ModelBase::toJson(m_BrokerSymbol);
    }
    if(m_TypeIsSet)
    {
        val[utility::conversions::to_string_t(U("type"))] = ModelBase::toJson(m_Type);
    }
    if(m_StopPriceIsSet)
    {
        val[utility::conversions::to_string_t(U("stopPrice"))] = ModelBase::toJson(m_StopPrice);
    }
    if(m_SideIsSet)
    {
        val[utility::conversions::to_string_t(U("side"))] = ModelBase::toJson(m_Side);
    }
    if(m_StatusIsSet)
    {
        val[utility::conversions::to_string_t(U("status"))] = ModelBase::toJson(m_Status);
    }
    if(m_EndTimeIsSet)
    {
        val[utility::conversions::to_string_t(U("endTime"))] = ModelBase::toJson(m_EndTime);
    }
    if(m_QtyIsSet)
    {
        val[utility::conversions::to_string_t(U("qty"))] = ModelBase::toJson(m_Qty);
    }
    if(m_FilledQtyBatchIsSet)
    {
        val[utility::conversions::to_string_t(U("filledQtyBatch"))] = ModelBase::toJson(m_FilledQtyBatch);
    }
    if(m_PriceIsSet)
    {
        val[utility::conversions::to_string_t(U("price"))] = ModelBase::toJson(m_Price);
    }
    if(m_ExistingIsSet)
    {
        val[utility::conversions::to_string_t(U("existing"))] = ModelBase::toJson(m_Existing);
    }

    return val;
}

bool Stoporder::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("id")));
        if(!fieldValue.is_null())
        {
            double refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
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
    if(val.has_field(utility::conversions::to_string_t(U("brokerSymbol"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("brokerSymbol")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setBrokerSymbol;
            ok &= ModelBase::fromJson(fieldValue, refVal_setBrokerSymbol);
            setBrokerSymbol(refVal_setBrokerSymbol);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("type"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("type")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setType);
            setType(refVal_setType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("stopPrice"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("stopPrice")));
        if(!fieldValue.is_null())
        {
            double refVal_setStopPrice;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStopPrice);
            setStopPrice(refVal_setStopPrice);
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
    if(val.has_field(utility::conversions::to_string_t(U("status"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("status")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OrderStatus> refVal_setStatus;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStatus);
            setStatus(refVal_setStatus);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("endTime"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("endTime")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setEndTime;
            ok &= ModelBase::fromJson(fieldValue, refVal_setEndTime);
            setEndTime(refVal_setEndTime);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qty"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qty")));
        if(!fieldValue.is_null())
        {
            double refVal_setQty;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQty);
            setQty(refVal_setQty);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("filledQtyBatch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("filledQtyBatch")));
        if(!fieldValue.is_null())
        {
            double refVal_setFilledQtyBatch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFilledQtyBatch);
            setFilledQtyBatch(refVal_setFilledQtyBatch);
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

void Stoporder::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_SymbolIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("symbol")), m_Symbol));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_BrokerSymbolIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("brokerSymbol")), m_BrokerSymbol));
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("type")), m_Type));
    }
    if(m_StopPriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("stopPrice")), m_StopPrice));
    }
    if(m_SideIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("side")), m_Side));
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("status")), m_Status));
    }
    if(m_EndTimeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("endTime")), m_EndTime));
    }
    if(m_QtyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qty")), m_Qty));
    }
    if(m_FilledQtyBatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("filledQtyBatch")), m_FilledQtyBatch));
    }
    if(m_PriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("price")), m_Price));
    }
    if(m_ExistingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("existing")), m_Existing));
    }
}

bool Stoporder::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("id"))))
    {
        double refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("id"))), refVal_setId );
        setId(refVal_setId);
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("brokerSymbol"))))
    {
        utility::string_t refVal_setBrokerSymbol;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("brokerSymbol"))), refVal_setBrokerSymbol );
        setBrokerSymbol(refVal_setBrokerSymbol);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("type"))))
    {
        utility::string_t refVal_setType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("type"))), refVal_setType );
        setType(refVal_setType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("stopPrice"))))
    {
        double refVal_setStopPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("stopPrice"))), refVal_setStopPrice );
        setStopPrice(refVal_setStopPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("side"))))
    {
        std::shared_ptr<Side> refVal_setSide;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("side"))), refVal_setSide );
        setSide(refVal_setSide);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("status"))))
    {
        std::shared_ptr<OrderStatus> refVal_setStatus;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("status"))), refVal_setStatus );
        setStatus(refVal_setStatus);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("endTime"))))
    {
        utility::datetime refVal_setEndTime;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("endTime"))), refVal_setEndTime );
        setEndTime(refVal_setEndTime);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qty"))))
    {
        double refVal_setQty;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qty"))), refVal_setQty );
        setQty(refVal_setQty);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("filledQtyBatch"))))
    {
        double refVal_setFilledQtyBatch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("filledQtyBatch"))), refVal_setFilledQtyBatch );
        setFilledQtyBatch(refVal_setFilledQtyBatch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("price"))))
    {
        double refVal_setPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("price"))), refVal_setPrice );
        setPrice(refVal_setPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("existing"))))
    {
        bool refVal_setExisting;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("existing"))), refVal_setExisting );
        setExisting(refVal_setExisting);
    }
    return ok;
}

double Stoporder::getId() const
{
    return m_Id;
}

void Stoporder::setId(double value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool Stoporder::idIsSet() const
{
    return m_IdIsSet;
}

void Stoporder::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t Stoporder::getSymbol() const
{
    return m_Symbol;
}

void Stoporder::setSymbol(const utility::string_t& value)
{
    m_Symbol = value;
    m_SymbolIsSet = true;
}

bool Stoporder::symbolIsSet() const
{
    return m_SymbolIsSet;
}

void Stoporder::unsetSymbol()
{
    m_SymbolIsSet = false;
}
std::shared_ptr<Exchange> Stoporder::getExchange() const
{
    return m_Exchange;
}

void Stoporder::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool Stoporder::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void Stoporder::unsetExchange()
{
    m_ExchangeIsSet = false;
}
utility::string_t Stoporder::getBrokerSymbol() const
{
    return m_BrokerSymbol;
}

void Stoporder::setBrokerSymbol(const utility::string_t& value)
{
    m_BrokerSymbol = value;
    m_BrokerSymbolIsSet = true;
}

bool Stoporder::brokerSymbolIsSet() const
{
    return m_BrokerSymbolIsSet;
}

void Stoporder::unsetBrokerSymbol()
{
    m_BrokerSymbolIsSet = false;
}
utility::string_t Stoporder::getType() const
{
    return m_Type;
}

void Stoporder::setType(const utility::string_t& value)
{
    m_Type = value;
    m_TypeIsSet = true;
}

bool Stoporder::typeIsSet() const
{
    return m_TypeIsSet;
}

void Stoporder::unsetType()
{
    m_TypeIsSet = false;
}
double Stoporder::getStopPrice() const
{
    return m_StopPrice;
}

void Stoporder::setStopPrice(double value)
{
    m_StopPrice = value;
    m_StopPriceIsSet = true;
}

bool Stoporder::stopPriceIsSet() const
{
    return m_StopPriceIsSet;
}

void Stoporder::unsetStopPrice()
{
    m_StopPriceIsSet = false;
}
std::shared_ptr<Side> Stoporder::getSide() const
{
    return m_Side;
}

void Stoporder::setSide(const std::shared_ptr<Side>& value)
{
    m_Side = value;
    m_SideIsSet = true;
}

bool Stoporder::sideIsSet() const
{
    return m_SideIsSet;
}

void Stoporder::unsetSide()
{
    m_SideIsSet = false;
}
std::shared_ptr<OrderStatus> Stoporder::getStatus() const
{
    return m_Status;
}

void Stoporder::setStatus(const std::shared_ptr<OrderStatus>& value)
{
    m_Status = value;
    m_StatusIsSet = true;
}

bool Stoporder::statusIsSet() const
{
    return m_StatusIsSet;
}

void Stoporder::unsetStatus()
{
    m_StatusIsSet = false;
}
utility::datetime Stoporder::getEndTime() const
{
    return m_EndTime;
}

void Stoporder::setEndTime(const utility::datetime& value)
{
    m_EndTime = value;
    m_EndTimeIsSet = true;
}

bool Stoporder::endTimeIsSet() const
{
    return m_EndTimeIsSet;
}

void Stoporder::unsetEndTime()
{
    m_EndTimeIsSet = false;
}
double Stoporder::getQty() const
{
    return m_Qty;
}

void Stoporder::setQty(double value)
{
    m_Qty = value;
    m_QtyIsSet = true;
}

bool Stoporder::qtyIsSet() const
{
    return m_QtyIsSet;
}

void Stoporder::unsetQty()
{
    m_QtyIsSet = false;
}
double Stoporder::getFilledQtyBatch() const
{
    return m_FilledQtyBatch;
}

void Stoporder::setFilledQtyBatch(double value)
{
    m_FilledQtyBatch = value;
    m_FilledQtyBatchIsSet = true;
}

bool Stoporder::filledQtyBatchIsSet() const
{
    return m_FilledQtyBatchIsSet;
}

void Stoporder::unsetFilledQtyBatch()
{
    m_FilledQtyBatchIsSet = false;
}
double Stoporder::getPrice() const
{
    return m_Price;
}

void Stoporder::setPrice(double value)
{
    m_Price = value;
    m_PriceIsSet = true;
}

bool Stoporder::priceIsSet() const
{
    return m_PriceIsSet;
}

void Stoporder::unsetPrice()
{
    m_PriceIsSet = false;
}
bool Stoporder::isExisting() const
{
    return m_Existing;
}

void Stoporder::setExisting(bool value)
{
    m_Existing = value;
    m_ExistingIsSet = true;
}

bool Stoporder::existingIsSet() const
{
    return m_ExistingIsSet;
}

void Stoporder::unsetExisting()
{
    m_ExistingIsSet = false;
}
}


