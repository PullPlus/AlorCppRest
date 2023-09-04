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



#include "AlorCppRest/model/RiskRate.h"

namespace alormodel {



RiskRate::RiskRate()
{
    m_Id = 0L;
    m_IdIsSet = false;
    m_Instrument = utility::conversions::to_string_t("");
    m_InstrumentIsSet = false;
    m_ExchangeIsSet = false;
    m_RiskCategoryId = 0;
    m_RiskCategoryIdIsSet = false;
    m_SecurityRiskCategoryId = 0.0;
    m_SecurityRiskCategoryIdIsSet = false;
    m_AssetType = utility::conversions::to_string_t("");
    m_AssetTypeIsSet = false;
    m_UnderlyingAsset = utility::conversions::to_string_t("");
    m_UnderlyingAssetIsSet = false;
    m_SetName = utility::conversions::to_string_t("");
    m_SetNameIsSet = false;
    m_IsDirect = false;
    m_IsDirectIsSet = false;
    m_Isin = utility::conversions::to_string_t("");
    m_IsinIsSet = false;
    m_CurrencyCode = utility::conversions::to_string_t("");
    m_CurrencyCodeIsSet = false;
    m_RateUp = 0.0;
    m_RateUpIsSet = false;
    m_RateDown = 0.0;
    m_RateDownIsSet = false;
    m_RateSymmetric = 0.0;
    m_RateSymmetricIsSet = false;
    m_IsShortSellPossible = false;
    m_IsShortSellPossibleIsSet = false;
    m_IsMarginal = false;
    m_IsMarginalIsSet = false;
    m_SetRate = 0.0;
    m_SetRateIsSet = false;
    m_CreatedAt = utility::conversions::to_string_t("");
    m_CreatedAtIsSet = false;
    m_UpdatedAt = utility::datetime();
    m_UpdatedAtIsSet = false;
}

RiskRate::~RiskRate()
{
}

void RiskRate::validate()
{
    // TODO: implement validation
}

web::json::value RiskRate::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("id"))] = ModelBase::toJson(m_Id);
    }
    if(m_InstrumentIsSet)
    {
        val[utility::conversions::to_string_t(U("instrument"))] = ModelBase::toJson(m_Instrument);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_RiskCategoryIdIsSet)
    {
        val[utility::conversions::to_string_t(U("riskCategoryId"))] = ModelBase::toJson(m_RiskCategoryId);
    }
    if(m_SecurityRiskCategoryIdIsSet)
    {
        val[utility::conversions::to_string_t(U("securityRiskCategoryId"))] = ModelBase::toJson(m_SecurityRiskCategoryId);
    }
    if(m_AssetTypeIsSet)
    {
        val[utility::conversions::to_string_t(U("assetType"))] = ModelBase::toJson(m_AssetType);
    }
    if(m_UnderlyingAssetIsSet)
    {
        val[utility::conversions::to_string_t(U("underlyingAsset"))] = ModelBase::toJson(m_UnderlyingAsset);
    }
    if(m_SetNameIsSet)
    {
        val[utility::conversions::to_string_t(U("setName"))] = ModelBase::toJson(m_SetName);
    }
    if(m_IsDirectIsSet)
    {
        val[utility::conversions::to_string_t(U("isDirect"))] = ModelBase::toJson(m_IsDirect);
    }
    if(m_IsinIsSet)
    {
        val[utility::conversions::to_string_t(U("isin"))] = ModelBase::toJson(m_Isin);
    }
    if(m_CurrencyCodeIsSet)
    {
        val[utility::conversions::to_string_t(U("currencyCode"))] = ModelBase::toJson(m_CurrencyCode);
    }
    if(m_RateUpIsSet)
    {
        val[utility::conversions::to_string_t(U("rateUp"))] = ModelBase::toJson(m_RateUp);
    }
    if(m_RateDownIsSet)
    {
        val[utility::conversions::to_string_t(U("rateDown"))] = ModelBase::toJson(m_RateDown);
    }
    if(m_RateSymmetricIsSet)
    {
        val[utility::conversions::to_string_t(U("rateSymmetric"))] = ModelBase::toJson(m_RateSymmetric);
    }
    if(m_IsShortSellPossibleIsSet)
    {
        val[utility::conversions::to_string_t(U("isShortSellPossible"))] = ModelBase::toJson(m_IsShortSellPossible);
    }
    if(m_IsMarginalIsSet)
    {
        val[utility::conversions::to_string_t(U("isMarginal"))] = ModelBase::toJson(m_IsMarginal);
    }
    if(m_SetRateIsSet)
    {
        val[utility::conversions::to_string_t(U("setRate"))] = ModelBase::toJson(m_SetRate);
    }
    if(m_CreatedAtIsSet)
    {
        val[utility::conversions::to_string_t(U("createdAt"))] = ModelBase::toJson(m_CreatedAt);
    }
    if(m_UpdatedAtIsSet)
    {
        val[utility::conversions::to_string_t(U("updatedAt"))] = ModelBase::toJson(m_UpdatedAt);
    }

    return val;
}

