#ifndef TELEBOT_APP_HPP

#define TELEBOT_APP_HPP


// STDLIB
#include <memory>
#include <iostream>



// application
#include "Config.hpp"
#include "Logger.hpp"
#include "Storage.hpp"
#include "TelegramBot.hpp"



namespace Telebot {
   namespace Application {

      /// Define application interface.
      class IApplication {
         public:
            virtual ~IApplication() {};
            /// Initialize application state.
            virtual int initialize() noexcept = 0;
            /// Start application loop.
            virtual int start() noexcept = 0;
            /**
             * Output application usage message.
             *
             * @param[in] out_stream the reference to output stream
             */
            virtual void usage( std::ostream &out_stream ) noexcept {
            };
      };

   }
}

#endif // TELEBOT_APP_HPP
