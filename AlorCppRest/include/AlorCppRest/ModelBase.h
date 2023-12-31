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

/*
 * ModelBase.h
 *
 * This is the base class for all model classes
 */

#ifndef ALORMODEL_ModelBase_H_
#define ALORMODEL_ModelBase_H_



#include "AlorCppRest/HttpContent.h"
#include "AlorCppRest/MultipartFormData.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/json.h>

#include <map>
#include <vector>

namespace alormodel {

class  ModelBase
{
public:
    ModelBase();
    virtual ~ModelBase();

    virtual void validate() = 0;

    virtual web::json::value toJson() const = 0;
    virtual bool fromJson( const web::json::value& json ) = 0;

    virtual void toMultipart( std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix ) const = 0;
    virtual bool fromMultiPart( std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix ) = 0;

    virtual bool isSet() const;

    static utility::string_t toString( const bool val );
    static utility::string_t toString( const float val );
    static utility::string_t toString( const double val );
    static utility::string_t toString( const int32_t val );
    static utility::string_t toString( const int64_t val );
    static utility::string_t toString( const utility::string_t &val );
    static utility::string_t toString( const utility::datetime &val );
    static utility::string_t toString( const web::json::value &val );
    static utility::string_t toString( const std::shared_ptr<HttpContent>& val );
    template <typename T>
    static utility::string_t toString( const std::shared_ptr<T>& val );
    template <typename T>
    static utility::string_t toString( const std::vector<T> & val );

    static web::json::value toJson( bool val );
    static web::json::value toJson( float val );
    static web::json::value toJson( double val );
    static web::json::value toJson( int32_t val );
    static web::json::value toJson( int64_t val );
    static web::json::value toJson( const utility::string_t& val );
    static web::json::value toJson( const utility::datetime& val );
    static web::json::value toJson( const web::json::value& val );
    static web::json::value toJson( const std::shared_ptr<HttpContent>& val );
    template<typename T>
    static web::json::value toJson( const std::shared_ptr<T>& val );
    static web::json::value toJson( const std::shared_ptr<utility::datetime>& val );
    template<typename T>
    static web::json::value toJson( const std::vector<T>& val );
    template<typename T>
    static web::json::value toJson( const std::map<utility::string_t, T>& val );

    static bool fromString( const utility::string_t& val, bool & );
    static bool fromString( const utility::string_t& val, float & );
    static bool fromString( const utility::string_t& val, double & );
    static bool fromString( const utility::string_t& val, int32_t & );
    static bool fromString( const utility::string_t& val, int64_t & );
    static bool fromString( const utility::string_t& val, utility::string_t & );
    static bool fromString( const utility::string_t& val, utility::datetime & );
    static bool fromString( const utility::string_t& val, web::json::value & );
    static bool fromString( const utility::string_t& val, std::shared_ptr<HttpContent> & );
    template<typename T>
    static bool fromString( const utility::string_t& val, std::shared_ptr<T>& );
    static bool fromString( const utility::string_t& val, std::shared_ptr<utility::datetime>& outVal );
    template<typename T>
    static bool fromString( const utility::string_t& val, std::vector<T> & );
    template<typename T>
    static bool fromString( const utility::string_t& val, std::map<utility::string_t, T> & );

    static bool fromJson( const web::json::value& val, bool & );
    static bool fromJson( const web::json::value& val, float & );
    static bool fromJson( const web::json::value& val, double & );
    static bool fromJson( const web::json::value& val, int32_t & );
    static bool fromJson( const web::json::value& val, int64_t & );
    static bool fromJson( const web::json::value& val, utility::string_t & );
    static bool fromJson( const web::json::value& val, utility::datetime & );
    static bool fromJson( const web::json::value& val, web::json::value & );
    static bool fromJson( const web::json::value& val, std::shared_ptr<HttpContent> & );
    template<typename T>
    static bool fromJson( const web::json::value& val, std::shared_ptr<T>& );
    static bool fromJson( const web::json::value& val, std::shared_ptr<utility::datetime> &outVal );
    template<typename T>
    static bool fromJson( const web::json::value& val, std::vector<T> & );
    template<typename T>
    static bool fromJson( const web::json::value& val, std::map<utility::string_t, T> & );


    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, bool value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, float value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, double value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int32_t value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int64_t value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::string_t& value, const utility::string_t& contentType = utility::conversions::to_string_t(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::datetime& value, const utility::string_t& contentType = utility::conversions::to_string_t(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const web::json::value& value, const utility::string_t& contentType = utility::conversions::to_string_t("application/json") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::shared_ptr<HttpContent>& );
    template <typename T>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::shared_ptr<T>& , const utility::string_t& contentType = utility::conversions::to_string_t("application/json") );
    static std::shared_ptr<HttpContent> toHttpContent(const utility::string_t& name, const std::shared_ptr<utility::datetime>& value , const utility::string_t& contentType = utility::conversions::to_string_t("application/json") );
    template <typename T>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType = utility::conversions::to_string_t("") );
    template <typename T>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::map<utility::string_t, T>& value, const utility::string_t& contentType = utility::conversions::to_string_t("") );

    static bool fromHttpContent( std::shared_ptr<HttpContent> val, bool & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, float & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, double & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, int64_t & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, int32_t & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, utility::string_t & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, utility::datetime & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, web::json::value & );
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, std::shared_ptr<HttpContent>& );
    template <typename T>
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, std::shared_ptr<T>& );
    template <typename T>
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, std::vector<T> & );
    template <typename T>
    static bool fromHttpContent( std::shared_ptr<HttpContent> val, std::map<utility::string_t, T> & );

    static utility::string_t toBase64( utility::string_t value );
    static utility::string_t toBase64( std::shared_ptr<std::istream> value );
    static std::shared_ptr<std::istream> fromBase64( const utility::string_t& encoded );
