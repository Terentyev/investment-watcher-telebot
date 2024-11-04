// application
#include "TelegramBot.hpp"


namespace Telebot {
   namespace TelegramBot {

      void ITelegramBot::ReactOnAnyMessage( const IMessage::CPtr &message ) {
         auto listener = _onAnyMessageListeners.cbegin();
         while ( 
               _onAnyMessageListeners.cend() != listener &&
               MessageProcessingStatus::Continue == (*listener)->operator() ( message )
         ) {
            ++listener;
         }
      }

      void ITelegramBot::onAnyMessage( const ITelegramBot::MessageListener &listener ) {
         _onAnyMessageListeners.push_back( std::make_unique<const MessageListener>( listener ) );
      }


   }
}
