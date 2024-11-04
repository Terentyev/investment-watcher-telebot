#ifndef APPLICATION_BASE_HPP

#define APPLICATION_BASE_HPP

// STDLIB
#include <memory>

// application
#include "Application.hpp"
#include "Config/Environment.hpp"
#include "Logger/IOStream.hpp"


namespace Telebot {
   namespace Application {
      
      /**
       * Implement base default application.
       */
      class Base: public IApplication {
         public:
            Base();
            Base(
               const int &argc, const char *argv[],
               std::unique_ptr<Telebot::Storage::IStorage> &&storage,
               std::unique_ptr<Telebot::TelegramBot::ITelegramBot> &&bot,
               std::unique_ptr<Telebot::Config::IConfig> &&config = std::make_unique<Telebot::Config::Environment>(),
               std::unique_ptr<Telebot::Logger::ILogger> &&log = std::make_unique<Telebot::Logger::IOStream>()
            ):
               _application_filename( argv[0] ),
               _bot( std::move( bot ) ),
               _config( std::move( config ) ),
               _log( std::move( log ) ),
               _storage( std::move( storage ) )
            {
            };

            int initialize() noexcept override;
            int start() noexcept override;
            void usage ( std::ostream &out_stream ) noexcept override;

         private:
            const std::string _application_filename;
            const std::unique_ptr<Telebot::TelegramBot::ITelegramBot> _bot;
            const std::unique_ptr<Telebot::Config::IConfig> _config;
            const std::unique_ptr<Telebot::Logger::ILogger> _log;
            const std::unique_ptr<Telebot::Storage::IStorage> _storage;
      };

   }
}

#endif // APPLICATION_BASE_HPP
