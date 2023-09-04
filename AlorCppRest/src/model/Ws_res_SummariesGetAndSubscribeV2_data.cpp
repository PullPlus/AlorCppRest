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



#include "AlorCppRest/model/Ws_res_SummariesGetAndSubscribeV2_data.h"

namespace alormodel {



Ws_res_SummariesGetAndSubscribeV2_data::Ws_res_SummariesGetAndSubscribeV2_data()
{
    m_BuyingPowerAtMorning = 0.0;
    m_BuyingPowerAtMorningIsSet = false;
    m_BuyingPower = 0.0;
    m_BuyingPowerIsSet = false;
    m_Profit = 0.0;
    m_ProfitIsSet = false;
    m_ProfitRate = 0.0;
    m_ProfitRateIsSet = false;
    m_PortfolioEvaluation = 0.0;
    m_PortfolioEvaluationIsSet = false;
    m_PortfolioLiquidationValue = 0.0;
    m_PortfolioLiquidationValueIsSet = false;
    m_InitialMargin = 0.0;
    m_InitialMarginIsSet = false;
    m_RiskBeforeForcePositionClosing = 0.0;
    m_RiskBeforeForcePositionClosingIsSet = false;
    m_Commission = 0.0;
    m_CommissionIsSet = false;
}

Ws_res_SummariesGetAndSubscribeV2_data::~Ws_res_SummariesGetAndSubscribeV2_data()
{
}

void Ws_res_SummariesGetAndSubscribeV2_data::validate()
{
    // TODO: implement validation
}

web::json::value Ws_res_SummariesGetAndSubscribeV2_data::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_BuyingPowerAtMorningIsSet)
    {
        val[utility::conversions::to_string_t(U("buyingPowerAtMorning"))] = ModelBase::toJson(m_BuyingPowerAtMorning);
    }
    if(m_BuyingPowerIsSet)
    {
        val[utility::conversions::to_string_t(U("buyingPower"))] = ModelBase::toJson(m_BuyingPower);
    }
    if(m_ProfitIsSet)
    {
        val[utility::conversions::to_string_t(U("profit"))] = ModelBase::toJson(m_Profit);
    }
    if(m_ProfitRateIsSet)
    {
        val[utility::conversions::to_string_t(U("profitRate"))] = ModelBase::toJson(m_ProfitRate);
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
    if(m_RiskBeforeForcePositionClosingIsSet)
    {
        val[utility::conversions::to_string_t(U("riskBeforeForcePositionClosing"))] = ModelBase::toJson(m_RiskBeforeForcePositionClosing);
    }
    if(m_CommissionIsSet)
    {
        val[utility::conversions::to_string_t(U("commission"))] = ModelBase::toJson(m_Commission);
    }

    return val;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("buyingPowerAtMorning"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("buyingPowerAtMorning")));
        if(!fieldValue.is_null())
        {
            double refVal_setBuyingPowerAtMorning;
            ok &= ModelBase::fromJson(fieldValue, refVal_setBuyingPowerAtMorning);
            setBuyingPowerAtMorning(refVal_setBuyingPowerAtMorning);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("buyingPower"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("buyingPower")));
        if(!fieldValue.is_null())
        {
            double refVal_setBuyingPower;
            ok &= ModelBase::fromJson(fieldValue, refVal_setBuyingPower);
            setBuyingPower(refVal_setBuyingPower);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("profit"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("profit")));
        if(!fieldValue.is_null())
        {
            double refVal_setProfit;
            ok &= ModelBase::fromJson(fieldValue, refVal_setProfit);
            setProfit(refVal_setProfit);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("profitRate"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("profitRate")));
        if(!fieldValue.is_null())
        {
            double refVal_setProfitRate;
            ok &= ModelBase::fromJson(fieldValue, refVal_setProfitRate);
            setProfitRate(refVal_setProfitRate);
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
    if(val.has_field(utility::conversions::to_string_t(U("riskBeforeForcePositionClosing"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("riskBeforeForcePositionClosing")));
        if(!fieldValue.is_null())
        {
            double refVal_setRiskBeforeForcePositionClosing;
            ok &= ModelBase::fromJson(fieldValue, refVal_setRiskBeforeForcePositionClosing);
            setRiskBeforeForcePositionClosing(refVal_setRiskBeforeForcePositionClosing);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("commission"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("commission")));
        if(!fieldValue.is_null())
        {
            double refVal_setCommission;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCommission);
            setCommission(refVal_setCommission);
        }
    }
    return ok;
}

void Ws_res_SummariesGetAndSubscribeV2_data::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_BuyingPowerAtMorningIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("buyingPowerAtMorning")), m_BuyingPowerAtMorning));
    }
    if(m_BuyingPowerIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("buyingPower")), m_BuyingPower));
    }
    if(m_ProfitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("profit")), m_Profit));
    }
    if(m_ProfitRateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("profitRate")), m_ProfitRate));
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
    if(m_RiskBeforeForcePositionClosingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("riskBeforeForcePositionClosing")), m_RiskBeforeForcePositionClosing));
    }
    if(m_CommissionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("commission")), m_Commission));
    }
}

