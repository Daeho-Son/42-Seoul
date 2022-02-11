#!/bin/bash

##
# make_test.sh
##


clear
if [ -n "$1" ]; then
	echo "./cub3d $1"
	./cub3d $1
	echo -e "\n"
fi

if [ -z $1 ]; then
	MAP_DIR="./assets/maps"
	LS=`ls $MAP_DIR`

	echo "./cub3d assets/maps/doesntexistmap.cub"
	./cub3d assets/maps/doesntexistmap.cub
	echo -e "\n"

	for TEST_FILE in $LS
	do
		echo "./cub3d $MAP_DIR/$TEST_FILE"
		./cub3d $MAP_DIR/$TEST_FILE
		echo -e "\n"
	done
fi
