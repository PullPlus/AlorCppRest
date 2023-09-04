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



#include "AlorCppRest/model/Risk.h"

namespace alormodel {



Risk::Risk()
{
    m_Portfolio = utility::conversions::to_string_t("");
    m_PortfolioIsSet = false;
    m_ExchangeIsSet = false;
    m_PortfolioEvaluation = 0.0;
    m_PortfolioEvaluationIsSet = false;
    m_PortfolioLiquidationValue = 0.0;
    m_PortfolioLiquidationValueIsSet = false;
    m_InitialMargin = 0.0;
    m_InitialMarginIsSet = false;
    m_MinimalMargin = 0.0;
    m_MinimalMarginIsSet = false;
    m_CorrectedMargin = 0.0;
    m_CorrectedMarginIsSet = false;
    m_RiskCoverageRatioOne = 0.0;
    m_RiskCoverageRatioOneIsSet = false;
    m_RiskCoverageRatioTwo = 0.0;
    m_RiskCoverageRatioTwoIsSet = false;
    m_RiskCategoryId = 0;
    m_RiskCategoryIdIsSet = false;
    m_ClientTypeIsSet = false;
    m_HasForbiddenPositions = false;
    m_HasForbiddenPositionsIsSet = false;
    m_HasNegativeQuantity = false;
    m_HasNegativeQuantityIsSet = false;
}

Risk::~Risk()
{
}

void Risk::validate()
{
    // TODO: implement validation
}

web::json::value Risk::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_PortfolioIsSet)
    {
        val[utility::conversions::to_string_t(U("portfolio"))] = ModelBase::toJson(m_Portfolio);
    }
    if(m_ExchangeIsSet)
    {
        val[utility::conversions::to_string_t(U("exchange"))] = ModelBase::toJson(m_Exchange);
    }
    if(m_PortfolioEvaluationIsSet)
    {
        val[utility::conversions::to_string_t(U("portfolioEvaluation"))] = ModelBase::toJson(m_PortfolioEvaluation);
    }
    if(m_PortfolioLiquidationValueIsSet)
    {
        val[utility::conversions::to_string_t(U("portfolioLiquidationValue"))] = ModelBase::toJson(m_PortfolioLiquidationValue);
    }
    if(m_InitialMarginIsSet)
    {
        val[utility::conversions::to_string_t(U("initialMargin"))] = ModelBase::toJson(m_InitialMargin);
    }
    if(m_MinimalMarginIsSet)
    {
        val[utility::conversions::to_string_t(U("minimalMargin"))] = ModelBase::toJson(m_MinimalMargin);
    }
    if(m_CorrectedMarginIsSet)
    {
        val[utility::conversions::to_string_t(U("correctedMargin"))] = ModelBase::toJson(m_CorrectedMargin);
    }
    if(m_RiskCoverageRatioOneIsSet)
    {
        val[utility::conversions::to_string_t(U("riskCoverageRatioOne"))] = ModelBase::toJson(m_RiskCoverageRatioOne);
    }
    if(m_RiskCoverageRatioTwoIsSet)
    {
        val[utility::conversions::to_string_t(U("riskCoverageRatioTwo"))] = ModelBase::toJson(m_RiskCoverageRatioTwo);
    }
    if(m_RiskCategoryIdIsSet)
    {
        val[utility::conversions::to_string_t(U("riskCategoryId"))] = ModelBase::toJson(m_RiskCategoryId);
    }
    if(m_ClientTypeIsSet)
    {
        val[utility::conversions::to_string_t(U("clientType"))] = ModelBase::toJson(m_ClientType);
    }
    if(m_HasForbiddenPositionsIsSet)
    {
        val[utility::conversions::to_string_t(U("hasForbiddenPositions"))] = ModelBase::toJson(m_HasForbiddenPositions);
    }
    if(m_HasNegativeQuantityIsSet)
    {
        val[utility::conversions::to_string_t(U("hasNegativeQuantity"))] = ModelBase::toJson(m_HasNegativeQuantity);
    }

    return val;
}

