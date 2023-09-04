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



#include "AlorCppRest/model/Position.h"

namespace alormodel {



Position::Position()
{
    m_Symbol = utility::conversions::to_string_t("");
    m_SymbolIsSet = false;
    m_BrokerSymbol = utility::conversions::to_string_t("");
    m_BrokerSymbolIsSet = false;
    m_ExchangeIsSet = false;
    m_Volume = 0.0;
    m_VolumeIsSet = false;
    m_CurrentVolume = 0.0;
    m_CurrentVolumeIsSet = false;
    m_AvgPrice = 0.0;
    m_AvgPriceIsSet = false;
    m_QtyUnits = 0.0;
    m_QtyUnitsIsSet = false;
    m_OpenUnits = 0.0;
    m_OpenUnitsIsSet = false;
    m_LotSize = 0.0;
    m_LotSizeIsSet = false;
    m_ShortName = utility::conversions::to_string_t("");
    m_ShortNameIsSet = false;
    m_QtyT0 = 0.0;
    m_QtyT0IsSet = false;
    m_QtyT1 = 0.0;
    m_QtyT1IsSet = false;
    m_QtyT2 = 0.0;
    m_QtyT2IsSet = false;
    m_QtyTFuture = 0.0;
    m_QtyTFutureIsSet = false;
    m_QtyT0Batch = 0.0;
    m_QtyT0BatchIsSet = false;
    m_QtyT1Batch = 0.0;
    m_QtyT1BatchIsSet = false;
    m_QtyT2Batch = 0.0;
    m_QtyT2BatchIsSet = false;
    m_QtyTFutureBatch = 0.0;
    m_QtyTFutureBatchIsSet = false;
    m_QtyBatch = 0.0;
    m_QtyBatchIsSet = false;
    m_OpenQtyBatch = 0.0;
    m_OpenQtyBatchIsSet = false;
    m_Qty = 0.0;
    m_QtyIsSet = false;
    m_Open = 0.0;
    m_OpenIsSet = false;
    m_UnrealisedPl = 0.0;
    m_UnrealisedPlIsSet = false;
    m_IsCurrency = false;
    m_IsCurrencyIsSet = false;
}

Position::~Position()
{
}

void Position::validate()
{
    // TODO: implement validation
}

web::json::value Position::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_SymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("symbol"))] = ModelBase::toJson(m_Symbol);
    }
    if(m_BrokerSymbolIsSet)
    {
        val[utility::conversions::to_string_t(U("brokerSymbol"))] = ModelBase::toJson(m_BrokerSymbol);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_VolumeIsSet)
    {
        val[utility::conversions::to_string_t(U("volume"))] = ModelBase::toJson(m_Volume);
    }
    if(m_CurrentVolumeIsSet)
    {
        val[utility::conversions::to_string_t(U("currentVolume"))] = ModelBase::toJson(m_CurrentVolume);
    }
    if(m_AvgPriceIsSet)
    {
        val[utility::conversions::to_string_t(U("avgPrice"))] = ModelBase::toJson(m_AvgPrice);
    }
    if(m_QtyUnitsIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyUnits"))] = ModelBase::toJson(m_QtyUnits);
    }
    if(m_OpenUnitsIsSet)
    {
        val[utility::conversions::to_string_t(U("openUnits"))] = ModelBase::toJson(m_OpenUnits);
    }
    if(m_LotSizeIsSet)
    {
        val[utility::conversions::to_string_t(U("lotSize"))] = ModelBase::toJson(m_LotSize);
    }
    if(m_ShortNameIsSet)
    {
        val[utility::conversions::to_string_t(U("shortName"))] = ModelBase::toJson(m_ShortName);
    }
    if(m_QtyT0IsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT0"))] = ModelBase::toJson(m_QtyT0);
    }
    if(m_QtyT1IsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT1"))] = ModelBase::toJson(m_QtyT1);
    }
    if(m_QtyT2IsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT2"))] = ModelBase::toJson(m_QtyT2);
    }
    if(m_QtyTFutureIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyTFuture"))] = ModelBase::toJson(m_QtyTFuture);
    }
    if(m_QtyT0BatchIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT0Batch"))] = ModelBase::toJson(m_QtyT0Batch);
    }
    if(m_QtyT1BatchIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT1Batch"))] = ModelBase::toJson(m_QtyT1Batch);
    }
    if(m_QtyT2BatchIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyT2Batch"))] = ModelBase::toJson(m_QtyT2Batch);
    }
    if(m_QtyTFutureBatchIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyTFutureBatch"))] = ModelBase::toJson(m_QtyTFutureBatch);
    }
    if(m_QtyBatchIsSet)
    {
        val[utility::conversions::to_string_t(U("qtyBatch"))] = ModelBase::toJson(m_QtyBatch);
    }
    if(m_OpenQtyBatchIsSet)
    {
        val[utility::conversions::to_string_t(U("openQtyBatch"))] = ModelBase::toJson(m_OpenQtyBatch);
    }
    if(m_QtyIsSet)
    {
        val[utility::conversions::to_string_t(U("qty"))] = ModelBase::toJson(m_Qty);
    }
    if(m_OpenIsSet)
    {
        val[utility::conversions::to_string_t(U("open"))] = ModelBase::toJson(m_Open);
    }
    if(m_UnrealisedPlIsSet)
    {
        val[utility::conversions::to_string_t(U("unrealisedPl"))] = ModelBase::toJson(m_UnrealisedPl);
    }
    if(m_IsCurrencyIsSet)
    {
        val[utility::conversions::to_string_t(U("isCurrency"))] = ModelBase::toJson(m_IsCurrency);
    }

    return val;
}

