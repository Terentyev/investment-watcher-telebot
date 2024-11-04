#ifndef LOGGER_HPP

#define LOGGER_HPP

// STDLIB
#include <string>

// BOOST
#include <boost/format.hpp>


namespace Telebot {
   namespace Logger {

      /// Define interface for logger.
      class ILogger {
         public:
            virtual ~ILogger() {};
            /**
             * Output error message.
             *
             * @param[in] frmt the reference to formatted message
             */
            void error( const boost::format &frmt ) { error( frmt.str() ); };
            /**
             * Output debug message.
             *
             * @param[in] frmt the reference to formatted message
             */
            void debug( const boost::format &frmt ) { debug( frmt.str() ); };
            /**
             * Output information message.
             *
             * @param[in] frmt the reference to formatted message
             */
            void info( const boost::format &frmt ) { info( frmt.str() ); };
            /**
             * Output error message.
             *
             * @param[in] frmt the reference to message
             */
            virtual void error( const std::string& message ) = 0;
            /**
             * Output debug message.
             *
             * @param[in] frmt the reference to message
             */
            virtual void debug( const std::string& message ) = 0;
            /**
             * Output information message.
             *
             * @param[in] frmt the reference to message
             */
            virtual void info( const std::string& message ) = 0;
      };

   }
}


#endif // LOGGER_HPP
