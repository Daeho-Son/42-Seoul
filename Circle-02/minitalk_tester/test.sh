#!/bin/bash

##
# test.sh
##

CHECK_OS=`uname -s`
DIR="../"

clear
make re -C $DIR
MAKE_SERVER=`find $DIR -maxdepth 1 -name "server"`
MAKE_CLIENT=`find $DIR -maxdepth 1 -name "client"`
if [ -z "$MAKE_SERVER" ] || [ -z "$MAKE_CLIENT" ]; then
        echo -e "\033[43;31mGCC ERROR\033[0m"
        exit
fi

clear
echo -n "Test count: "
read COUNT
for i in {1..1000}
do
	./output.sh $COUNT > test1.txt
	tail -2 test1.txt > test2.txt
	head -1 test2.txt > output.txt
	TIME=`tail -1 test2.txt`
	clear
	echo -e "<No.$i>\n"
	TEST=`cat test.txt`
	OUTPUT=`cat output.txt`
	echo -e "\033[31m# Test case\033[0m\n${TEST}\n"
	echo -e "\033[31m# Output\033[0m\n${OUTPUT}\n"
	if [[ "$TEST" = "$OUTPUT" ]]; then
		echo -e "\033[31mTime: ${TIME}\033[0m"
		echo -e "\033[31mResult: OK\033[0m"
	else
		echo -e "\033[31m# Diff\033[0m"
		declare -a arr_t
		for ((i=0; i<${#TEST}; i++)); do arr_t[$i]="${TEST:$i:1}"; done
		declare -a arr_o
		for ((i=0; i<${#OUTPUT}; i++)); do arr_o[$i]="${OUTPUT:$i:1}"; done
		for ((i=0; i<${#TEST}; i++))
		do
			if [[ "${arr_t[$i]}" = "${arr_o[$i]}" ]]; then
				echo -n "${arr_t[$i]}"
			else
				echo -en "\033[31m${arr_t[$i]}\033[0m"
			fi
		done
		echo -e "\n\n\033[43;31mResult: KO!!!\033[0m"
		exit
	fi
	sleep 1;
done