bool Position::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("volume"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("volume")));
        if(!fieldValue.is_null())
        {
            double refVal_setVolume;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVolume);
            setVolume(refVal_setVolume);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("currentVolume"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("currentVolume")));
        if(!fieldValue.is_null())
        {
            double refVal_setCurrentVolume;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCurrentVolume);
            setCurrentVolume(refVal_setCurrentVolume);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("avgPrice"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("avgPrice")));
        if(!fieldValue.is_null())
        {
            double refVal_setAvgPrice;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAvgPrice);
            setAvgPrice(refVal_setAvgPrice);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyUnits"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyUnits")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyUnits;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyUnits);
            setQtyUnits(refVal_setQtyUnits);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("openUnits"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("openUnits")));
        if(!fieldValue.is_null())
        {
            double refVal_setOpenUnits;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOpenUnits);
            setOpenUnits(refVal_setOpenUnits);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("lotSize"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("lotSize")));
        if(!fieldValue.is_null())
        {
            double refVal_setLotSize;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLotSize);
            setLotSize(refVal_setLotSize);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("shortName"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("shortName")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setShortName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setShortName);
            setShortName(refVal_setShortName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT0"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT0")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT0;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT0);
            setQtyT0(refVal_setQtyT0);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT1"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT1")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT1;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT1);
            setQtyT1(refVal_setQtyT1);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT2"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT2")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT2;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT2);
            setQtyT2(refVal_setQtyT2);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyTFuture"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyTFuture")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyTFuture;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyTFuture);
            setQtyTFuture(refVal_setQtyTFuture);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT0Batch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT0Batch")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT0Batch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT0Batch);
            setQtyT0Batch(refVal_setQtyT0Batch);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT1Batch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT1Batch")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT1Batch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT1Batch);
            setQtyT1Batch(refVal_setQtyT1Batch);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyT2Batch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyT2Batch")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyT2Batch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyT2Batch);
            setQtyT2Batch(refVal_setQtyT2Batch);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyTFutureBatch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyTFutureBatch")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyTFutureBatch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyTFutureBatch);
            setQtyTFutureBatch(refVal_setQtyTFutureBatch);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("qtyBatch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("qtyBatch")));
        if(!fieldValue.is_null())
        {
            double refVal_setQtyBatch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setQtyBatch);
            setQtyBatch(refVal_setQtyBatch);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("openQtyBatch"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("openQtyBatch")));
        if(!fieldValue.is_null())
        {
            double refVal_setOpenQtyBatch;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOpenQtyBatch);
            setOpenQtyBatch(refVal_setOpenQtyBatch);
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
    if(val.has_field(utility::conversions::to_string_t(U("open"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("open")));
        if(!fieldValue.is_null())
        {
            double refVal_setOpen;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOpen);
            setOpen(refVal_setOpen);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("unrealisedPl"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("unrealisedPl")));
        if(!fieldValue.is_null())
        {
            double refVal_setUnrealisedPl;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUnrealisedPl);
            setUnrealisedPl(refVal_setUnrealisedPl);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isCurrency"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isCurrency")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsCurrency;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsCurrency);
            setIsCurrency(refVal_setIsCurrency);
        }
    }
    return ok;
}