bool Risk::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("portfolio"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("portfolio")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setPortfolio;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPortfolio);
            setPortfolio(refVal_setPortfolio);
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
    if(val.has_field(utility::conversions::to_string_t(U("portfolioEvaluation"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("portfolioEvaluation")));
        if(!fieldValue.is_null())
        {
            double refVal_setPortfolioEvaluation;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPortfolioEvaluation);
            setPortfolioEvaluation(refVal_setPortfolioEvaluation);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("portfolioLiquidationValue"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("portfolioLiquidationValue")));
        if(!fieldValue.is_null())
        {
            double refVal_setPortfolioLiquidationValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setPortfolioLiquidationValue);
            setPortfolioLiquidationValue(refVal_setPortfolioLiquidationValue);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("initialMargin"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("initialMargin")));
        if(!fieldValue.is_null())
        {
            double refVal_setInitialMargin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setInitialMargin);
            setInitialMargin(refVal_setInitialMargin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("minimalMargin"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("minimalMargin")));
        if(!fieldValue.is_null())
        {
            double refVal_setMinimalMargin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMinimalMargin);
            setMinimalMargin(refVal_setMinimalMargin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("correctedMargin"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("correctedMargin")));
        if(!fieldValue.is_null())
        {
            double refVal_setCorrectedMargin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCorrectedMargin);
            setCorrectedMargin(refVal_setCorrectedMargin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("riskCoverageRatioOne"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("riskCoverageRatioOne")));
        if(!fieldValue.is_null())
        {
            double refVal_setRiskCoverageRatioOne;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRiskCoverageRatioOne);
            setRiskCoverageRatioOne(refVal_setRiskCoverageRatioOne);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("riskCoverageRatioTwo"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("riskCoverageRatioTwo")));
        if(!fieldValue.is_null())
        {
            double refVal_setRiskCoverageRatioTwo;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRiskCoverageRatioTwo);
            setRiskCoverageRatioTwo(refVal_setRiskCoverageRatioTwo);
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
    if(val.has_field(utility::conversions::to_string_t(U("clientType"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("clientType")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ClientType> refVal_setClientType;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClientType);
            setClientType(refVal_setClientType);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("hasForbiddenPositions"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("hasForbiddenPositions")));
        if(!fieldValue.is_null())
        {
            bool refVal_setHasForbiddenPositions;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHasForbiddenPositions);
            setHasForbiddenPositions(refVal_setHasForbiddenPositions);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("hasNegativeQuantity"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("hasNegativeQuantity")));
        if(!fieldValue.is_null())
        {
            bool refVal_setHasNegativeQuantity;
            ok &= ModelBase::fromJson(fieldValue, refVal_setHasNegativeQuantity);
            setHasNegativeQuantity(refVal_setHasNegativeQuantity);
        }
    }
    return ok;
}

void Risk::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_PortfolioIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("portfolio")), m_Portfolio));
    }
    if(m_ExchangeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("exchange")), m_Exchange));
    }
    if(m_PortfolioEvaluationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("portfolioEvaluation")), m_PortfolioEvaluation));
    }
    if(m_PortfolioLiquidationValueIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("portfolioLiquidationValue")), m_PortfolioLiquidationValue));
    }
    if(m_InitialMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("initialMargin")), m_InitialMargin));
    }
    if(m_MinimalMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("minimalMargin")), m_MinimalMargin));
    }
    if(m_CorrectedMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("correctedMargin")), m_CorrectedMargin));
    }
    if(m_RiskCoverageRatioOneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("riskCoverageRatioOne")), m_RiskCoverageRatioOne));
    }
    if(m_RiskCoverageRatioTwoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("riskCoverageRatioTwo")), m_RiskCoverageRatioTwo));
    }
    if(m_RiskCategoryIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("riskCategoryId")), m_RiskCategoryId));
    }
    if(m_ClientTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("clientType")), m_ClientType));
    }
    if(m_HasForbiddenPositionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("hasForbiddenPositions")), m_HasForbiddenPositions));
    }
    if(m_HasNegativeQuantityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("hasNegativeQuantity")), m_HasNegativeQuantity));
    }
}

