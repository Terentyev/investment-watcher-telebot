#!/bin/bash

APP_INCLUDE='./app/include'
APP_LIB='./app/lib'
ODB_PATH='./odb'


for DIR in "$APP_INCLUDE" "$APP_LIB" "$ODB_PATH" ; do
	if [ ! -d "$DIR" ] ; then
		echo 'Could not find one of necessary directory' "$DIR" '. Be sure you start script from root directory of project.' >&2
		exit 1
	fi
done

echo "Coping from '$APP_INCLUDE' to '$ODB_PATH' header files..."
cp -v "$APP_INCLUDE/"*.hpp "$ODB_PATH/" || exit 1

echo "Generate ODB-schema..."
docker compose exec -itu u odb find . -iname '*.hpp' -exec odb -x -std=c++14 -d sqlite --generate-query --generate-schema {} \+ || exit 1

echo "Moving from '$ODB_PATH' to '$APP_LIB' CPP-files..."
mv -v "$ODB_PATH"/*.cxx "$APP_LIB/" || exit 1

echo "Moving from '$ODB_PATH' to '$APP_INCLUDE' header files..."
mv -v "$ODB_PATH"/*.{h,i}xx "$APP_INCLUDE/" || exit 1

echo "Removing from '$ODB_PATH' useless header files..."
rm "$ODB_PATH"/*.hpp || exit 1
