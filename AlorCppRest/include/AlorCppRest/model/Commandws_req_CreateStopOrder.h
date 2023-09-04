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
 * Commandws_req_CreateStopOrder.h
 *
 * 
 */

#ifndef ALORMODEL_Commandws_req_CreateStopOrder_H_
#define ALORMODEL_Commandws_req_CreateStopOrder_H_


#include "AlorCppRest/ModelBase.h"

#include "AlorCppRest/model/Condition.h"
#include "AlorCppRest/model/Side.h"
#include "AlorCppRest/model/Bodyrequest_OrdersActionsLimitTVput_user.h"
#include <cpprest/details/basic_types.h>
#include "AlorCppRest/model/Bodyrequest_OrdersActionsLimitTVput_instrument.h"

namespace alormodel {

class Bodyrequest_OrdersActionsLimitTVput_instrument;
class Bodyrequest_OrdersActionsLimitTVput_user;

/// <summary>
/// 
/// </summary>
class  Commandws_req_CreateStopOrder
    : public ModelBase
{
public:
    Commandws_req_CreateStopOrder();
    virtual ~Commandws_req_CreateStopOrder();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Commandws_req_CreateStopOrder members

    /// <summary>
    /// Код операции
    /// </summary>
    utility::string_t getOpcode() const;
    bool opcodeIsSet() const;
    void unsetOpcode();

    void setOpcode(const utility::string_t& value);

    /// <summary>
    /// Клиентский идентификатор команды. В качестве идентификатора требуется уникальная случайная строка. Если уже приходил запрос с таким идентификатором, то команда не будет исполнена повторно.
    /// </summary>
    utility::string_t getGuid() const;
    bool guidIsSet() const;
    void unsetGuid();

    void setGuid(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Side> getSide() const;
    bool sideIsSet() const;
    void unsetSide();

    void setSide(const std::shared_ptr<Side>& value);

    /// <summary>
    /// Количество (лоты)
    /// </summary>
    int32_t getQuantity() const;
    bool quantityIsSet() const;
    void unsetQuantity();

    void setQuantity(int32_t value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Condition> getCondition() const;
    bool conditionIsSet() const;
    void unsetCondition();

    void setCondition(const std::shared_ptr<Condition>& value);

    /// <summary>
    /// Цена срабатывания
    /// </summary>
    double getTriggerPrice() const;
    bool triggerPriceIsSet() const;
    void unsetTriggerPrice();

    void setTriggerPrice(double value);

    /// <summary>
    /// Срок действия (UTC) в формате Unix Time seconds
    /// </summary>
    int64_t getStopEndUnixTime() const;
    bool stopEndUnixTimeIsSet() const;
    void unsetStopEndUnixTime();

    void setStopEndUnixTime(int64_t value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_instrument> getInstrument() const;
    bool instrumentIsSet() const;
    void unsetInstrument();

    void setInstrument(const std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_instrument>& value);

    /// <summary>
    /// Режим торгов (борд)
    /// </summary>
    utility::string_t getBoard() const;
    bool boardIsSet() const;
    void unsetBoard();

    void setBoard(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_user> getUser() const;
    bool userIsSet() const;
    void unsetUser();

    void setUser(const std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_user>& value);

    /// <summary>
    /// Флаг, отвечающий за проверку уникальности команд. По умолчанию включен.
    /// </summary>
    bool isCheckDuplicates() const;
    bool checkDuplicatesIsSet() const;
    void unsetCheckDuplicates();

    void setCheckDuplicates(bool value);

    /// <summary>
    /// Флаг указывает, создать активную заявку, или не активную. Не активная заявка отображается в системе, но не участвует в процессе выставления на биржу, пока не станет активной. Данный флаг необходим при создании группы заявок с типом &#39;TriggerBracketOrders&#39; 
    /// </summary>
    bool isActivate() const;
    bool activateIsSet() const;
    void unsetActivate();

    void setActivate(bool value);


protected:
    utility::string_t m_Opcode;
    bool m_OpcodeIsSet;
    utility::string_t m_Guid;
    bool m_GuidIsSet;
    std::shared_ptr<Side> m_Side;
    bool m_SideIsSet;
    int32_t m_Quantity;
    bool m_QuantityIsSet;
    std::shared_ptr<Condition> m_Condition;
    bool m_ConditionIsSet;
    double m_TriggerPrice;
    bool m_TriggerPriceIsSet;
    int64_t m_StopEndUnixTime;
    bool m_StopEndUnixTimeIsSet;
    std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_instrument> m_Instrument;
    bool m_InstrumentIsSet;
    utility::string_t m_Board;
    bool m_BoardIsSet;
    std::shared_ptr<Bodyrequest_OrdersActionsLimitTVput_user> m_User;
    bool m_UserIsSet;
    bool m_CheckDuplicates;
    bool m_CheckDuplicatesIsSet;
    bool m_Activate;
    bool m_ActivateIsSet;
};


}

#endif /* ALORMODEL_Commandws_req_CreateStopOrder_H_ */