bool RiskRate::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("instrument"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("instrument")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setInstrument;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInstrument);
            setInstrument(refVal_setInstrument);
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
    if(val.has_field(utility::conversions::to_string_t(U("riskCategoryId"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("riskCategoryId")));
        if(!fieldValue.is_null())
        {
            int32_t refVal_setRiskCategoryId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRiskCategoryId);
            setRiskCategoryId(refVal_setRiskCategoryId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("securityRiskCategoryId"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("securityRiskCategoryId")));
        if(!fieldValue.is_null())
        {
            double refVal_setSecurityRiskCategoryId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSecurityRiskCategoryId);
            setSecurityRiskCategoryId(refVal_setSecurityRiskCategoryId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("assetType"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("assetType")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setAssetType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAssetType);
            setAssetType(refVal_setAssetType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("underlyingAsset"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("underlyingAsset")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setUnderlyingAsset;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUnderlyingAsset);
            setUnderlyingAsset(refVal_setUnderlyingAsset);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("setName"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("setName")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setSetName;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSetName);
            setSetName(refVal_setSetName);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isDirect"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isDirect")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsDirect;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsDirect);
            setIsDirect(refVal_setIsDirect);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isin"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isin")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setIsin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsin);
            setIsin(refVal_setIsin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("currencyCode"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("currencyCode")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCurrencyCode;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCurrencyCode);
            setCurrencyCode(refVal_setCurrencyCode);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("rateUp"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("rateUp")));
        if(!fieldValue.is_null())
        {
            double refVal_setRateUp;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRateUp);
            setRateUp(refVal_setRateUp);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("rateDown"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("rateDown")));
        if(!fieldValue.is_null())
        {
            double refVal_setRateDown;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRateDown);
            setRateDown(refVal_setRateDown);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("rateSymmetric"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("rateSymmetric")));
        if(!fieldValue.is_null())
        {
            double refVal_setRateSymmetric;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRateSymmetric);
            setRateSymmetric(refVal_setRateSymmetric);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isShortSellPossible"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isShortSellPossible")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsShortSellPossible;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsShortSellPossible);
            setIsShortSellPossible(refVal_setIsShortSellPossible);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isMarginal"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isMarginal")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsMarginal;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsMarginal);
            setIsMarginal(refVal_setIsMarginal);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("setRate"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("setRate")));
        if(!fieldValue.is_null())
        {
            double refVal_setSetRate;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSetRate);
            setSetRate(refVal_setSetRate);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("createdAt"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("createdAt")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setCreatedAt;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreatedAt);
            setCreatedAt(refVal_setCreatedAt);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("updatedAt"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("updatedAt")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setUpdatedAt;
            ok &= ModelBase::fromJson(fieldValue, refVal_setUpdatedAt);
            setUpdatedAt(refVal_setUpdatedAt);
        }
    }
    return ok;
}

