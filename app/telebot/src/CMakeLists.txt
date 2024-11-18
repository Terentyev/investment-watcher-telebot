set(SOURCE_FILES
	telebot.cpp
	Application.cpp
	Application/Base.cpp
	Config.cpp
	Config/Environment.cpp
	Logger.cpp
	Logger/IOStream.cpp
	Storage.cpp
	Storage/ODB.cpp
	TelegramBot.cpp
	TelegramBot/TgBot.cpp
	${CMAKE_CURRENT_LIST_DIR}/../../lib/tg_detail-odb.cxx
	${CMAKE_CURRENT_LIST_DIR}/../../lib/user-odb.cxx)

add_executable(telebot ${SOURCE_FILES})

target_include_directories(telebot PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include)
target_include_directories(telebot PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_include_directories(telebot PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/../../../build/vcpkg_installed/x64-linux/include)

# curl
include_directories(
	{$CMAKE_CURRENT_LIST_DIR}/../../../build/vcpkg_installed/x64-linux/include/
	${OPENSSL_INCLUDE_DIR}
	${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()
# tgbot-cpp
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
target_link_libraries(telebot PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/../../../build/vcpkg_installed/x64-linux/lib/libTgBot.a
	${CMAKE_THREAD_LIBS_INIT}
	${OPENSSL_LIBRARIES}
	${Boost_LIBRARIES}
	${CURL_LIBRARIES})
# sqlite3
find_package(unofficial-sqlite3 REQUIRED)
target_link_libraries(telebot PRIVATE unofficial::sqlite3::sqlite3)
# ODB
find_package(odb CONFIG REQUIRED COMPONENTS sqlite libodb)
target_link_libraries(telebot PRIVATE odb::libodb odb::libodb-sqlite)
