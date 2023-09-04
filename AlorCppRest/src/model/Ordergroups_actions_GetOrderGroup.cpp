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



#include "AlorCppRest/model/Ordergroups_actions_GetOrderGroup.h"

namespace alormodel {



Ordergroups_actions_GetOrderGroup::Ordergroups_actions_GetOrderGroup()
{
    m_Id = utility::conversions::to_string_t("");
    m_IdIsSet = false;
    m_Login = utility::conversions::to_string_t("");
    m_LoginIsSet = false;
    m_OrdersIsSet = false;
    m_ExecutionPolicyIsSet = false;
    m_StatusIsSet = false;
    m_CreatedAt = utility::datetime();
    m_CreatedAtIsSet = false;
    m_ClosedAt = utility::datetime();
    m_ClosedAtIsSet = false;
}

Ordergroups_actions_GetOrderGroup::~Ordergroups_actions_GetOrderGroup()
{
}

void Ordergroups_actions_GetOrderGroup::validate()
{
    // TODO: implement validation
}

web::json::value Ordergroups_actions_GetOrderGroup::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_IdIsSet)
    {
        val[utility::conversions::to_string_t(U("Id"))] = ModelBase::toJson(m_Id);
    }
    if(m_LoginIsSet)
    {
        val[utility::conversions::to_string_t(U("Login"))] = ModelBase::toJson(m_Login);
    }
    if(m_OrdersIsSet)
    {
        val[utility::conversions::to_string_t(U("Orders"))] = ModelBase::toJson(m_Orders);
    }
    if(m_ExecutionPolicyIsSet)
    {
        val[utility::conversions::to_string_t(U("ExecutionPolicy"))] = ModelBase::toJson(m_ExecutionPolicy);
    }
    if(m_StatusIsSet)
    {
        val[utility::conversions::to_string_t(U("Status"))] = ModelBase::toJson(m_Status);
    }
    if(m_CreatedAtIsSet)
    {
        val[utility::conversions::to_string_t(U("CreatedAt"))] = ModelBase::toJson(m_CreatedAt);
    }
    if(m_ClosedAtIsSet)
    {
        val[utility::conversions::to_string_t(U("ClosedAt"))] = ModelBase::toJson(m_ClosedAt);
    }

    return val;
}

bool Ordergroups_actions_GetOrderGroup::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("Id"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Id")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setId;
            ok &= ModelBase::fromJson(fieldValue, refVal_setId);
            setId(refVal_setId);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("Login"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Login")));
        if(!fieldValue.is_null())
        {
            utility::string_t refVal_setLogin;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLogin);
            setLogin(refVal_setLogin);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("Orders"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Orders")));
        if(!fieldValue.is_null())
        {
            std::vector<std::shared_ptr<Ordergroups_actions_GetOrderGroup_Orders_inner>> refVal_setOrders;
            ok &= ModelBase::fromJson(fieldValue, refVal_setOrders);
            setOrders(refVal_setOrders);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("ExecutionPolicy"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("ExecutionPolicy")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<ExecutionPolicy> refVal_setExecutionPolicy;
            ok &= ModelBase::fromJson(fieldValue, refVal_setExecutionPolicy);
            setExecutionPolicy(refVal_setExecutionPolicy);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("Status"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("Status")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OrderGroupStatus> refVal_setStatus;
            ok &= ModelBase::fromJson(fieldValue, refVal_setStatus);
            setStatus(refVal_setStatus);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("CreatedAt"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("CreatedAt")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setCreatedAt;
            ok &= ModelBase::fromJson(fieldValue, refVal_setCreatedAt);
            setCreatedAt(refVal_setCreatedAt);
        }
    }
    if(val.has_field(utility::conversions::to_string_t(U("ClosedAt"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("ClosedAt")));
        if(!fieldValue.is_null())
        {
            utility::datetime refVal_setClosedAt;
            ok &= ModelBase::fromJson(fieldValue, refVal_setClosedAt);
            setClosedAt(refVal_setClosedAt);
        }
    }
    return ok;
}

void Ordergroups_actions_GetOrderGroup::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Id")), m_Id));
    }
    if(m_LoginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Login")), m_Login));
    }
    if(m_OrdersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Orders")), m_Orders));
    }
    if(m_ExecutionPolicyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("ExecutionPolicy")), m_ExecutionPolicy));
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("Status")), m_Status));
    }
    if(m_CreatedAtIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("CreatedAt")), m_CreatedAt));
    }
    if(m_ClosedAtIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("ClosedAt")), m_ClosedAt));
    }
}

