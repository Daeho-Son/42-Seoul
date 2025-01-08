func_run_test()
{
	output=$(eval "$1")
	expected_output=$2

	echo "[TEST] $1"
	echo -n "Result: "
	if [[ "$expected_output" == "$output" ]]; then
		echo "OK"
	else
		echo "KO"
	fi
	echo ""
}

echo "========== TEST ex02 =========="

# Test Case 1
case1_command="python tester.py | cat -e"
case1_expected_output="List : <class 'list'>$
Tuple : <class 'tuple'>$
Set : <class 'set'>$
Dict : <class 'dict'>$
Brian is in the kitchen : <class 'str'>$
Toto is in the kitchen : <class 'str'>$
Type not found$
42$"

func_run_test "$case1_command" "$case1_expected_output"


# Test Case 2
case2_command="python find_ft_type.py | cat -e"
case2_expected_output=""

func_run_test "$case2_command" "$case2_expected_output"
