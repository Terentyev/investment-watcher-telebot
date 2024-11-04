#ifndef LOGGER_IOSTREAM_HPP

#define LOGGER_IOSTREAM_HPP

// applicatio
#include "Logger.hpp"


namespace Telebot {
   namespace Logger {
      
      /**
       * Implement logger that send messages to standard cerr, clog, cout
       * streams.
       */
      class IOStream: public ILogger {
         public:
            IOStream() {};

            void error(const std::string &message) override;
            void debug(const std::string &message) override;
            void info(const std::string &message) override;
      };

   }
}
#endif // LOGGER_IOSTREAM_HPP
