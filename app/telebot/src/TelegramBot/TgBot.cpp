// application
#include "TelegramBot/TgBot.hpp"

namespace Telebot {
   namespace TelegramBot {

      //
      // UserTgBot
      //
      const std::int64_t UserTgBot::getId() const noexcept {
         return _user_ptr->id;
      };

      const bool UserTgBot::getIsBot() const noexcept {
         return _user_ptr->isBot;
      };

      const std::string& UserTgBot::getFirstName() const noexcept {
         return _user_ptr->firstName;
      };

      const std::string& UserTgBot::getLastName() const noexcept {
         return _user_ptr->lastName;
      };

      const std::string& UserTgBot::getUsername() const noexcept {
         return _user_ptr->username;
      };

      const std::string& UserTgBot::getLanguageCode() const noexcept {
         return _user_ptr->languageCode;
      };


      //
      // ChatTgBot
      //
      const std::int64_t ChatTgBot::getId() const noexcept {
         return _chat_ptr->id;
      };

      const std::string& ChatTgBot::getTitle() const noexcept {
         return _chat_ptr->title;
      };

      const std::string& ChatTgBot::getUsername() const noexcept {
         return _chat_ptr->username;
      };

      const std::string& ChatTgBot::getFirstName() const noexcept {
         return _chat_ptr->firstName;
      };

      const std::string& ChatTgBot::getLastName() const noexcept {
         return _chat_ptr->lastName;
      };

      const bool ChatTgBot::getIsForum() const noexcept {
         return _chat_ptr->isForum;
      };

      const std::vector<std::string>& ChatTgBot::getActiveUsernames() const noexcept {
         return _chat_ptr->activeUsernames;
      };

      const std::string& ChatTgBot::getEmojiStatusCustomEmojiId() const noexcept {
         return _chat_ptr->emojiStatusCustomEmojiId;
      };

      const std::string& ChatTgBot::getBio() const noexcept {
         return _chat_ptr->bio;
      };

      const std::string& ChatTgBot::getDescription() const noexcept {
         return _chat_ptr->description;
      };

      const std::string& ChatTgBot::getInviteLink() const noexcept {
         return _chat_ptr->inviteLink;
      };


      //
      // MessageTgBot
      //
      const std::int32_t MessageTgBot::getMessageId() const noexcept {
         return _message_ptr->messageId;
      };

      const std::int32_t MessageTgBot::getMessageThreadId() const noexcept {
         return _message_ptr->messageThreadId;
      };

      const IUser::CPtr& MessageTgBot::getFrom() const noexcept {
         return _from;
      };

      const IChat::CPtr& MessageTgBot::getSenderChat() const noexcept {
         return _senderChat;
      };

      const std::int32_t MessageTgBot::getDate() const noexcept {
         return _message_ptr->date;
      };

      const IChat::CPtr& MessageTgBot::getChat() const noexcept {
         return _chat;
      };

      const std::string& MessageTgBot::getText() const noexcept {
         return _message_ptr->text;
      };


      //
      // TelegramBotTgBot
      //
      void TelegramBotTgBot::initialize( const std::string &token ) {
         _bot = std::make_unique<TgBot::Bot>( token );

         _bot->getEvents().onCommand(
            "start",
            [this]( TgBot::Message::Ptr message ) {
               this->_bot->getApi().sendMessage( message->chat->id, "Hi!" );
            }
         );

         _bot->getEvents().onAnyMessage(
            [this]( TgBot::Message::Ptr message ) {
               this->ReactOnAnyMessage( std::make_unique<const MessageTgBot>( message ) );
            }
         );
      };

      void TelegramBotTgBot::start() {
         _bot->getApi().deleteWebhook();

         TgBot::TgLongPoll longPoll( *_bot );
         while ( true ) {
            longPoll.start();
         }
      };

      void TelegramBotTgBot::sendMessage( const IChat::CPtr& chat, const std::string& message ) {
         _bot->getApi().sendMessage( chat->getId(), message );
      };

      const IUser::CPtr TelegramBotTgBot::getMe() {
         return std::make_unique<const UserTgBot>( _bot->getApi().getMe() );
      };
      
   }
}
