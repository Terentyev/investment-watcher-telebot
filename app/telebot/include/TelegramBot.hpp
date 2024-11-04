#ifndef TELEGRAM_BOT_HPP

#define TELEGRAM_BOT_HPP

// STDLIB
#include <functional>
#include <memory>
#include <string>

// BOOST
#include <boost/signals2.hpp>

// TgBot
#include <tgbot/tgbot.h>


namespace Telebot {
   namespace TelegramBot {

      /// Define interface for telegram user object.
      class IUser {
         public:
            /// Define smart unique pointer to object.
            typedef std::unique_ptr<IUser> Ptr;
            /// Define smart unique pointer to immutable object.
            typedef std::unique_ptr<const IUser> CPtr;

            virtual ~IUser() {};

            /// Return user telegram id.
            virtual const std::int64_t getId() const noexcept = 0;
            /// Return true if telegram user is a bot.
            virtual const bool getIsBot() const noexcept = 0;
            /// Return first name telegram user.
            virtual const std::string& getFirstName() const noexcept = 0;
            /// Return last name telegram user.
            virtual const std::string& getLastName() const noexcept = 0;
            /// Return username telegram user.
            virtual const std::string& getUsername() const noexcept = 0;
            /// Return language code telegram user.
            virtual const std::string& getLanguageCode() const noexcept = 0;
      };


      /// Define interface for telegram chat object.
      class IChat {
         public:
            /// Define smart unique pointer to object.
            typedef std::unique_ptr<IChat> Ptr;
            /// Define smart unique pointer to immutable object.
            typedef std::unique_ptr<const IChat> CPtr;

            virtual ~IChat() {};

            /// Return telegram chat id.
            virtual const std::int64_t getId() const noexcept = 0;
            /// Return title of telegram chat.
            virtual const std::string& getTitle() const noexcept = 0;
            /// Return username of telegram chat.
            virtual const std::string& getUsername() const noexcept = 0;
            /// Return first name of telegram chat.
            virtual const std::string& getFirstName() const noexcept = 0;
            /// Return last name of telegram chat.
            virtual const std::string& getLastName() const noexcept = 0;
            /// Return true if chat is forum.
            virtual const bool getIsForum() const noexcept = 0;
            // photo
            virtual const std::vector<std::string>& getActiveUsernames() const noexcept = 0;
            /// Return... WTF?!
            virtual const std::string& getEmojiStatusCustomEmojiId() const noexcept = 0;
            /// Return bio of telegram chat.
            virtual const std::string& getBio() const noexcept = 0;
            // hasPrivateForwards
            // hasRestrictedVoiceAndVideoMessages
            // joinToSendMessages
            // joinByRequest
            /// Return telegram chat description.
            virtual const std::string& getDescription() const noexcept = 0;
            /// Return telegram chat itvite link.
            virtual const std::string& getInviteLink() const noexcept = 0;
            // std::shared_ptr<Message> pinnedMessage
            // permissions
            // slowModeDelay
            // messageAutoDeleteTime
            // hasAggressiveAntiSpamEnabled
            // hasHiddenMembers
            // hasProtectedContent
            // stickerSetName
            // canSetStickerSet
            // linkedChatId
            // location
      };

      /// Define interface of telegram message object.
      class IMessage {
         public:
            /// Define smart unique pointer to object.
            typedef std::unique_ptr<IMessage> Ptr;
            /// Define smart unique pointer to immutable object.
            typedef std::unique_ptr<const IMessage> CPtr;

            virtual ~IMessage() {};

            /// Return telegram message id.
            virtual const std::int32_t getMessageId() const noexcept = 0;
            /// Return telegram message id in thread.
            virtual const std::int32_t getMessageThreadId() const noexcept = 0;
            //// Return reference to telegram user object -- author of current message.
            virtual const IUser::CPtr& getFrom() const noexcept = 0;
            //// Return reference to telegram user object -- author of current message.? TODO
            virtual const IChat::CPtr& getSenderChat() const noexcept = 0;
            /// Return date of message.
            virtual const std::int32_t getDate() const noexcept = 0;
            /// Return reference to telegram chat object.
            virtual const IChat::CPtr& getChat() const noexcept = 0;
            /*virtual const IUser& getForwardFrom() const noexcept = 0;
            virtual const IChat& getForwardFromChat() const noexcept = 0;
            virtual const std::int32_t getForwardFromMessageId() const noexcept = 0;
            virtual const std::string& getForwardSignature() const noexcept = 0;
            virtual const std::string& getForwardSenderName() const noexcept = 0;
            virtual const std::int32_t getForwardDate() const noexcept = 0;
            virtual const bool getIsTopicMessage() const noexcept = 0;
            virtual const bool getIsAutomaticForward() const noexcept = 0;
            virtual const IMessage& getReplyToMessage() const noexcept = 0;
            virtual const IUser& getViaBot() const noexcept = 0;
            virtual const std::int32_t getEditDate() const noexcept = 0;
            virtual bool getHasProtectedContent() const noexcept = 0;
            virtual const std::string& getMediaGroupId() const noexcept = 0;
            virtual const std::string& getAuthorSignature() const noexcept = 0;*/
            /// Return telegram message text.
            virtual const std::string& getText() const noexcept = 0;
      };


      /// Define interface for telegram bot object.
      class ITelegramBot {
         public:
            enum MessageProcessingStatus {
               Continue,
               Stop
            };
            typedef std::function<MessageProcessingStatus ( const IMessage::CPtr &message )> MessageListener;

         private:
            /// Slots, that will be called after new any message.
            std::list<std::unique_ptr<const MessageListener>> _onAnyMessageListeners;

         protected:
            void ReactOnAnyMessage( const IMessage::CPtr &message );

         public:
            virtual ~ITelegramBot() {};
            /**
             * Initialize telegram bot state.
             *
             * @param[in] token the reference to telegram bot token (ask t.me/BotFather)
             */
            virtual void initialize( const std::string &token ) = 0;
            /// Start telegram bot loop.
            virtual void start() = 0;

            /**
             * Registers listener which receives new incoming message of any kind
             *
             * @param[in] listener listener.
             */
            void onAnyMessage( const MessageListener &listener );

            /**
             * Return telegram bot info.
             */
            virtual const IUser::CPtr getMe() = 0;

            /**
             * Send message into specified telegram chat.
             *
             * @param[in] chat the reference to telegram chat object
             * @param[in] message the message that should be sent
             */
            virtual void sendMessage( const IChat::CPtr& chat, const std::string& message ) = 0;
      };

   }
}

#endif // TELEGRAM_BOT_HPP
