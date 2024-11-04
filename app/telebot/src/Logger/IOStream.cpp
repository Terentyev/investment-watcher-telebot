// STDLIB
#include <iostream>

// application
#include "Logger/IOStream.hpp"


namespace Telebot {
   namespace Logger {

      void IOStream::error( const std::string &message ) {
         std::cerr << message << std::endl;
      };

      void IOStream::debug( const std::string &message ) {
         std::clog << message << std::endl;
      };

      void IOStream::info( const std::string &message ) {
         std::clog << message << std::endl;
      };

   }
}