void RiskRate::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_InstrumentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("instrument")), m_Instrument));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_RiskCategoryIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("riskCategoryId")), m_RiskCategoryId));
    }
    if(m_SecurityRiskCategoryIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("securityRiskCategoryId")), m_SecurityRiskCategoryId));
    }
    if(m_AssetTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("assetType")), m_AssetType));
    }
    if(m_UnderlyingAssetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("underlyingAsset")), m_UnderlyingAsset));
    }
    if(m_SetNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("setName")), m_SetName));
    }
    if(m_IsDirectIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isDirect")), m_IsDirect));
    }
    if(m_IsinIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isin")), m_Isin));
    }
    if(m_CurrencyCodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("currencyCode")), m_CurrencyCode));
    }
    if(m_RateUpIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("rateUp")), m_RateUp));
    }
    if(m_RateDownIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("rateDown")), m_RateDown));
    }
    if(m_RateSymmetricIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("rateSymmetric")), m_RateSymmetric));
    }
    if(m_IsShortSellPossibleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isShortSellPossible")), m_IsShortSellPossible));
    }
    if(m_IsMarginalIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isMarginal")), m_IsMarginal));
    }
    if(m_SetRateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("setRate")), m_SetRate));
    }
    if(m_CreatedAtIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("createdAt")), m_CreatedAt));
    }
    if(m_UpdatedAtIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("updatedAt")), m_UpdatedAt));
    }
}

bool RiskRate::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("instrument"))))
    {
        utility::string_t refVal_setInstrument;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("instrument"))), refVal_setInstrument );
        setInstrument(refVal_setInstrument);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exchange"))))
    {
        std::shared_ptr<Exchange> refVal_setExchange;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exchange"))), refVal_setExchange );
        setExchange(refVal_setExchange);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("riskCategoryId"))))
    {
        int32_t refVal_setRiskCategoryId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("riskCategoryId"))), refVal_setRiskCategoryId );
        setRiskCategoryId(refVal_setRiskCategoryId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("securityRiskCategoryId"))))
    {
        double refVal_setSecurityRiskCategoryId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("securityRiskCategoryId"))), refVal_setSecurityRiskCategoryId );
        setSecurityRiskCategoryId(refVal_setSecurityRiskCategoryId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("assetType"))))
    {
        utility::string_t refVal_setAssetType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("assetType"))), refVal_setAssetType );
        setAssetType(refVal_setAssetType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("underlyingAsset"))))
    {
        utility::string_t refVal_setUnderlyingAsset;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("underlyingAsset"))), refVal_setUnderlyingAsset );
        setUnderlyingAsset(refVal_setUnderlyingAsset);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("setName"))))
    {
        utility::string_t refVal_setSetName;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("setName"))), refVal_setSetName );
        setSetName(refVal_setSetName);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isDirect"))))
    {
        bool refVal_setIsDirect;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isDirect"))), refVal_setIsDirect );
        setIsDirect(refVal_setIsDirect);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isin"))))
    {
        utility::string_t refVal_setIsin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isin"))), refVal_setIsin );
        setIsin(refVal_setIsin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("currencyCode"))))
    {
        utility::string_t refVal_setCurrencyCode;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("currencyCode"))), refVal_setCurrencyCode );
        setCurrencyCode(refVal_setCurrencyCode);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("rateUp"))))
    {
        double refVal_setRateUp;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("rateUp"))), refVal_setRateUp );
        setRateUp(refVal_setRateUp);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("rateDown"))))
    {
        double refVal_setRateDown;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("rateDown"))), refVal_setRateDown );
        setRateDown(refVal_setRateDown);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("rateSymmetric"))))
    {
        double refVal_setRateSymmetric;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("rateSymmetric"))), refVal_setRateSymmetric );
        setRateSymmetric(refVal_setRateSymmetric);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isShortSellPossible"))))
    {
        bool refVal_setIsShortSellPossible;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isShortSellPossible"))), refVal_setIsShortSellPossible );
        setIsShortSellPossible(refVal_setIsShortSellPossible);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isMarginal"))))
    {
        bool refVal_setIsMarginal;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isMarginal"))), refVal_setIsMarginal );
        setIsMarginal(refVal_setIsMarginal);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("setRate"))))
    {
        double refVal_setSetRate;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("setRate"))), refVal_setSetRate );
        setSetRate(refVal_setSetRate);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("createdAt"))))
    {
        utility::string_t refVal_setCreatedAt;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("createdAt"))), refVal_setCreatedAt );
        setCreatedAt(refVal_setCreatedAt);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("updatedAt"))))
    {
        utility::datetime refVal_setUpdatedAt;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("updatedAt"))), refVal_setUpdatedAt );
        setUpdatedAt(refVal_setUpdatedAt);
    }
    return ok;
}

