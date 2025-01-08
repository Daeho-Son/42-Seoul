func_run_test()
{
	command=$1
	expected=$2
	output=$(eval "$command")

	echo "Execute Command: $command"
	echo -n "Result: "
	if [[ "$expected" == "$output" ]]; then
		echo "OK"
	else
		echo -e "<OUTPUT>\n$output"
		echo -e "<EXPECTED>\n$expected"
		echo "KO"
	fi
	echo "--------------------"
}