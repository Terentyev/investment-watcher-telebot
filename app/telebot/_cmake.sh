#!/bin/bash

BASE_PATH='/home/u'
PROJECT_PATH="$BASE_PATH/project"
BUILD_PATH="$BASE_PATH/build"
SOURCE_PATH="$PROJECT_PATH/telebot"
TOOLS_PATH="$BASE_PATH/tools"
VCPKG_PATH="$TOOLS_PATH/vcpkg"


if [[ "`pwd`" != "$SOURCE_PATH" ]] ; then
	echo "Should be run at '$SOURCE_PATH'!"
	exit 1
fi

"$VCPKG_PATH/vcpkg" install || exit 1

CXXFLAGS=--std=c++14 cmake -B "$BUILD_PATH" -S "$SOURCE_PATH" -DCMAKE_TOOLCHAIN_FILE="$VCPKG_PATH/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES || exit 1

make -C "$BUILD_PATH" && ctest --test-dir "$BUILD_PATH" || exit 1

