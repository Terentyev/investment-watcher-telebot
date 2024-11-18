#include <gtest/gtest.h>

#include "Config/Environment.hpp"



TEST( ConfigEnvironmentTests, TestEmptyVariables )
{
   std::unique_ptr<Telebot::Config::IConfig> config( new Telebot::Config::Environment() );

   ASSERT_EQ( config->getValue( "DBIC" ), "" );
   ASSERT_EQ( config->getValue( "TOKEN" ), "" );
}

TEST( ConfigEnvironmentTests, TestNonEmptyVariables )
{
   std::unique_ptr<Telebot::Config::IConfig> config( new Telebot::Config::Environment() );

   ASSERT_NE( config->getValue( "PATH" ), "" );
}

TEST( ConfigEnvironmentTests, TestDynamicVariables )
{
   std::unique_ptr<Telebot::Config::IConfig> config( new Telebot::Config::Environment() );
   const std::string variableName( "sa7Vu2bo" );
   const std::string variableValue( "poh3Seed" );

   ASSERT_EQ( config->getValue( variableName ), "" );

   setenv( variableName.c_str(), variableValue.c_str(), 0 );

   ASSERT_EQ( config->getValue( variableName ), variableValue );
}
