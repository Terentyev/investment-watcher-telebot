#ifndef SCHEMA_TG_DETAIL_HPP
#define SCHEMA_TG_DETAIL_HPP

#include <cstdint>
#include <string>

#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/tr1/memory.hxx>

#pragma db object table("tg_details")
class tg_detail
{
   public:
      tg_detail() {};
      tg_detail(
            const std::int64_t& tgid,
            const std::string& username,
            const std::string& first_name,
            const std::string& last_name,
            const std::string& language_code,
            bool is_bot,
            unsigned long int user_id
            ): tgid_( tgid ), username_( username ),
               first_name_( first_name ), last_name_( last_name ),
               language_code_( language_code ), is_bot_( is_bot ),
               user_id_( user_id )
      {
      }

      const std::int64_t& tgid () const { return tgid_; };
      const std::string& username () const { return username_; };
      const std::string& first_name() const { return first_name_; };
      const std::string& last_name() const { return last_name_; };
      const std::string& language_code() const { return language_code_; };
      const bool is_bot() const { return is_bot_; };
      const unsigned long int user_id() const { return user_id_; };

   private:
      friend class odb::access;

#pragma db id type("INTEGER") column("id")
      unsigned long id_;
#pragma db type("INTEGER") column("tgid")
      std::int64_t tgid_;
#pragma db type("VARCHAR(128)") column("username")
      std::string username_;
#pragma db type("VARCHAR(128)") column("first_name")
      std::string first_name_;
#pragma db type("VARCHAR(128)") column("last_name")
      std::string last_name_;
#pragma db type("VARCHAR(8)") column("language_code")
      std::string language_code_;
#pragma db type("INTEGER") column("is_bot")
      bool is_bot_;
#pragma db type("INTEGER") column("user_id")
      unsigned long user_id_;
};


#endif // SCHEMA_TG_DETAIL_HPP