void Position::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_BrokerSymbolIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("brokerSymbol")), m_BrokerSymbol));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_VolumeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("volume")), m_Volume));
    }
    if(m_CurrentVolumeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("currentVolume")), m_CurrentVolume));
    }
    if(m_AvgPriceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("avgPrice")), m_AvgPrice));
    }
    if(m_QtyUnitsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyUnits")), m_QtyUnits));
    }
    if(m_OpenUnitsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("openUnits")), m_OpenUnits));
    }
    if(m_LotSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("lotSize")), m_LotSize));
    }
    if(m_ShortNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("shortName")), m_ShortName));
    }
    if(m_QtyT0IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT0")), m_QtyT0));
    }
    if(m_QtyT1IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT1")), m_QtyT1));
    }
    if(m_QtyT2IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT2")), m_QtyT2));
    }
    if(m_QtyTFutureIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyTFuture")), m_QtyTFuture));
    }
    if(m_QtyT0BatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT0Batch")), m_QtyT0Batch));
    }
    if(m_QtyT1BatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT1Batch")), m_QtyT1Batch));
    }
    if(m_QtyT2BatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyT2Batch")), m_QtyT2Batch));
    }
    if(m_QtyTFutureBatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyTFutureBatch")), m_QtyTFutureBatch));
    }
    if(m_QtyBatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qtyBatch")), m_QtyBatch));
    }
    if(m_OpenQtyBatchIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("openQtyBatch")), m_OpenQtyBatch));
    }
    if(m_QtyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("qty")), m_Qty));
    }
    if(m_OpenIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("open")), m_Open));
    }
    if(m_UnrealisedPlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("unrealisedPl")), m_UnrealisedPl));
    }
    if(m_IsCurrencyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isCurrency")), m_IsCurrency));
    }
}

