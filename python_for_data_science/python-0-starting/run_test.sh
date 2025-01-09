func_run_test()
{
	command=$1
	expected=$2
	output=$(eval "$command")

	echo "Execute Command: $command"
	if [[ "$expected" == "$output" ]]; then
		echo "Result: OK"
	else
		echo -e "<OUTPUT>\n$output"
		echo -e "<EXPECTED>\n$expected"
		echo "Result: KO"
	fi
	echo "--------------------"
}