set(SOURCE_FILES
	${CMAKE_CURRENT_LIST_PATH}../src/Config.cpp
	${CMAKE_CURRENT_LIST_DIR}/../src/Config/Environment.cpp
	Config/Environment.cpp)

add_executable(tests ${SOURCE_FILES})

target_include_directories(tests PRIVATE include)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../include)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../build/vcpkg_installed/x64-linux/include)

# GTest
find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)


include(GoogleTest)
gtest_discover_tests(tests)
