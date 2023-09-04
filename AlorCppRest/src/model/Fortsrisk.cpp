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



#include "AlorCppRest/model/Fortsrisk.h"

namespace alormodel {



Fortsrisk::Fortsrisk()
{
    m_Portfolio = utility::conversions::to_string_t("");
    m_PortfolioIsSet = false;
    m_MoneyFree = 0.0;
    m_MoneyFreeIsSet = false;
    m_MoneyBlocked = 0.0;
    m_MoneyBlockedIsSet = false;
    m_BalanceMoney = 0.0;
    m_BalanceMoneyIsSet = false;
    m_Fee = 0.0;
    m_FeeIsSet = false;
    m_MoneyOld = 0.0;
    m_MoneyOldIsSet = false;
    m_MoneyAmount = 0.0;
    m_MoneyAmountIsSet = false;
    m_MoneyPledgeAmount = 0.0;
    m_MoneyPledgeAmountIsSet = false;
    m_VmInterCl = 0.0;
    m_VmInterClIsSet = false;
    m_VmCurrentPositions = 0.0;
    m_VmCurrentPositionsIsSet = false;
    m_VarMargin = 0.0;
    m_VarMarginIsSet = false;
    m_IsLimitsSet = false;
    m_IsLimitsSetIsSet = false;
}

Fortsrisk::~Fortsrisk()
{
}

void Fortsrisk::validate()
{
    // TODO: implement validation
}

web::json::value Fortsrisk::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_PortfolioIsSet)
    {
        val[utility::conversions::to_string_t(U("portfolio"))] = ModelBase::toJson(m_Portfolio);
    }
    if(m_MoneyFreeIsSet)
    {
        val[utility::conversions::to_string_t(U("moneyFree"))] = ModelBase::toJson(m_MoneyFree);
    }
    if(m_MoneyBlockedIsSet)
    {
        val[utility::conversions::to_string_t(U("moneyBlocked"))] = ModelBase::toJson(m_MoneyBlocked);
    }
    if(m_BalanceMoneyIsSet)
    {
        val[utility::conversions::to_string_t(U("balanceMoney"))] = ModelBase::toJson(m_BalanceMoney);
    }
    if(m_FeeIsSet)
    {
        val[utility::conversions::to_string_t(U("fee"))] = ModelBase::toJson(m_Fee);
    }
    if(m_MoneyOldIsSet)
    {
        val[utility::conversions::to_string_t(U("moneyOld"))] = ModelBase::toJson(m_MoneyOld);
    }
    if(m_MoneyAmountIsSet)
    {
        val[utility::conversions::to_string_t(U("moneyAmount"))] = ModelBase::toJson(m_MoneyAmount);
    }
    if(m_MoneyPledgeAmountIsSet)
    {
        val[utility::conversions::to_string_t(U("moneyPledgeAmount"))] = ModelBase::toJson(m_MoneyPledgeAmount);
    }
    if(m_VmInterClIsSet)
    {
        val[utility::conversions::to_string_t(U("vmInterCl"))] = ModelBase::toJson(m_VmInterCl);
    }
    if(m_VmCurrentPositionsIsSet)
    {
        val[utility::conversions::to_string_t(U("vmCurrentPositions"))] = ModelBase::toJson(m_VmCurrentPositions);
    }
    if(m_VarMarginIsSet)
    {
        val[utility::conversions::to_string_t(U("varMargin"))] = ModelBase::toJson(m_VarMargin);
    }
    if(m_IsLimitsSetIsSet)
    {
        val[utility::conversions::to_string_t(U("isLimitsSet"))] = ModelBase::toJson(m_IsLimitsSet);
    }

    return val;
}

