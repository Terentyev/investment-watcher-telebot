#ifndef SCHEMA_USER_HPP
#define SCHEMA_USER_HPP

#include <odb/core.hxx>
#include <odb/tr1/memory.hxx>

#pragma db object table("users")
class user
{
   public:
      user()
   {
   }

   private:
      friend class odb::access;

#pragma db id type("INTEGER") column("id")
      unsigned long id_;
};

#endif // SCHEMA_USER_HPP