bool Position::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("brokerSymbol"))))
    {
        utility::string_t refVal_setBrokerSymbol;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("brokerSymbol"))), refVal_setBrokerSymbol );
        setBrokerSymbol(refVal_setBrokerSymbol);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exchange"))))
    {
        std::shared_ptr<Exchange> refVal_setExchange;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exchange"))), refVal_setExchange );
        setExchange(refVal_setExchange);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("volume"))))
    {
        double refVal_setVolume;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("volume"))), refVal_setVolume );
        setVolume(refVal_setVolume);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("currentVolume"))))
    {
        double refVal_setCurrentVolume;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("currentVolume"))), refVal_setCurrentVolume );
        setCurrentVolume(refVal_setCurrentVolume);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("avgPrice"))))
    {
        double refVal_setAvgPrice;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("avgPrice"))), refVal_setAvgPrice );
        setAvgPrice(refVal_setAvgPrice);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyUnits"))))
    {
        double refVal_setQtyUnits;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyUnits"))), refVal_setQtyUnits );
        setQtyUnits(refVal_setQtyUnits);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("openUnits"))))
    {
        double refVal_setOpenUnits;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("openUnits"))), refVal_setOpenUnits );
        setOpenUnits(refVal_setOpenUnits);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("lotSize"))))
    {
        double refVal_setLotSize;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("lotSize"))), refVal_setLotSize );
        setLotSize(refVal_setLotSize);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("shortName"))))
    {
        utility::string_t refVal_setShortName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("shortName"))), refVal_setShortName );
        setShortName(refVal_setShortName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT0"))))
    {
        double refVal_setQtyT0;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT0"))), refVal_setQtyT0 );
        setQtyT0(refVal_setQtyT0);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT1"))))
    {
        double refVal_setQtyT1;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT1"))), refVal_setQtyT1 );
        setQtyT1(refVal_setQtyT1);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT2"))))
    {
        double refVal_setQtyT2;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT2"))), refVal_setQtyT2 );
        setQtyT2(refVal_setQtyT2);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyTFuture"))))
    {
        double refVal_setQtyTFuture;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyTFuture"))), refVal_setQtyTFuture );
        setQtyTFuture(refVal_setQtyTFuture);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT0Batch"))))
    {
        double refVal_setQtyT0Batch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT0Batch"))), refVal_setQtyT0Batch );
        setQtyT0Batch(refVal_setQtyT0Batch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT1Batch"))))
    {
        double refVal_setQtyT1Batch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT1Batch"))), refVal_setQtyT1Batch );
        setQtyT1Batch(refVal_setQtyT1Batch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyT2Batch"))))
    {
        double refVal_setQtyT2Batch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyT2Batch"))), refVal_setQtyT2Batch );
        setQtyT2Batch(refVal_setQtyT2Batch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyTFutureBatch"))))
    {
        double refVal_setQtyTFutureBatch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyTFutureBatch"))), refVal_setQtyTFutureBatch );
        setQtyTFutureBatch(refVal_setQtyTFutureBatch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qtyBatch"))))
    {
        double refVal_setQtyBatch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qtyBatch"))), refVal_setQtyBatch );
        setQtyBatch(refVal_setQtyBatch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("openQtyBatch"))))
    {
        double refVal_setOpenQtyBatch;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("openQtyBatch"))), refVal_setOpenQtyBatch );
        setOpenQtyBatch(refVal_setOpenQtyBatch);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("qty"))))
    {
        double refVal_setQty;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("qty"))), refVal_setQty );
        setQty(refVal_setQty);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("open"))))
    {
        double refVal_setOpen;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("open"))), refVal_setOpen );
        setOpen(refVal_setOpen);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("unrealisedPl"))))
    {
        double refVal_setUnrealisedPl;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("unrealisedPl"))), refVal_setUnrealisedPl );
        setUnrealisedPl(refVal_setUnrealisedPl);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isCurrency"))))
    {
        bool refVal_setIsCurrency;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isCurrency"))), refVal_setIsCurrency );
        setIsCurrency(refVal_setIsCurrency);
    }
    return ok;
}

utility::string_t Position::getSymbol() const
{
    return m_Symbol;
}

void Position::setSymbol(const utility::string_t& value)
{
    m_Symbol = value;
    m_SymbolIsSet = true;
}

bool Position::symbolIsSet() const
{
    return m_SymbolIsSet;
}

void Position::unsetSymbol()
{
    m_SymbolIsSet = false;
}
utility::string_t Position::getBrokerSymbol() const
{
    return m_BrokerSymbol;
}

void Position::setBrokerSymbol(const utility::string_t& value)
{
    m_BrokerSymbol = value;
    m_BrokerSymbolIsSet = true;
}

bool Position::brokerSymbolIsSet() const
{
    return m_BrokerSymbolIsSet;
}

void Position::unsetBrokerSymbol()
{
    m_BrokerSymbolIsSet = false;
}
std::shared_ptr<Exchange> Position::getExchange() const
{
    return m_Exchange;
}

void Position::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool Position::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void Position::unsetExchange()
{
    m_ExchangeIsSet = false;
}
double Position::getVolume() const
{
    return m_Volume;
}

void Position::setVolume(double value)
{
    m_Volume = value;
    m_VolumeIsSet = true;
}

bool Position::volumeIsSet() const
{
    return m_VolumeIsSet;
}

