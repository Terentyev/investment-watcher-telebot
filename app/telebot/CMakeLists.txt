cmake_minimum_required(VERSION 3.13)
project(telebot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set(Boost_USE_MULTITHREADED ON)

set(SOURCE_FILES 
	src/telebot.cpp
	src/Application.cpp
	src/Application/Base.cpp
	src/Config.cpp
	src/Config/Environment.cpp
	src/Logger.cpp
	src/Logger/IOStream.cpp
	src/Storage.cpp
	src/Storage/ODB.cpp
	src/TelegramBot.cpp
	src/TelegramBot/TgBot.cpp
	/home/u/project/lib/tg_detail-odb.cxx
	/home/u/project/lib/user-odb.cxx)

add_executable(telebot ${SOURCE_FILES})

target_include_directories(telebot PRIVATE include)
target_include_directories(telebot PRIVATE /home/u/project/include)
target_include_directories(telebot PRIVATE /home/u/build/vcpkg_installed/x64-linux/include)

# tgbot-cpp
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
target_link_libraries(telebot PRIVATE /home/u/build/vcpkg_installed/x64-linux/lib/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})
# sqlite3
find_package(unofficial-sqlite3 REQUIRED)
target_link_libraries(telebot PRIVATE unofficial::sqlite3::sqlite3)
# ODB
find_package(odb CONFIG REQUIRED COMPONENTS sqlite libodb)
target_link_libraries(telebot PRIVATE odb::libodb odb::libodb-sqlite)

include_directories(/home/u/build/vcpkg_installed/x64-linux/include/ ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()