bool Ws_res_SummariesGetAndSubscribeV2_data::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("buyingPowerAtMorning"))))
    {
        double refVal_setBuyingPowerAtMorning;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("buyingPowerAtMorning"))), refVal_setBuyingPowerAtMorning );
        setBuyingPowerAtMorning(refVal_setBuyingPowerAtMorning);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("buyingPower"))))
    {
        double refVal_setBuyingPower;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("buyingPower"))), refVal_setBuyingPower );
        setBuyingPower(refVal_setBuyingPower);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("profit"))))
    {
        double refVal_setProfit;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("profit"))), refVal_setProfit );
        setProfit(refVal_setProfit);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("profitRate"))))
    {
        double refVal_setProfitRate;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("profitRate"))), refVal_setProfitRate );
        setProfitRate(refVal_setProfitRate);
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("riskBeforeForcePositionClosing"))))
    {
        double refVal_setRiskBeforeForcePositionClosing;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("riskBeforeForcePositionClosing"))), refVal_setRiskBeforeForcePositionClosing );
        setRiskBeforeForcePositionClosing(refVal_setRiskBeforeForcePositionClosing);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("commission"))))
    {
        double refVal_setCommission;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("commission"))), refVal_setCommission );
        setCommission(refVal_setCommission);
    }
    return ok;
}

double Ws_res_SummariesGetAndSubscribeV2_data::getBuyingPowerAtMorning() const
{
    return m_BuyingPowerAtMorning;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setBuyingPowerAtMorning(double value)
{
    m_BuyingPowerAtMorning = value;
    m_BuyingPowerAtMorningIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::buyingPowerAtMorningIsSet() const
{
    return m_BuyingPowerAtMorningIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetBuyingPowerAtMorning()
{
    m_BuyingPowerAtMorningIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getBuyingPower() const
{
    return m_BuyingPower;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setBuyingPower(double value)
{
    m_BuyingPower = value;
    m_BuyingPowerIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::buyingPowerIsSet() const
{
    return m_BuyingPowerIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetBuyingPower()
{
    m_BuyingPowerIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getProfit() const
{
    return m_Profit;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setProfit(double value)
{
    m_Profit = value;
    m_ProfitIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::profitIsSet() const
{
    return m_ProfitIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetProfit()
{
    m_ProfitIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getProfitRate() const
{
    return m_ProfitRate;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setProfitRate(double value)
{
    m_ProfitRate = value;
    m_ProfitRateIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::profitRateIsSet() const
{
    return m_ProfitRateIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetProfitRate()
{
    m_ProfitRateIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getPortfolioEvaluation() const
{
    return m_PortfolioEvaluation;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setPortfolioEvaluation(double value)
{
    m_PortfolioEvaluation = value;
    m_PortfolioEvaluationIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::portfolioEvaluationIsSet() const
{
    return m_PortfolioEvaluationIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetPortfolioEvaluation()
{
    m_PortfolioEvaluationIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getPortfolioLiquidationValue() const
{
    return m_PortfolioLiquidationValue;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setPortfolioLiquidationValue(double value)
{
    m_PortfolioLiquidationValue = value;
    m_PortfolioLiquidationValueIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::portfolioLiquidationValueIsSet() const
{
    return m_PortfolioLiquidationValueIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetPortfolioLiquidationValue()
{
    m_PortfolioLiquidationValueIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getInitialMargin() const
{
    return m_InitialMargin;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setInitialMargin(double value)
{
    m_InitialMargin = value;
    m_InitialMarginIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::initialMarginIsSet() const
{
    return m_InitialMarginIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetInitialMargin()
{
    m_InitialMarginIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getRiskBeforeForcePositionClosing() const
{
    return m_RiskBeforeForcePositionClosing;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setRiskBeforeForcePositionClosing(double value)
{
    m_RiskBeforeForcePositionClosing = value;
    m_RiskBeforeForcePositionClosingIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::riskBeforeForcePositionClosingIsSet() const
{
    return m_RiskBeforeForcePositionClosingIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetRiskBeforeForcePositionClosing()
{
    m_RiskBeforeForcePositionClosingIsSet = false;
}
double Ws_res_SummariesGetAndSubscribeV2_data::getCommission() const
{
    return m_Commission;
}

void Ws_res_SummariesGetAndSubscribeV2_data::setCommission(double value)
{
    m_Commission = value;
    m_CommissionIsSet = true;
}

bool Ws_res_SummariesGetAndSubscribeV2_data::commissionIsSet() const
{
    return m_CommissionIsSet;
}

void Ws_res_SummariesGetAndSubscribeV2_data::unsetCommission()
{
    m_CommissionIsSet = false;
}
}