bool Fortsrisk::fromJson(const web::json::value& val)
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
    if(val.has_field(utility::conversions::to_string_t(U("moneyFree"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("moneyFree")));
        if(!fieldValue.is_null())
        {
            double refVal_setMoneyFree;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMoneyFree);
            setMoneyFree(refVal_setMoneyFree);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("moneyBlocked"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("moneyBlocked")));
        if(!fieldValue.is_null())
        {
            double refVal_setMoneyBlocked;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMoneyBlocked);
            setMoneyBlocked(refVal_setMoneyBlocked);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("balanceMoney"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("balanceMoney")));
        if(!fieldValue.is_null())
        {
            double refVal_setBalanceMoney;
            ok &= ModelBase::fromJson(fieldValue, refVal_setBalanceMoney);
            setBalanceMoney(refVal_setBalanceMoney);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("fee"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("fee")));
        if(!fieldValue.is_null())
        {
            double refVal_setFee;
            ok &= ModelBase::fromJson(fieldValue, refVal_setFee);
            setFee(refVal_setFee);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("moneyOld"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("moneyOld")));
        if(!fieldValue.is_null())
        {
            double refVal_setMoneyOld;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMoneyOld);
            setMoneyOld(refVal_setMoneyOld);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("moneyAmount"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("moneyAmount")));
        if(!fieldValue.is_null())
        {
            double refVal_setMoneyAmount;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMoneyAmount);
            setMoneyAmount(refVal_setMoneyAmount);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("moneyPledgeAmount"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("moneyPledgeAmount")));
        if(!fieldValue.is_null())
        {
            double refVal_setMoneyPledgeAmount;
            ok &= ModelBase::fromJson(fieldValue, refVal_setMoneyPledgeAmount);
            setMoneyPledgeAmount(refVal_setMoneyPledgeAmount);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("vmInterCl"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("vmInterCl")));
        if(!fieldValue.is_null())
        {
            double refVal_setVmInterCl;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVmInterCl);
            setVmInterCl(refVal_setVmInterCl);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("vmCurrentPositions"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("vmCurrentPositions")));
        if(!fieldValue.is_null())
        {
            double refVal_setVmCurrentPositions;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVmCurrentPositions);
            setVmCurrentPositions(refVal_setVmCurrentPositions);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("varMargin"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("varMargin")));
        if(!fieldValue.is_null())
        {
            double refVal_setVarMargin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setVarMargin);
            setVarMargin(refVal_setVarMargin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("isLimitsSet"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("isLimitsSet")));
        if(!fieldValue.is_null())
        {
            bool refVal_setIsLimitsSet;
            ok &= ModelBase::fromJson(fieldValue, refVal_setIsLimitsSet);
            setIsLimitsSet(refVal_setIsLimitsSet);
        }
    }
    return ok;
}

void Fortsrisk::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_MoneyFreeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("moneyFree")), m_MoneyFree));
    }
    if(m_MoneyBlockedIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("moneyBlocked")), m_MoneyBlocked));
    }
    if(m_BalanceMoneyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("balanceMoney")), m_BalanceMoney));
    }
    if(m_FeeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("fee")), m_Fee));
    }
    if(m_MoneyOldIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("moneyOld")), m_MoneyOld));
    }
    if(m_MoneyAmountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("moneyAmount")), m_MoneyAmount));
    }
    if(m_MoneyPledgeAmountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("moneyPledgeAmount")), m_MoneyPledgeAmount));
    }
    if(m_VmInterClIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("vmInterCl")), m_VmInterCl));
    }
    if(m_VmCurrentPositionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("vmCurrentPositions")), m_VmCurrentPositions));
    }
    if(m_VarMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("varMargin")), m_VarMargin));
    }
    if(m_IsLimitsSetIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("isLimitsSet")), m_IsLimitsSet));
    }
}

bool Fortsrisk::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t(U("moneyFree"))))
    {
        double refVal_setMoneyFree;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("moneyFree"))), refVal_setMoneyFree );
        setMoneyFree(refVal_setMoneyFree);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("moneyBlocked"))))
    {
        double refVal_setMoneyBlocked;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("moneyBlocked"))), refVal_setMoneyBlocked );
        setMoneyBlocked(refVal_setMoneyBlocked);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("balanceMoney"))))
    {
        double refVal_setBalanceMoney;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("balanceMoney"))), refVal_setBalanceMoney );
        setBalanceMoney(refVal_setBalanceMoney);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("fee"))))
    {
        double refVal_setFee;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("fee"))), refVal_setFee );
        setFee(refVal_setFee);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("moneyOld"))))
    {
        double refVal_setMoneyOld;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("moneyOld"))), refVal_setMoneyOld );
        setMoneyOld(refVal_setMoneyOld);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("moneyAmount"))))
    {
        double refVal_setMoneyAmount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("moneyAmount"))), refVal_setMoneyAmount );
        setMoneyAmount(refVal_setMoneyAmount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("moneyPledgeAmount"))))
    {
        double refVal_setMoneyPledgeAmount;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("moneyPledgeAmount"))), refVal_setMoneyPledgeAmount );
        setMoneyPledgeAmount(refVal_setMoneyPledgeAmount);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("vmInterCl"))))
    {
        double refVal_setVmInterCl;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("vmInterCl"))), refVal_setVmInterCl );
        setVmInterCl(refVal_setVmInterCl);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("vmCurrentPositions"))))
    {
        double refVal_setVmCurrentPositions;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("vmCurrentPositions"))), refVal_setVmCurrentPositions );
        setVmCurrentPositions(refVal_setVmCurrentPositions);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("varMargin"))))
    {
        double refVal_setVarMargin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("varMargin"))), refVal_setVarMargin );
        setVarMargin(refVal_setVarMargin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("isLimitsSet"))))
    {
        bool refVal_setIsLimitsSet;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("isLimitsSet"))), refVal_setIsLimitsSet );
        setIsLimitsSet(refVal_setIsLimitsSet);
    }
    return ok;
}

utility::string_t Fortsrisk::getPortfolio() const
{
    return m_Portfolio;
}

void Fortsrisk::setPortfolio(const utility::string_t& value)
{
    m_Portfolio = value;
    m_PortfolioIsSet = true;
}

bool Fortsrisk::portfolioIsSet() const
{
    return m_PortfolioIsSet;
}

