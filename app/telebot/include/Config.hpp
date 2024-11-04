#ifndef CONFIG_HPP

#define CONFIG_HPP


// STDLIB
#include <string>


namespace Telebot {
   namespace Config {

      /// Define interface for application configuration.
      class IConfig {
         public:
            virtual ~IConfig() {};
            /**
             * Return configuration value for specified name.
             *
             * @param[in] name the reference to name of configuration item
             */
            virtual const std::string getValue( const std::string &name ) = 0;
      };

   }
}

#endif // CONFIG_HPP
