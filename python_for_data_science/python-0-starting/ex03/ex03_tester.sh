source ../run_test.sh

echo "========== TEST ex03 =========="

# Test Case 1
case1_command="python tester.py | cat -e"
case1_expected_output="Nothing: None <class 'NoneType'>$
Cheese: nan <class 'float'>$
Zero: 0 <class 'int'>$
Empty: <class 'str'>$
Fake: False <class 'bool'>$
Type not Found$
1$"

func_run_test "$case1_command" "$case1_expected_output"


# Test Case 2
case2_command="python NULL_not_found.py | cat -e"
case2_expected_output=""

func_run_test "$case2_command" "$case2_expected_output"