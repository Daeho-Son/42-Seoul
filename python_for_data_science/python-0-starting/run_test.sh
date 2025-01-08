func_run_test()
{
	command=$1
	expected=$2
	output=$(eval "$command")

	echo "RUN COMMAND: $command"
	echo -e "<OUTPUT>\n$output"
	echo -e "<EXPECTED>\n$expected"
	echo -n "Result: "
	if [[ "$expected" == "$output" ]]; then
		echo "OK"
	else
		echo "KO"
	fi
	echo "--------------------"
}