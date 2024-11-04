#ifndef STORAGE_HPP

#define STORAGE_HPP


// STDLIB
#include <memory>
#include <string>

// application
#include "TelegramBot.hpp"


namespace Telebot {
   namespace Storage {

      /// Define interface for storage.
      class IStorage {
         public:
            virtual ~IStorage() {};
            /**
             * Initialize storage state.
             *
             * @param[in] dbci the database connection info
             */
            virtual void initialize( const std::string& dbci ) = 0;
            /// Ensure database schema exists or create it.
            virtual void make_schema() = 0;
            /**
             * Ensure inapp-user exists for telegram user or create him.
             *
             * @param[in] from the reference to telegram user object
             */
            virtual void ensure_user_exists( const TelegramBot::IUser::CPtr& from ) = 0;
      };

   }
}


#endif // STORAGE_HPP