bool Risk::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("portfolio"))))
    {
        utility::string_t refVal_setPortfolio;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("portfolio"))), refVal_setPortfolio );
        setPortfolio(refVal_setPortfolio);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("exchange"))))
    {
        std::shared_ptr<Exchange> refVal_setExchange;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("exchange"))), refVal_setExchange );
        setExchange(refVal_setExchange);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("portfolioEvaluation"))))
    {
        double refVal_setPortfolioEvaluation;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("portfolioEvaluation"))), refVal_setPortfolioEvaluation );
        setPortfolioEvaluation(refVal_setPortfolioEvaluation);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("portfolioLiquidationValue"))))
    {
        double refVal_setPortfolioLiquidationValue;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("portfolioLiquidationValue"))), refVal_setPortfolioLiquidationValue );
        setPortfolioLiquidationValue(refVal_setPortfolioLiquidationValue);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("initialMargin"))))
    {
        double refVal_setInitialMargin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("initialMargin"))), refVal_setInitialMargin );
        setInitialMargin(refVal_setInitialMargin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("minimalMargin"))))
    {
        double refVal_setMinimalMargin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("minimalMargin"))), refVal_setMinimalMargin );
        setMinimalMargin(refVal_setMinimalMargin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("correctedMargin"))))
    {
        double refVal_setCorrectedMargin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("correctedMargin"))), refVal_setCorrectedMargin );
        setCorrectedMargin(refVal_setCorrectedMargin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("riskCoverageRatioOne"))))
    {
        double refVal_setRiskCoverageRatioOne;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("riskCoverageRatioOne"))), refVal_setRiskCoverageRatioOne );
        setRiskCoverageRatioOne(refVal_setRiskCoverageRatioOne);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("riskCoverageRatioTwo"))))
    {
        double refVal_setRiskCoverageRatioTwo;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("riskCoverageRatioTwo"))), refVal_setRiskCoverageRatioTwo );
        setRiskCoverageRatioTwo(refVal_setRiskCoverageRatioTwo);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("riskCategoryId"))))
    {
        int32_t refVal_setRiskCategoryId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("riskCategoryId"))), refVal_setRiskCategoryId );
        setRiskCategoryId(refVal_setRiskCategoryId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("clientType"))))
    {
        std::shared_ptr<ClientType> refVal_setClientType;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("clientType"))), refVal_setClientType );
        setClientType(refVal_setClientType);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("hasForbiddenPositions"))))
    {
        bool refVal_setHasForbiddenPositions;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("hasForbiddenPositions"))), refVal_setHasForbiddenPositions );
        setHasForbiddenPositions(refVal_setHasForbiddenPositions);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("hasNegativeQuantity"))))
    {
        bool refVal_setHasNegativeQuantity;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("hasNegativeQuantity"))), refVal_setHasNegativeQuantity );
        setHasNegativeQuantity(refVal_setHasNegativeQuantity);
    }
    return ok;
}

utility::string_t Risk::getPortfolio() const
{
    return m_Portfolio;
}

void Risk::setPortfolio(const utility::string_t& value)
{
    m_Portfolio = value;
    m_PortfolioIsSet = true;
}

bool Risk::portfolioIsSet() const
{
    return m_PortfolioIsSet;
}

void Risk::unsetPortfolio()
{
    m_PortfolioIsSet = false;
}
std::shared_ptr<Exchange> Risk::getExchange() const
{
    return m_Exchange;
}

void Risk::setExchange(const std::shared_ptr<Exchange>& value)
{
    m_Exchange = value;
    m_ExchangeIsSet = true;
}

bool Risk::exchangeIsSet() const
{
    return m_ExchangeIsSet;
}

void Risk::unsetExchange()
{
    m_ExchangeIsSet = false;
}
double Risk::getPortfolioEvaluation() const
{
    return m_PortfolioEvaluation;
}

void Risk::setPortfolioEvaluation(double value)
{
    m_PortfolioEvaluation = value;
    m_PortfolioEvaluationIsSet = true;
}

bool Risk::portfolioEvaluationIsSet() const
{
    return m_PortfolioEvaluationIsSet;
}

void Risk::unsetPortfolioEvaluation()
{
    m_PortfolioEvaluationIsSet = false;
}
double Risk::getPortfolioLiquidationValue() const
{
    return m_PortfolioLiquidationValue;
}

void Risk::setPortfolioLiquidationValue(double value)
{
    m_PortfolioLiquidationValue = value;
    m_PortfolioLiquidationValueIsSet = true;
}

bool Risk::portfolioLiquidationValueIsSet() const
{
    return m_PortfolioLiquidationValueIsSet;
}

