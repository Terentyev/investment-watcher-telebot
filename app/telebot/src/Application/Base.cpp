// STDLIB
#include <csignal>
#include <iostream>

// BOOST
#include <boost/format.hpp>

// ODB
#include <odb/exception.hxx>

// application
#include "Application/Base.hpp"


namespace Telebot {
   namespace Application {

      int Base::initialize() noexcept {
         std::string token( _config->getValue( "TOKEN" ) );
         if ( token.empty() ) {
            _log->error( "Not defined telegram bot token" );
            usage( std::cerr );
            return 1;
         }

         _log->info( boost::format( "Token: %1%" ) % token );
         _bot->initialize( token );
         /*_bot->onCommand(
            "start",
            [this]( const Telebot::TelegramBot::IMessage::CPtr& message ) {
               this->_log->debug( boost::format( "User[%1%] send command: %2%" ) % message->getFrom()->getId() % message->getText() );
               this->_storage->ensure_user_exists( message->getFrom() );
               this->_bot->sendMessage( message->getChat(), "Hi!" );
            }
         );*/
         _bot->onAnyMessage(
            [this]( const TelegramBot::IMessage::CPtr& message ) -> TelegramBot::ITelegramBot::MessageProcessingStatus {
               this->_log->debug( boost::format( "User[%1%] wrote: %2%" ) % message->getFrom()->getId() % message->getText() );
               this->_storage->ensure_user_exists( message->getFrom() );
               if ( message->getText() == "/start" )
                  return TelegramBot::ITelegramBot::MessageProcessingStatus::Stop;

               this->_bot->sendMessage( message->getChat(), "Your message is: " + message->getText() );
               return TelegramBot::ITelegramBot::MessageProcessingStatus::Continue;
            }
         );

         std::string dbci( _config->getValue( "DBCI" ) );
         if ( dbci.empty() ) {
            this->_log->error( "Not defined database connection info" );
            usage( std::cerr );
            return 1;
         }

         _log->info( boost::format( "DBCI: %1%" ) % dbci );
         try {
            _storage->initialize( dbci );
         } catch ( const odb::exception& e) {
            _log->error( boost::format( "ODB Error: %1%" ) % e.what() );
            return 1;
         } catch ( const std::exception& e ) {
            _log->error( boost::format( "Unknown error: %1%" ) % e.what() );
            return 1;
         }

         return 0;
      };


      int Base::start() noexcept {
         try {
            _storage->make_schema();
            try {
               _log->info( boost::format( "Bot username: %1%" ) % _bot->getMe()->getUsername() );
               _bot->start();
            } catch (const std::exception &e ) {
               _log->error( boost::format( "Bot error: %1%" ) % e.what() );
               return 1;
            }
         } catch (const odb::exception &e) {
            _log->error( boost::format( "ODB Error: %1%" ) % e.what() );
            return 1;
         } catch (const std::exception &e) {
            _log->error( boost::format( "Unknown error: %1%" ) % e.what() );
            return 1;
         }
         return 0;
      };

      void Base::usage( std::ostream &out_stream ) noexcept {
         // TODO: generate help from IConfig object
         out_stream << "Usage: " << std::endl
            << _application_filename << std::endl
            << std::endl
            << "There should be defined environment variables:" << std::endl
            << "  DBCI  -- path to sqlite3-database file" << std::endl
            << "  TOKEN -- telegram bot token (ask it t.me/BotFather)" << std::endl
            << std::endl;
      };

   }
}
