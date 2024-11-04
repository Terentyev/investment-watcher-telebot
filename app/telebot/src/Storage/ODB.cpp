// ODB
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

// application
#include "Storage/ODB.hpp"

#include "tg_detail.hpp"
#include "tg_detail-odb.hxx"
#include "user.hpp"
#include "user-odb.hxx"


namespace Telebot {
   namespace Storage {
      
      /// Type definitions
      /// tg_detail query type
      typedef odb::query<tg_detail> tg_detail_q;
      /// tg_detail result type
      typedef odb::result<tg_detail> tg_detail_r;
      /// user query type
      typedef odb::query<user> user_q;
      /// user result type
      typedef odb::query<user> user_r;


      //
      // ODB
      //
      void ODB::initialize( const std::string& dbci ) {
         _db = std::make_unique<odb::sqlite::database>( dbci );
      };

      void ODB::make_schema() {
         {
            odb::core::transaction t( _db->begin() );
            if ( !odb::schema_catalog::exists( *_db ) )
               odb::schema_catalog::create_schema( *_db );
            t.commit();
         }
      };

      void ODB::ensure_user_exists( const TelegramBot::IUser::CPtr& from ) {
         {
            odb::core::transaction t( _db->begin() );

            tg_detail_q exact_match_q (
                  tg_detail_q::tgid == from->getId() &&
                  tg_detail_q::username == from->getUsername() &&
                  tg_detail_q::first_name == from->getFirstName() &&
                  tg_detail_q::last_name == from->getLastName() &&
                  tg_detail_q::language_code == from->getLanguageCode() &&
                  tg_detail_q::is_bot == from->getIsBot()
                  );
            {
               std::unique_ptr<tg_detail> tgd( _db->query_one<tg_detail>( exact_match_q ) );
               if ( tgd != nullptr )
                  return;
            }

            tg_detail_q tgid_q (
                  tg_detail_q::tgid == from->getId()
                  );

            {
               std::unique_ptr<tg_detail> tgd( _db->query_one<tg_detail>( tgid_q ) );
               unsigned long int user_id;
               if ( tgd == nullptr ) {
                  user new_user;
                  user_id = _db->persist( new_user );
               }
               else {
                  user_id = tgd->user_id();
               }
               tg_detail new_tg_detail (
                     from->getId(),
                     from->getUsername(),
                     from->getFirstName(),
                     from->getLastName(),
                     from->getLanguageCode(),
                     from->getIsBot(),
                     user_id
                     );
               _db->persist (new_tg_detail);
            }

            t.commit();
         }
      };



   }
}