void Position::unsetVolume()
{
    m_VolumeIsSet = false;
}
double Position::getCurrentVolume() const
{
    return m_CurrentVolume;
}

void Position::setCurrentVolume(double value)
{
    m_CurrentVolume = value;
    m_CurrentVolumeIsSet = true;
}

bool Position::currentVolumeIsSet() const
{
    return m_CurrentVolumeIsSet;
}

void Position::unsetCurrentVolume()
{
    m_CurrentVolumeIsSet = false;
}
double Position::getAvgPrice() const
{
    return m_AvgPrice;
}

void Position::setAvgPrice(double value)
{
    m_AvgPrice = value;
    m_AvgPriceIsSet = true;
}

bool Position::avgPriceIsSet() const
{
    return m_AvgPriceIsSet;
}

void Position::unsetAvgPrice()
{
    m_AvgPriceIsSet = false;
}
double Position::getQtyUnits() const
{
    return m_QtyUnits;
}

void Position::setQtyUnits(double value)
{
    m_QtyUnits = value;
    m_QtyUnitsIsSet = true;
}

bool Position::qtyUnitsIsSet() const
{
    return m_QtyUnitsIsSet;
}

void Position::unsetQtyUnits()
{
    m_QtyUnitsIsSet = false;
}
double Position::getOpenUnits() const
{
    return m_OpenUnits;
}

void Position::setOpenUnits(double value)
{
    m_OpenUnits = value;
    m_OpenUnitsIsSet = true;
}

bool Position::openUnitsIsSet() const
{
    return m_OpenUnitsIsSet;
}

void Position::unsetOpenUnits()
{
    m_OpenUnitsIsSet = false;
}
double Position::getLotSize() const
{
    return m_LotSize;
}

void Position::setLotSize(double value)
{
    m_LotSize = value;
    m_LotSizeIsSet = true;
}

bool Position::lotSizeIsSet() const
{
    return m_LotSizeIsSet;
}

void Position::unsetLotSize()
{
    m_LotSizeIsSet = false;
}
utility::string_t Position::getShortName() const
{
    return m_ShortName;
}

void Position::setShortName(const utility::string_t& value)
{
    m_ShortName = value;
    m_ShortNameIsSet = true;
}

bool Position::shortNameIsSet() const
{
    return m_ShortNameIsSet;
}

void Position::unsetShortName()
{
    m_ShortNameIsSet = false;
}
double Position::getQtyT0() const
{
    return m_QtyT0;
}

void Position::setQtyT0(double value)
{
    m_QtyT0 = value;
    m_QtyT0IsSet = true;
}

bool Position::qtyT0IsSet() const
{
    return m_QtyT0IsSet;
}

void Position::unsetQtyT0()
{
    m_QtyT0IsSet = false;
}
double Position::getQtyT1() const
{
    return m_QtyT1;
}

void Position::setQtyT1(double value)
{
    m_QtyT1 = value;
    m_QtyT1IsSet = true;
}

bool Position::qtyT1IsSet() const
{
    return m_QtyT1IsSet;
}

void Position::unsetQtyT1()
{
    m_QtyT1IsSet = false;
}
double Position::getQtyT2() const
{
    return m_QtyT2;
}

void Position::setQtyT2(double value)
{
    m_QtyT2 = value;
    m_QtyT2IsSet = true;
}

bool Position::qtyT2IsSet() const
{
    return m_QtyT2IsSet;
}

void Position::unsetQtyT2()
{
    m_QtyT2IsSet = false;
}
double Position::getQtyTFuture() const
{
    return m_QtyTFuture;
}

void Position::setQtyTFuture(double value)
{
    m_QtyTFuture = value;
    m_QtyTFutureIsSet = true;
}

bool Position::qtyTFutureIsSet() const
{
    return m_QtyTFutureIsSet;
}

void Position::unsetQtyTFuture()
{
    m_QtyTFutureIsSet = false;
}
double Position::getQtyT0Batch() const
{
    return m_QtyT0Batch;
}