bool Ordergroups_actions_GetOrderGroup::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("Id"))))
    {
        utility::string_t refVal_setId;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Id"))), refVal_setId );
        setId(refVal_setId);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("Login"))))
    {
        utility::string_t refVal_setLogin;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Login"))), refVal_setLogin );
        setLogin(refVal_setLogin);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("Orders"))))
    {
        std::vector<std::shared_ptr<Ordergroups_actions_GetOrderGroup_Orders_inner>> refVal_setOrders;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Orders"))), refVal_setOrders );
        setOrders(refVal_setOrders);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("ExecutionPolicy"))))
    {
        std::shared_ptr<ExecutionPolicy> refVal_setExecutionPolicy;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("ExecutionPolicy"))), refVal_setExecutionPolicy );
        setExecutionPolicy(refVal_setExecutionPolicy);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("Status"))))
    {
        std::shared_ptr<OrderGroupStatus> refVal_setStatus;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("Status"))), refVal_setStatus );
        setStatus(refVal_setStatus);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("CreatedAt"))))
    {
        utility::datetime refVal_setCreatedAt;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("CreatedAt"))), refVal_setCreatedAt );
        setCreatedAt(refVal_setCreatedAt);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("ClosedAt"))))
    {
        utility::datetime refVal_setClosedAt;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("ClosedAt"))), refVal_setClosedAt );
        setClosedAt(refVal_setClosedAt);
    }
    return ok;
}

utility::string_t Ordergroups_actions_GetOrderGroup::getId() const
{
    return m_Id;
}

void Ordergroups_actions_GetOrderGroup::setId(const utility::string_t& value)
{
    m_Id = value;
    m_IdIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::idIsSet() const
{
    return m_IdIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetId()
{
    m_IdIsSet = false;
}
utility::string_t Ordergroups_actions_GetOrderGroup::getLogin() const
{
    return m_Login;
}

void Ordergroups_actions_GetOrderGroup::setLogin(const utility::string_t& value)
{
    m_Login = value;
    m_LoginIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::loginIsSet() const
{
    return m_LoginIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetLogin()
{
    m_LoginIsSet = false;
}
std::vector<std::shared_ptr<Ordergroups_actions_GetOrderGroup_Orders_inner>>& Ordergroups_actions_GetOrderGroup::getOrders()
{
    return m_Orders;
}

void Ordergroups_actions_GetOrderGroup::setOrders(const std::vector<std::shared_ptr<Ordergroups_actions_GetOrderGroup_Orders_inner>>& value)
{
    m_Orders = value;
    m_OrdersIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::ordersIsSet() const
{
    return m_OrdersIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetOrders()
{
    m_OrdersIsSet = false;
}
std::shared_ptr<ExecutionPolicy> Ordergroups_actions_GetOrderGroup::getExecutionPolicy() const
{
    return m_ExecutionPolicy;
}

void Ordergroups_actions_GetOrderGroup::setExecutionPolicy(const std::shared_ptr<ExecutionPolicy>& value)
{
    m_ExecutionPolicy = value;
    m_ExecutionPolicyIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::executionPolicyIsSet() const
{
    return m_ExecutionPolicyIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetExecutionPolicy()
{
    m_ExecutionPolicyIsSet = false;
}
std::shared_ptr<OrderGroupStatus> Ordergroups_actions_GetOrderGroup::getStatus() const
{
    return m_Status;
}

void Ordergroups_actions_GetOrderGroup::setStatus(const std::shared_ptr<OrderGroupStatus>& value)
{
    m_Status = value;
    m_StatusIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::statusIsSet() const
{
    return m_StatusIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetStatus()
{
    m_StatusIsSet = false;
}
utility::datetime Ordergroups_actions_GetOrderGroup::getCreatedAt() const
{
    return m_CreatedAt;
}

void Ordergroups_actions_GetOrderGroup::setCreatedAt(const utility::datetime& value)
{
    m_CreatedAt = value;
    m_CreatedAtIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::createdAtIsSet() const
{
    return m_CreatedAtIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetCreatedAt()
{
    m_CreatedAtIsSet = false;
}
utility::datetime Ordergroups_actions_GetOrderGroup::getClosedAt() const
{
    return m_ClosedAt;
}

void Ordergroups_actions_GetOrderGroup::setClosedAt(const utility::datetime& value)
{
    m_ClosedAt = value;
    m_ClosedAtIsSet = true;
}

bool Ordergroups_actions_GetOrderGroup::closedAtIsSet() const
{
    return m_ClosedAtIsSet;
}

void Ordergroups_actions_GetOrderGroup::unsetClosedAt()
{
    m_ClosedAtIsSet = false;
}
}


