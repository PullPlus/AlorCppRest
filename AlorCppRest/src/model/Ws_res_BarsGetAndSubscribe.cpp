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



#include "AlorCppRest/model/Ws_res_BarsGetAndSubscribe.h"

namespace alormodel {



Ws_res_BarsGetAndSubscribe::Ws_res_BarsGetAndSubscribe()
{
    m_DataIsSet = false;
    m_Guid = utility::conversions::to_string_t("");
    m_GuidIsSet = false;
}

Ws_res_BarsGetAndSubscribe::~Ws_res_BarsGetAndSubscribe()
{
}

void Ws_res_BarsGetAndSubscribe::validate()
{
    // TODO: implement validation
}

web::json::value Ws_res_BarsGetAndSubscribe::toJson() const
{

    web::json::value val = web::json::value::object();
    
    if(m_DataIsSet)
    {
        val[utility::conversions::to_string_t(U("data"))] = ModelBase::toJson(m_Data);
    }
    if(m_GuidIsSet)
    {
        val[utility::conversions::to_string_t(U("guid"))] = ModelBase::toJson(m_Guid);
    }

    return val;
}

bool Ws_res_BarsGetAndSubscribe::fromJson(const web::json::value& val)
{
    bool ok = true;
    
    if(val.has_field(utility::conversions::to_string_t(U("data"))))
    {
        const web::json::value& fieldValue = val.at(utility::conversions::to_string_t(U("data")));
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Ws_res_BarsGetAndSubscribe_data> refVal_setData;
            ok &= ModelBase::fromJson(fieldValue, refVal_setData);
            setData(refVal_setData);
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

void Ws_res_BarsGetAndSubscribe::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if(m_DataIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("data")), m_Data));
    }
    if(m_GuidIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t(U("guid")), m_Guid));
    }
}

bool Ws_res_BarsGetAndSubscribe::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t(U(".")))
    {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if(multipart->hasContent(utility::conversions::to_string_t(U("data"))))
    {
        std::shared_ptr<Ws_res_BarsGetAndSubscribe_data> refVal_setData;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("data"))), refVal_setData );
        setData(refVal_setData);
    }
    if(multipart->hasContent(utility::conversions::to_string_t(U("guid"))))
    {
        utility::string_t refVal_setGuid;
        ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t(U("guid"))), refVal_setGuid );
        setGuid(refVal_setGuid);
    }
    return ok;
}

std::shared_ptr<Ws_res_BarsGetAndSubscribe_data> Ws_res_BarsGetAndSubscribe::getData() const
{
    return m_Data;
}

void Ws_res_BarsGetAndSubscribe::setData(const std::shared_ptr<Ws_res_BarsGetAndSubscribe_data>& value)
{
    m_Data = value;
    m_DataIsSet = true;
}

bool Ws_res_BarsGetAndSubscribe::dataIsSet() const
{
    return m_DataIsSet;
}

void Ws_res_BarsGetAndSubscribe::unsetData()
{
    m_DataIsSet = false;
}
utility::string_t Ws_res_BarsGetAndSubscribe::getGuid() const
{
    return m_Guid;
}

void Ws_res_BarsGetAndSubscribe::setGuid(const utility::string_t& value)
{
    m_Guid = value;
    m_GuidIsSet = true;
}

bool Ws_res_BarsGetAndSubscribe::guidIsSet() const
{
    return m_GuidIsSet;
}

void Ws_res_BarsGetAndSubscribe::unsetGuid()
{
    m_GuidIsSet = false;
}
}


