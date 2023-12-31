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
 * InstrumentsApi.h
 *
 * 
 */

#ifndef ALORAPI_InstrumentsApi_H_
#define ALORAPI_InstrumentsApi_H_



#include "AlorCppRest/ApiClient.h"

#include "AlorCppRest/model/Alltrade.h"
#include "AlorCppRest/model/Alltradeshistory.h"
#include "AlorCppRest/model/History.h"
#include "AlorCppRest/model/Orderbook.h"
#include "AlorCppRest/model/RiskRates.h"
#include "AlorCppRest/model/Security.h"
#include "AlorCppRest/model/Symbol.h"
#include "AlorCppRest/model/Symbol_futures.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace alorapi {

using namespace alormodel;



class  InstrumentsApi 
{
public:

    explicit InstrumentsApi( std::shared_ptr<const ApiClient> apiClient );

    virtual ~InstrumentsApi();

    /// <summary>
    /// Запрос истории для выбранных биржи и инструмента
    /// </summary>
    /// <remarks>
    /// Запрос истории рынка для выбранных биржи и финансового инструмента. Данные имеют задержку в 15 минут, если запрос не авторизован. Для авторизованных клиентов задержка не применяется.
    /// </remarks>
    /// <param name="symbol">Тикер (Код финансового инструмента)</param>
    /// <param name="exchange">Биржа</param>
    /// <param name="tf">Длительность таймфрейма в секундах или код (\&quot;D\&quot; - дни, \&quot;W\&quot; - недели, \&quot;M\&quot; - месяцы, \&quot;Y\&quot; - годы)</param>
    /// <param name="from">Начало отрезка времени (UTC) в формате Unix Time Seconds</param>
    /// <param name="to">Конец отрезка времени (UTC) в формате Unix Time Seconds</param>
    /// <param name="untraded">Флаг для поиска данных по устаревшим или экспирированным инструментам. При использовании требуется точное совпадение тикера (optional, default to false)</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<History>> devHistory(
        utility::string_t symbol,
        utility::string_t exchange,
        utility::string_t tf,
        int64_t from,
        int64_t to,
        boost::optional<bool> untraded,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение информации о биржевом стакане
    /// </summary>
    /// <remarks>
    /// Запрос биржевого стакана
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="seccode">Инструмент</param>
    /// <param name="depth">Глубина стакана. Стандартное и максимальное значение - 20 (20х20). (optional, default to 0)</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<Orderbook>> devOrderbookExchangSeccode(
        utility::string_t exchange,
        utility::string_t seccode,
        boost::optional<int32_t> depth,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение информации о котировках для выбранных инструментов
    /// </summary>
    /// <remarks>
    /// Запрос информации о котировках для выбранных инструментов и бирж
    /// </remarks>
    /// <param name="symbols">Принимает несколько пар биржа-тикер. Пары отделены запятыми. Биржа и тикер разделены двоеточием</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::vector<std::shared_ptr<Symbol>>> devQuotes(
        utility::string_t symbols,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение котировки по ближайшему фьючерсу (код)
    /// </summary>
    /// <remarks>
    /// Запрос котировки по ближайшему фьючерсу (только по коду, без даты)
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="symbol">Тикер (Код финансового инструмента)</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<Symbol_futures>> devSecuritiesFutures(
        utility::string_t exchange,
        utility::string_t symbol,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение информации о торговых инструментах
    /// </summary>
    /// <remarks>
    /// Запрос информации о торговых инструментах
    /// </remarks>
    /// <param name="query">Тикер (Код финансового инструмента)</param>
    /// <param name="limit">Ограничение на количество выдаваемых результатов поиска (optional, default to 0)</param>
    /// <param name="offset">Смещение начала выборки (для пагинации) (optional, default to 0)</param>
    /// <param name="sector">Рынок на бирже (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="cficode">Код финансового инструмента по стандарту ISO 10962 (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="exchange">Биржа (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::vector<std::shared_ptr<Security>>> devSecuritiesSearch(
        utility::string_t query,
        boost::optional<int32_t> limit,
        boost::optional<int32_t> offset,
        boost::optional<utility::string_t> sector,
        boost::optional<utility::string_t> cficode,
        boost::optional<utility::string_t> exchange,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение информации о всех сделках по ценным бумагам за сегодня
    /// </summary>
    /// <remarks>
    /// Запросить данные о всех сделках (лента) по ценным бумагам за сегодняшний день
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="symbol">Тикер (Код финансового инструмента)</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="from">Начало отрезка времени (UTC) для фильтра результатов в формате Unix Time Seconds (optional, default to 0L)</param>
    /// <param name="to">Конец отрезка времени (UTC) для фильтра результатов в формате Unix Time Seconds (optional, default to 0L)</param>
    /// <param name="fromId">Начальный номер сделки для фильтра результатов (optional, default to 0L)</param>
    /// <param name="toId">Конечный номер сделки для фильтра результатов (optional, default to 0L)</param>
    /// <param name="take">Количество загружаемых элементов (optional, default to 0)</param>
    /// <param name="descending">Флаг обратной сортировки выдачи (optional, default to false)</param>
    /// <param name="includeVirtualTrades">Флаг загрузки виртуальных (индикативных) сделок, полученных из заявок на питерской бирже (optional, default to false)</param>
    pplx::task<std::vector<std::shared_ptr<Alltrade>>> devSecuritiesSearchAllTrades(
        utility::string_t exchange,
        utility::string_t symbol,
        boost::optional<utility::string_t> format,
        boost::optional<int64_t> from,
        boost::optional<int64_t> to,
        boost::optional<int64_t> fromId,
        boost::optional<int64_t> toId,
        boost::optional<int32_t> take,
        boost::optional<bool> descending,
        boost::optional<bool> includeVirtualTrades
    ) const;
    /// <summary>
    /// Получение исторической информации о всех сделках по ценным бумагам
    /// </summary>
    /// <remarks>
    /// Запросить данные о сделках (лента) по ценным бумагам за исторический период (за текущий день сделки не отдаются)
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="symbol">Тикер (Код финансового инструмента)</param>
    /// <param name="limit">Ограничение на количество выдаваемых результатов поиска (1-50000)</param>
    /// <param name="from">Начало отрезка времени (UTC) для фильтра результатов в формате Unix Time Seconds (optional, default to 0L)</param>
    /// <param name="to">Конец отрезка времени (UTC) для фильтра результатов в формате Unix Time Seconds (optional, default to 0L)</param>
    /// <param name="offset">Смещение начала выборки (для пагинации) (optional, default to 0)</param>
    pplx::task<std::shared_ptr<Alltradeshistory>> devSecuritiesSearchAllTradesHistory(
        utility::string_t exchange,
        utility::string_t symbol,
        int32_t limit,
        boost::optional<int64_t> from,
        boost::optional<int64_t> to,
        boost::optional<int32_t> offset
    ) const;
    /// <summary>
    /// Получение информации о торговых инструментах на выбранной бирже
    /// </summary>
    /// <remarks>
    /// Запрос информации об инструментах на выбранной бирже
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::vector<std::shared_ptr<Security>>> devSecuritiesSearchExchange(
        utility::string_t exchange,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Получение информации о выбранном финансовом инструменте
    /// </summary>
    /// <remarks>
    /// Запрос информации о выбранном финансовом инструменте на бирже
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="symbol">Тикер (Код финансового инструмента)</param>
    /// <param name="format">Формат возвращаемого сервером JSON (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<Security>> devSecuritiesSearchExchangeCode(
        utility::string_t exchange,
        utility::string_t symbol,
        boost::optional<utility::string_t> format
    ) const;
    /// <summary>
    /// Запрос ставок риска
    /// </summary>
    /// <remarks>
    /// Получение ставок риска для маржинальной торговли.
    /// </remarks>
    /// <param name="exchange">Биржа</param>
    /// <param name="ticker">Тикер\\код инструмента, ISIN для облигаций (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    /// <param name="riskCategoryId">Id вашей (или той которая интересует) категории риска. Можно получить из запроса информации по клиенту или через кабинет клиента (optional, default to 0)</param>
    /// <param name="search">Часть Тикера\\кода инструмента, ISIN для облигаций. Вернет все совпадения, начинающиеся с  (optional, default to utility::conversions::to_string_t(&quot;&quot;))</param>
    pplx::task<std::shared_ptr<RiskRates>> riskRates(
        utility::string_t exchange,
        boost::optional<utility::string_t> ticker,
        boost::optional<int32_t> riskCategoryId,
        boost::optional<utility::string_t> search
    ) const;

protected:
    std::shared_ptr<const ApiClient> m_ApiClient;
};

}

#endif /* ALORAPI_InstrumentsApi_H_ */

