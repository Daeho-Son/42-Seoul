source ../run_test.sh

# ft_filter.__doc__ Test
echo "========= TEST ft_filter.__doc ========="
echo "Result: " $(python doc_tester.py)
echo "--------------------"


# TEST CASE 1
case1_command="python filterstring.py 'Hello the World' 4"
case1_expected="['Hello', 'World']"

func_run_test "$case1_command" "$case1_expected"


# TEST CASE 2
case2_command="python filterstring.py 'Hello the World' 99"
case2_expected="[]"

func_run_test "$case2_command" "$case2_expected"


# TEST CASE 3
case3_command="python filterstring.py 3 'Hello the World'"
case3_expected="AssertionError: the arguments are bad"

func_run_test "$case3_command" "$case3_expected"


# TEST CASE 4
case4_command="python filterstring.py"
case4_expected="AssertionError: the arguments are bad"

func_run_test "$case4_command" "$case4_expected"