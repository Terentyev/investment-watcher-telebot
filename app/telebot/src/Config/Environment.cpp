// application
#include "Config/Environment.hpp"


namespace Telebot {
   namespace Config {
      
      const std::string Environment::getValue( const std::string &name ) {
         const char *value_c = getenv( name.c_str() );

         if ( !value_c )
            return "";

         return value_c;
      };

   }
}