protected:
    bool m_IsSet;
};

template <typename T>
utility::string_t ModelBase::toString( const std::shared_ptr<T>& val )
{
    utility::stringstream_t ss;
    if( val != nullptr )
    {
        val->toJson().serialize(ss);
    }
    return  utility::string_t(ss.str());
}
template<typename T>
utility::string_t ModelBase::toString( const std::vector<T> & val )
{
    utility::string_t strArray;
    for ( const auto &item : val )
    {
        strArray.append( toString(item) + "," );
    }
    if (val.count() > 0)
    {
        strArray.pop_back();
    }
    return strArray;
}
template<typename T>
web::json::value ModelBase::toJson( const std::shared_ptr<T>& val )
{
    web::json::value retVal;
    if(val != nullptr)
    {
        retVal = val->toJson();
    }
    return retVal;
}
template<typename T>
web::json::value ModelBase::toJson( const std::vector<T>& value )
{
    std::vector<web::json::value> ret;
    for ( const auto& x : value )
    {
        ret.push_back( toJson(x) );
    }
    return web::json::value::array(ret);
}
template<typename T>
web::json::value ModelBase::toJson( const std::map<utility::string_t, T>& val )
{
    web::json::value obj;
    for ( const auto &itemkey : val )
    {
        obj[itemkey.first] = toJson( itemkey.second );
    }
    return obj;
}
template<typename T>
bool ModelBase::fromString( const utility::string_t& val, std::shared_ptr<T>& outVal )
{
    bool ok = false;
    if(outVal == nullptr)
    {
        outVal = std::shared_ptr<T>(new T());
    }
    if( outVal != nullptr )
    {
        ok = outVal->fromJson(web::json::value::parse(val));
    }
    return ok;
}
template<typename T>
bool ModelBase::fromJson( const web::json::value& val, std::shared_ptr<T> &outVal )
{
    bool ok = false;
    if(outVal == nullptr)
    {
        outVal = std::shared_ptr<T>(new T());
    }
    if( outVal != nullptr )
    {
        ok = outVal->fromJson(val);
    }
    return ok;
}
template<typename T>
bool ModelBase::fromJson( const web::json::value& val, std::vector<T> &outVal )
{
    bool ok = true;
    if (val.is_array())
    {
        for (const auto jitem : val.as_array())
        {
            T item;
            ok &= fromJson(jitem, item);
            outVal.push_back(item);
        }
    }
    else
    {
        ok = false;
    }
    return ok;
}
template<typename T>
bool ModelBase::fromJson( const web::json::value& jval, std::map<utility::string_t, T> &outVal )
{
    bool ok = true;
    if ( jval.is_object() )
    {
        auto obj = jval.as_object();
        for( auto objItr = obj.begin() ; objItr != obj.end() ; objItr++ )
        {
            T itemVal;
            ok &= fromJson(objItr->second, itemVal);
            outVal.insert(std::pair<utility::string_t, T>(objItr->first, itemVal));
        }
    }
    else
    {
        ok = false;
    }
    return ok;
}
template <typename T>
std::shared_ptr<HttpContent> ModelBase::toHttpContent(const utility::string_t& name, const std::shared_ptr<T>& value , const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    if (value != nullptr )
    {
        content->setName( name );
        content->setContentDisposition( utility::conversions::to_string_t("form-data") );
        content->setContentType( contentType );
        content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string( value->toJson().serialize() ) ) ) );
    }
    return content;
}
template <typename T>
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType )
{
    web::json::value json_array = ModelBase::toJson(value);
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(json_array.serialize()) ) ) );
    return content;
}
template <typename T>
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const std::map<utility::string_t, T>& value, const utility::string_t& contentType )
{
    web::json::value jobj = ModelBase::toJson(value);
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(jobj.serialize()) ) ) );
    return content;
}
template <typename T>
bool ModelBase::fromHttpContent( std::shared_ptr<HttpContent> val,  std::shared_ptr<T>& outVal )
{
    utility::string_t str;
    if(val == nullptr) return false;
    if( outVal == nullptr )
    {
        outVal = std::shared_ptr<T>(new T());
    }
    ModelBase::fromHttpContent(val, str);
    return fromString(str, outVal);
}
template <typename T>
bool ModelBase::fromHttpContent( std::shared_ptr<HttpContent> val, std::vector<T> & )
{
    return true;
}
template <typename T>
bool ModelBase::fromHttpContent( std::shared_ptr<HttpContent> val, std::map<utility::string_t, T> & )
{
    return true;
}
}

#endif /* ALORMODEL_ModelBase_H_ */