void Risk::unsetPortfolioLiquidationValue()
{
    m_PortfolioLiquidationValueIsSet = false;
}
double Risk::getInitialMargin() const
{
    return m_InitialMargin;
}

void Risk::setInitialMargin(double value)
{
    m_InitialMargin = value;
    m_InitialMarginIsSet = true;
}

bool Risk::initialMarginIsSet() const
{
    return m_InitialMarginIsSet;
}

void Risk::unsetInitialMargin()
{
    m_InitialMarginIsSet = false;
}
double Risk::getMinimalMargin() const
{
    return m_MinimalMargin;
}

void Risk::setMinimalMargin(double value)
{
    m_MinimalMargin = value;
    m_MinimalMarginIsSet = true;
}

bool Risk::minimalMarginIsSet() const
{
    return m_MinimalMarginIsSet;
}

void Risk::unsetMinimalMargin()
{
    m_MinimalMarginIsSet = false;
}
double Risk::getCorrectedMargin() const
{
    return m_CorrectedMargin;
}

void Risk::setCorrectedMargin(double value)
{
    m_CorrectedMargin = value;
    m_CorrectedMarginIsSet = true;
}

bool Risk::correctedMarginIsSet() const
{
    return m_CorrectedMarginIsSet;
}

void Risk::unsetCorrectedMargin()
{
    m_CorrectedMarginIsSet = false;
}
double Risk::getRiskCoverageRatioOne() const
{
    return m_RiskCoverageRatioOne;
}

void Risk::setRiskCoverageRatioOne(double value)
{
    m_RiskCoverageRatioOne = value;
    m_RiskCoverageRatioOneIsSet = true;
}

bool Risk::riskCoverageRatioOneIsSet() const
{
    return m_RiskCoverageRatioOneIsSet;
}

void Risk::unsetRiskCoverageRatioOne()
{
    m_RiskCoverageRatioOneIsSet = false;
}
double Risk::getRiskCoverageRatioTwo() const
{
    return m_RiskCoverageRatioTwo;
}

void Risk::setRiskCoverageRatioTwo(double value)
{
    m_RiskCoverageRatioTwo = value;
    m_RiskCoverageRatioTwoIsSet = true;
}

bool Risk::riskCoverageRatioTwoIsSet() const
{
    return m_RiskCoverageRatioTwoIsSet;
}

void Risk::unsetRiskCoverageRatioTwo()
{
    m_RiskCoverageRatioTwoIsSet = false;
}
int32_t Risk::getRiskCategoryId() const
{
    return m_RiskCategoryId;
}

void Risk::setRiskCategoryId(int32_t value)
{
    m_RiskCategoryId = value;
    m_RiskCategoryIdIsSet = true;
}

bool Risk::riskCategoryIdIsSet() const
{
    return m_RiskCategoryIdIsSet;
}

void Risk::unsetRiskCategoryId()
{
    m_RiskCategoryIdIsSet = false;
}
std::shared_ptr<ClientType> Risk::getClientType() const
{
    return m_ClientType;
}

void Risk::setClientType(const std::shared_ptr<ClientType>& value)
{
    m_ClientType = value;
    m_ClientTypeIsSet = true;
}

bool Risk::clientTypeIsSet() const
{
    return m_ClientTypeIsSet;
}

void Risk::unsetClientType()
{
    m_ClientTypeIsSet = false;
}
bool Risk::isHasForbiddenPositions() const
{
    return m_HasForbiddenPositions;
}

void Risk::setHasForbiddenPositions(bool value)
{
    m_HasForbiddenPositions = value;
    m_HasForbiddenPositionsIsSet = true;
}

bool Risk::hasForbiddenPositionsIsSet() const
{
    return m_HasForbiddenPositionsIsSet;
}

void Risk::unsetHasForbiddenPositions()
{
    m_HasForbiddenPositionsIsSet = false;
}
bool Risk::isHasNegativeQuantity() const
{
    return m_HasNegativeQuantity;
}

void Risk::setHasNegativeQuantity(bool value)
{
    m_HasNegativeQuantity = value;
    m_HasNegativeQuantityIsSet = true;
}

bool Risk::hasNegativeQuantityIsSet() const
{
    return m_HasNegativeQuantityIsSet;
}

void Risk::unsetHasNegativeQuantity()
{
    m_HasNegativeQuantityIsSet = false;
}
}

