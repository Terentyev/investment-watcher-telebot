#ifndef TELEGRAM_BOT_TG_BOT_HPP

#define TELEGRAM_BOT_TG_BOT_HPP

// STDLIB
#include <string>

// TgBot
#include <tgbot/tgbot.h>

// application
#include "TelegramBot.hpp"


namespace Telebot {
   namespace TelegramBot {
      
      /// Implement telegram user object for TgBot library.
      class UserTgBot: public IUser {
         public:
            UserTgBot();
            UserTgBot( TgBot::User::Ptr user_ptr ):
               _user_ptr( user_ptr )
            {
            };

            const std::int64_t getId() const noexcept override;
            const bool getIsBot() const noexcept override;
            const std::string& getFirstName() const noexcept override;
            const std::string& getLastName() const noexcept override;
            const std::string& getUsername() const noexcept override;
            const std::string& getLanguageCode() const noexcept override;

         private:
            const TgBot::User::Ptr _user_ptr;
      };


      /// Implement telegram chat object for TgBot library.
      class ChatTgBot: public IChat {
         public:
            ChatTgBot();
            ChatTgBot( TgBot::Chat::Ptr chat_ptr ):
               _chat_ptr( chat_ptr )
            {
            };
         
            const std::int64_t getId() const noexcept override;
            const std::string& getTitle() const noexcept override;
            const std::string& getUsername() const noexcept override;
            const std::string& getFirstName() const noexcept override;
            const std::string& getLastName() const noexcept override;
            const bool getIsForum() const noexcept override;
            const std::vector<std::string>& getActiveUsernames() const noexcept override;
            const std::string& getEmojiStatusCustomEmojiId() const noexcept override;
            const std::string& getBio() const noexcept override;
            const std::string& getDescription() const noexcept override;
            const std::string& getInviteLink() const noexcept override;

         private:
            const TgBot::Chat::Ptr _chat_ptr;
      };


      /// Implement telegram message object for TgBot library.
      class MessageTgBot: public IMessage {
         public:
            MessageTgBot();
            MessageTgBot( TgBot::Message::Ptr message_ptr ):
               _message_ptr( message_ptr ),
               _from( std::make_unique<const UserTgBot>( _message_ptr->from ) ),
               _senderChat( std::make_unique<const ChatTgBot>( _message_ptr->senderChat ) ),
               _chat( std::make_unique<const ChatTgBot>( _message_ptr->chat ) )
            {
            };

            const std::int32_t getMessageId() const noexcept override;
            const std::int32_t getMessageThreadId() const noexcept override;
            const IUser::CPtr& getFrom() const noexcept override;
            const IChat::CPtr& getSenderChat() const noexcept override;
            const std::int32_t getDate() const noexcept override;
            const IChat::CPtr& getChat() const noexcept override;
            const std::string& getText() const noexcept override;

         private:
            const TgBot::Message::Ptr _message_ptr;
            const IUser::CPtr _from;
            const IChat::CPtr _senderChat;
            const IChat::CPtr _chat;
      };


      /// Implement telegram bot object for TgBot library.
      class TelegramBotTgBot: public ITelegramBot {
         public:
            TelegramBotTgBot() {};
            void initialize(const std::string &token) override;

            void start() override;
            void sendMessage( const IChat::CPtr& chat, const std::string& message ) override;
            const IUser::CPtr getMe() override;

         private:
            std::unique_ptr<TgBot::Bot> _bot;
      };

   }
}

#endif // TELEGRAM_BOT_TG_BOT_HPP
