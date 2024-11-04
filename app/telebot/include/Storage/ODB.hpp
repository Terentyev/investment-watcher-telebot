#ifndef STORAGE_ODB_HPP

#define STORAGE_ODB_HPP

// ODB
#include <odb/database.hxx>

// application
#include "Storage.hpp"


namespace Telebot {
   namespace Storage {
      
      /**
       * Implement storag based on ODB library.
       * See more information at https://www.codesynthesis.com/products/odb/
       */
      class ODB: public IStorage {
         public:
            ODB() {};

            void initialize( const std::string& dbci ) override;
            void make_schema() override;
            void ensure_user_exists( const TelegramBot::IUser::CPtr& from ) override;

         private:
            std::unique_ptr<odb::core::database> _db;
      };

   }
}


#endif // STORAGE_ODB_HPP
