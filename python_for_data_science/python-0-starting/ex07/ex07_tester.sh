source ../run_test.sh

# TEST CASE 1 - 주어진 테스트
case1_command="python sos.py \"sos\" | cat -e"
case1_expected="... --- ...$"

func_run_test "$case1_command" "$case1_expected"


# TEST CASE 2 - 허용되지 않은 특수문자
case2_command="python sos.py 'h\$llo'"
case2_expected="AssertionError: the arguments are bad"

func_run_test "$case2_command" "$case2_expected"


# TEST CASE 3 - 전부 소문자
case3_command="python sos.py 'h e l l o'"
case3_expected=".... / . / .-.. / .-.. / ---"

func_run_test "$case3_command" "$case3_expected"


# TEST CASE 4 - 전부 대문자
case4_command="python sos.py 'H E L L O'"
case4_expected=".... / . / .-.. / .-.. / ---"

func_run_test "$case4_command" "$case4_expected"