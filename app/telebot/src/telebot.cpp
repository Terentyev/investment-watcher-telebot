// application
#include "Application/Base.hpp"
#include "Config/Environment.hpp"
#include "Storage/ODB.hpp"
#include "TelegramBot/TgBot.hpp"


int main (int argc, const char *argv[]) {
   std::unique_ptr<Telebot::Application::IApplication> app = std::make_unique<Telebot::Application::Base>(
      argc, argv,
      std::make_unique<Telebot::Storage::ODB>(),
      std::make_unique<Telebot::TelegramBot::TelegramBotTgBot>()
   );
   return app->initialize() || app->start();
}
