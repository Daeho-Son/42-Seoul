#!/bin/bash

##
# test.sh
##

trap "
echo 'SIGINT'
exit" SIGINT

CHECK_OS="`uname -s`"
SHELL_DIR=${PWD##*/}
DIR="../"

clear
gcc random.c -o random
make fclean -C $DIR
make re -C $DIR
CHECK_MAKE=`find ../ -maxdepth 1 -name "push_swap"`
if [[ "$CHECK_MAKE" = "" ]]; then
	clear
	echo -e "\033[43;31mgcc Error\033[0m"
	exit
fi

clear
while :
do
	echo -n "Number of Parameters: "
	read NUM
	CHECK_NUM=${NUM//[0-9]/}
	if [[ -n "$CHECK_NUM" ]] ; then
		clear
		echo -e "\033[43;31mPlease enter number!!\033[0m"
	else
		if [[ "$NUM" = "" ]]; then
			NUM=5
		fi
		MIN=100000000
		MAX=-1
		SUM=0
		for i in {1..1000}
		do
			clear
			echo -e "# Case $i\n"
			./random `expr $NUM + 1` > ./random.txt
			INPUT=`cat random.txt`
			echo -e "Input Number:  $INPUT\n"
			$DIR/push_swap $INPUT > result.txt
			RESULT=`cat result.txt`
			if [[ "$RESULT" = "" ]]; then
				$DIR/push_swap $INPUT 2> error.log
			else
				COUNT=`wc -l < result.txt`
				echo -n "OS: "
				if [[ "$CHECK_OS" = "Linux"* ]]; then
					echo "Linux"
					STATUS=`./checker_linux $INPUT < result.txt`
				else
					echo "Mac"
					STATUS=`./checker_Mac $INPUT < result.txt`
				fi
				echo -n "Status: "
				if [[ "$STATUS" = "KO" ]]; then
					echo "KO"
					echo "$INPUT" > ./input.txt
					rm random
					rm random.txt
					exit
				elif [[ "$STATUS" = "Error" ]]; then
					echo "Error"
					echo "$INPUT" > ./input.txt
					rm random
					rm random.txt
					exit
				else
					echo "OK"
					SUM=`expr $SUM + $COUNT`
					if [ ${COUNT} -lt ${MIN} ]; then
						MIN=$COUNT
					fi
					if [ ${MAX} -lt ${COUNT} ]; then
						MAX=$COUNT
						echo "$INPUT" > max_input.txt
					fi
					AVG=`expr $SUM / $i`
					echo "MIN:$MIN"
					echo "AVG:	$AVG"
					echo "MAX:$MAX"
				fi
			fi
			sleep 1
		done
		rm random
		rm random.txt
		exit
	fi
done
