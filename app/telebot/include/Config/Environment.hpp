#ifndef CONFIG_ENVIRONMENT_HPP

#define CONFIG_ENVIRONMENT_HPP

// application
#include "Config.hpp"


namespace Telebot {
   namespace Config {
      
      /**
       * Implement configuration object that extract values from environment
       * variables.
       */
      class Environment: public IConfig {
         const std::string getValue(const std::string &name) override;
      };

   }
}

#endif // CONFIG_ENVIRONMENT_HPP