int64_t RiskRate::getId() const
{
    return m_Id;
}

void RiskRate::setId(int64_t value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool RiskRate::idIsSet() const
{
    return m_IdIsSet;
}

void RiskRate::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t RiskRate::getInstrument() const
{
    return m_Instrument;
}

void RiskRate::setInstrument(const utility::string_t& value)
{
    m_Instrument = value;
    m_InstrumentIsSet = true;
}

bool RiskRate::instrumentIsSet() const
{
    return m_InstrumentIsSet;
}

void RiskRate::unsetInstrument()
{
    m_InstrumentIsSet = false;
}
std::shared_ptr<Exchange> RiskRate::getExchange() const
{
    return m_Exchange;
}

void RiskRate::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool RiskRate::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void RiskRate::unsetExchange()
{
    m_ExchangeIsSet = false;
}
int32_t RiskRate::getRiskCategoryId() const
{
    return m_RiskCategoryId;
}

void RiskRate::setRiskCategoryId(int32_t value)
{
    m_RiskCategoryId = value;
    m_RiskCategoryIdIsSet = true;
}

bool RiskRate::riskCategoryIdIsSet() const
{
    return m_RiskCategoryIdIsSet;
}

void RiskRate::unsetRiskCategoryId()
{
    m_RiskCategoryIdIsSet = false;
}
double RiskRate::getSecurityRiskCategoryId() const
{
    return m_SecurityRiskCategoryId;
}

void RiskRate::setSecurityRiskCategoryId(double value)
{
    m_SecurityRiskCategoryId = value;
    m_SecurityRiskCategoryIdIsSet = true;
}

bool RiskRate::securityRiskCategoryIdIsSet() const
{
    return m_SecurityRiskCategoryIdIsSet;
}

void RiskRate::unsetSecurityRiskCategoryId()
{
    m_SecurityRiskCategoryIdIsSet = false;
}
utility::string_t RiskRate::getAssetType() const
{
    return m_AssetType;
}

void RiskRate::setAssetType(const utility::string_t& value)
{
    m_AssetType = value;
    m_AssetTypeIsSet = true;
}

bool RiskRate::assetTypeIsSet() const
{
    return m_AssetTypeIsSet;
}

void RiskRate::unsetAssetType()
{
    m_AssetTypeIsSet = false;
}
utility::string_t RiskRate::getUnderlyingAsset() const
{
    return m_UnderlyingAsset;
}

void RiskRate::setUnderlyingAsset(const utility::string_t& value)
{
    m_UnderlyingAsset = value;
    m_UnderlyingAssetIsSet = true;
}

bool RiskRate::underlyingAssetIsSet() const
{
    return m_UnderlyingAssetIsSet;
}

void RiskRate::unsetUnderlyingAsset()
{
    m_UnderlyingAssetIsSet = false;
}
utility::string_t RiskRate::getSetName() const
{
    return m_SetName;
}

void RiskRate::setSetName(const utility::string_t& value)
{
    m_SetName = value;
    m_SetNameIsSet = true;
}

bool RiskRate::setNameIsSet() const
{
    return m_SetNameIsSet;
}

void RiskRate::unsetSetName()
{
    m_SetNameIsSet = false;
}
bool RiskRate::isIsDirect() const
{
    return m_IsDirect;
}

void RiskRate::setIsDirect(bool value)
{
    m_IsDirect = value;
    m_IsDirectIsSet = true;
}

bool RiskRate::isDirectIsSet() const
{
    return m_IsDirectIsSet;
}

void RiskRate::unsetIsDirect()
{
    m_IsDirectIsSet = false;
}
utility::string_t RiskRate::getIsin() const
{
    return m_Isin;
}

void RiskRate::setIsin(const utility::string_t& value)
{
    m_Isin = value;
    m_IsinIsSet = true;
}

bool RiskRate::isinIsSet() const
{
    return m_IsinIsSet;
}

void RiskRate::unsetIsin()
{
    m_IsinIsSet = false;
}
utility::string_t RiskRate::getCurrencyCode() const
{
    return m_CurrencyCode;
}

void RiskRate::setCurrencyCode(const utility::string_t& value)
{
    m_CurrencyCode = value;
    m_CurrencyCodeIsSet = true;
}

bool RiskRate::currencyCodeIsSet() const
{
    return m_CurrencyCodeIsSet;
}

void RiskRate::unsetCurrencyCode()
{
    m_CurrencyCodeIsSet = false;
}
double RiskRate::getRateUp() const
{
    return m_RateUp;
}

void RiskRate::setRateUp(double value)
{
    m_RateUp = value;
    m_RateUpIsSet = true;
}

bool RiskRate::rateUpIsSet() const
{
    return m_RateUpIsSet;
}

void RiskRate::unsetRateUp()
{
    m_RateUpIsSet = false;
}
double RiskRate::getRateDown() const
{
    return m_RateDown;
}

void RiskRate::setRateDown(double value)
{
    m_RateDown = value;
    m_RateDownIsSet = true;
}

bool RiskRate::rateDownIsSet() const
{
    return m_RateDownIsSet;
}

void RiskRate::unsetRateDown()
{
    m_RateDownIsSet = false;
}
double RiskRate::getRateSymmetric() const
{
    return m_RateSymmetric;
}

void RiskRate::setRateSymmetric(double value)
{
    m_RateSymmetric = value;
    m_RateSymmetricIsSet = true;
}

bool RiskRate::rateSymmetricIsSet() const
{
    return m_RateSymmetricIsSet;
}

void RiskRate::unsetRateSymmetric()
{
    m_RateSymmetricIsSet = false;
}
bool RiskRate::isIsShortSellPossible() const
{
    return m_IsShortSellPossible;
}

void RiskRate::setIsShortSellPossible(bool value)
{
    m_IsShortSellPossible = value;
    m_IsShortSellPossibleIsSet = true;
}

bool RiskRate::isShortSellPossibleIsSet() const
{
    return m_IsShortSellPossibleIsSet;
}

void RiskRate::unsetIsShortSellPossible()
{
    m_IsShortSellPossibleIsSet = false;
}
bool RiskRate::isIsMarginal() const
{
    return m_IsMarginal;
}

void RiskRate::setIsMarginal(bool value)
{
    m_IsMarginal = value;
    m_IsMarginalIsSet = true;
}

bool RiskRate::isMarginalIsSet() const
{
    return m_IsMarginalIsSet;
}

void RiskRate::unsetIsMarginal()
{
    m_IsMarginalIsSet = false;
}
double RiskRate::getSetRate() const
{
    return m_SetRate;
}

void RiskRate::setSetRate(double value)
{
    m_SetRate = value;
    m_SetRateIsSet = true;
}

bool RiskRate::setRateIsSet() const
{
    return m_SetRateIsSet;
}

void RiskRate::unsetSetRate()
{
    m_SetRateIsSet = false;
}
utility::string_t RiskRate::getCreatedAt() const
{
    return m_CreatedAt;
}

void RiskRate::setCreatedAt(const utility::string_t& value)
{
    m_CreatedAt = value;
    m_CreatedAtIsSet = true;
}

bool RiskRate::createdAtIsSet() const
{
    return m_CreatedAtIsSet;
}

void RiskRate::unsetCreatedAt()
{
    m_CreatedAtIsSet = false;
}
utility::datetime RiskRate::getUpdatedAt() const
{
    return m_UpdatedAt;
}

void RiskRate::setUpdatedAt(const utility::datetime& value)
{
    m_UpdatedAt = value;
    m_UpdatedAtIsSet = true;
}

bool RiskRate::updatedAtIsSet() const
{
    return m_UpdatedAtIsSet;
}

void RiskRate::unsetUpdatedAt()
{
    m_UpdatedAtIsSet = false;
}
}