void Position::setQtyT0Batch(double value)
{
    m_QtyT0Batch = value;
    m_QtyT0BatchIsSet = true;
}

bool Position::qtyT0BatchIsSet() const
{
    return m_QtyT0BatchIsSet;
}

void Position::unsetQtyT0Batch()
{
    m_QtyT0BatchIsSet = false;
}
double Position::getQtyT1Batch() const
{
    return m_QtyT1Batch;
}

void Position::setQtyT1Batch(double value)
{
    m_QtyT1Batch = value;
    m_QtyT1BatchIsSet = true;
}

bool Position::qtyT1BatchIsSet() const
{
    return m_QtyT1BatchIsSet;
}

void Position::unsetQtyT1Batch()
{
    m_QtyT1BatchIsSet = false;
}
double Position::getQtyT2Batch() const
{
    return m_QtyT2Batch;
}

void Position::setQtyT2Batch(double value)
{
    m_QtyT2Batch = value;
    m_QtyT2BatchIsSet = true;
}

bool Position::qtyT2BatchIsSet() const
{
    return m_QtyT2BatchIsSet;
}

void Position::unsetQtyT2Batch()
{
    m_QtyT2BatchIsSet = false;
}
double Position::getQtyTFutureBatch() const
{
    return m_QtyTFutureBatch;
}

void Position::setQtyTFutureBatch(double value)
{
    m_QtyTFutureBatch = value;
    m_QtyTFutureBatchIsSet = true;
}

bool Position::qtyTFutureBatchIsSet() const
{
    return m_QtyTFutureBatchIsSet;
}

void Position::unsetQtyTFutureBatch()
{
    m_QtyTFutureBatchIsSet = false;
}
double Position::getQtyBatch() const
{
    return m_QtyBatch;
}

void Position::setQtyBatch(double value)
{
    m_QtyBatch = value;
    m_QtyBatchIsSet = true;
}

bool Position::qtyBatchIsSet() const
{
    return m_QtyBatchIsSet;
}

void Position::unsetQtyBatch()
{
    m_QtyBatchIsSet = false;
}
double Position::getOpenQtyBatch() const
{
    return m_OpenQtyBatch;
}

void Position::setOpenQtyBatch(double value)
{
    m_OpenQtyBatch = value;
    m_OpenQtyBatchIsSet = true;
}

bool Position::openQtyBatchIsSet() const
{
    return m_OpenQtyBatchIsSet;
}

void Position::unsetOpenQtyBatch()
{
    m_OpenQtyBatchIsSet = false;
}
double Position::getQty() const
{
    return m_Qty;
}

void Position::setQty(double value)
{
    m_Qty = value;
    m_QtyIsSet = true;
}

bool Position::qtyIsSet() const
{
    return m_QtyIsSet;
}

void Position::unsetQty()
{
    m_QtyIsSet = false;
}
double Position::getOpen() const
{
    return m_Open;
}

void Position::setOpen(double value)
{
    m_Open = value;
    m_OpenIsSet = true;
}

bool Position::openIsSet() const
{
    return m_OpenIsSet;
}

void Position::unsetOpen()
{
    m_OpenIsSet = false;
}
double Position::getUnrealisedPl() const
{
    return m_UnrealisedPl;
}

void Position::setUnrealisedPl(double value)
{
    m_UnrealisedPl = value;
    m_UnrealisedPlIsSet = true;
}

bool Position::unrealisedPlIsSet() const
{
    return m_UnrealisedPlIsSet;
}

void Position::unsetUnrealisedPl()
{
    m_UnrealisedPlIsSet = false;
}
bool Position::isIsCurrency() const
{
    return m_IsCurrency;
}

void Position::setIsCurrency(bool value)
{
    m_IsCurrency = value;
    m_IsCurrencyIsSet = true;
}

bool Position::isCurrencyIsSet() const
{
    return m_IsCurrencyIsSet;
}

void Position::unsetIsCurrency()
{
    m_IsCurrencyIsSet = false;
}
}


