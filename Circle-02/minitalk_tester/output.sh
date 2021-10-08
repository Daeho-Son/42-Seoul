#!/bin/bash

##
# out_put.sh
##

DIR="../"

gcc random.c -o random
echo "\033[31m./random $1 > test.txt\033[0m"
./random $1 > test.txt

clear
${DIR}server &
SERVER_PID=`ps | grep "server" | grep -v "grep\|server.c" | awk '{print $1}'`
StartTime=$(date +%s)
${DIR}client $SERVER_PID "`cat test.txt`"
EndTime=$(date +%s)
echo -e "\n$(($EndTime - $StartTime))s"
rm random
kill -9 $SERVER_PID