void Fortsrisk::unsetPortfolio()
{
    m_PortfolioIsSet = false;
}
double Fortsrisk::getMoneyFree() const
{
    return m_MoneyFree;
}

void Fortsrisk::setMoneyFree(double value)
{
    m_MoneyFree = value;
    m_MoneyFreeIsSet = true;
}

bool Fortsrisk::moneyFreeIsSet() const
{
    return m_MoneyFreeIsSet;
}

void Fortsrisk::unsetMoneyFree()
{
    m_MoneyFreeIsSet = false;
}
double Fortsrisk::getMoneyBlocked() const
{
    return m_MoneyBlocked;
}

void Fortsrisk::setMoneyBlocked(double value)
{
    m_MoneyBlocked = value;
    m_MoneyBlockedIsSet = true;
}

bool Fortsrisk::moneyBlockedIsSet() const
{
    return m_MoneyBlockedIsSet;
}

void Fortsrisk::unsetMoneyBlocked()
{
    m_MoneyBlockedIsSet = false;
}
double Fortsrisk::getBalanceMoney() const
{
    return m_BalanceMoney;
}

void Fortsrisk::setBalanceMoney(double value)
{
    m_BalanceMoney = value;
    m_BalanceMoneyIsSet = true;
}

bool Fortsrisk::balanceMoneyIsSet() const
{
    return m_BalanceMoneyIsSet;
}

void Fortsrisk::unsetBalanceMoney()
{
    m_BalanceMoneyIsSet = false;
}
double Fortsrisk::getFee() const
{
    return m_Fee;
}

void Fortsrisk::setFee(double value)
{
    m_Fee = value;
    m_FeeIsSet = true;
}

bool Fortsrisk::feeIsSet() const
{
    return m_FeeIsSet;
}

void Fortsrisk::unsetFee()
{
    m_FeeIsSet = false;
}
double Fortsrisk::getMoneyOld() const
{
    return m_MoneyOld;
}

void Fortsrisk::setMoneyOld(double value)
{
    m_MoneyOld = value;
    m_MoneyOldIsSet = true;
}

bool Fortsrisk::moneyOldIsSet() const
{
    return m_MoneyOldIsSet;
}

void Fortsrisk::unsetMoneyOld()
{
    m_MoneyOldIsSet = false;
}
double Fortsrisk::getMoneyAmount() const
{
    return m_MoneyAmount;
}

void Fortsrisk::setMoneyAmount(double value)
{
    m_MoneyAmount = value;
    m_MoneyAmountIsSet = true;
}

bool Fortsrisk::moneyAmountIsSet() const
{
    return m_MoneyAmountIsSet;
}

void Fortsrisk::unsetMoneyAmount()
{
    m_MoneyAmountIsSet = false;
}
double Fortsrisk::getMoneyPledgeAmount() const
{
    return m_MoneyPledgeAmount;
}

void Fortsrisk::setMoneyPledgeAmount(double value)
{
    m_MoneyPledgeAmount = value;
    m_MoneyPledgeAmountIsSet = true;
}

bool Fortsrisk::moneyPledgeAmountIsSet() const
{
    return m_MoneyPledgeAmountIsSet;
}

void Fortsrisk::unsetMoneyPledgeAmount()
{
    m_MoneyPledgeAmountIsSet = false;
}
double Fortsrisk::getVmInterCl() const
{
    return m_VmInterCl;
}

void Fortsrisk::setVmInterCl(double value)
{
    m_VmInterCl = value;
    m_VmInterClIsSet = true;
}

bool Fortsrisk::vmInterClIsSet() const
{
    return m_VmInterClIsSet;
}

void Fortsrisk::unsetVmInterCl()
{
    m_VmInterClIsSet = false;
}
double Fortsrisk::getVmCurrentPositions() const
{
    return m_VmCurrentPositions;
}

void Fortsrisk::setVmCurrentPositions(double value)
{
    m_VmCurrentPositions = value;
    m_VmCurrentPositionsIsSet = true;
}

bool Fortsrisk::vmCurrentPositionsIsSet() const
{
    return m_VmCurrentPositionsIsSet;
}

void Fortsrisk::unsetVmCurrentPositions()
{
    m_VmCurrentPositionsIsSet = false;
}
double Fortsrisk::getVarMargin() const
{
    return m_VarMargin;
}

void Fortsrisk::setVarMargin(double value)
{
    m_VarMargin = value;
    m_VarMarginIsSet = true;
}

bool Fortsrisk::varMarginIsSet() const
{
    return m_VarMarginIsSet;
}

void Fortsrisk::unsetVarMargin()
{
    m_VarMarginIsSet = false;
}
bool Fortsrisk::isIsLimitsSet() const
{
    return m_IsLimitsSet;
}

void Fortsrisk::setIsLimitsSet(bool value)
{
    m_IsLimitsSet = value;
    m_IsLimitsSetIsSet = true;
}

bool Fortsrisk::isLimitsSetIsSet() const
{
    return m_IsLimitsSetIsSet;
}

void Fortsrisk::unsetIsLimitsSet()
{
    m_IsLimitsSetIsSet = false;
}
}


