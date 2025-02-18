source ../run_test.sh

echo "========== TEST ex04 =========="

# TEST CASE 1 - 숫자가 아닌 경우, AssertionError가 발생한다.
case1_command="python whatis.py Hi!"
case1_expected="AssertionError: argument is not an integer"

func_run_test "$case1_command" "$case1_expected"


# TEST CASE 2 - 매개 변수의 개수가 2개 이상인 경우, AssertionError가 발생한다.
case2_command="python whatis.py 13 5"
case2_expected="AssertionError: more than one argument is provided"

func_run_test "$case2_command" "$case2_expected"


# TEST CASE 3 - 매개 변수가 없는 경우, 아무것도 출력되지 않는다.
case3_command="python whatis.py"
case3_expected=""

func_run_test "$case3_command" "$case3_expected"


# TEST CASE 4 - 매개 변수가 14인 경우, `I'm Even.`을 출력한다.
case4_command="python whatis.py 14"
case4_expected="I'm Even."

func_run_test "$case4_command" "$case4_expected"


# TEST CASE 5 - 매개 변수가 -5인 경우, `I'm Odd.`를 출력한다.
case5_command="python whatis.py -5"
case5_expected="I'm Odd."

func_run_test "$case5_command" "$case5_expected"


# TEST CASE 6 - 매개 변수가 0인 경우, `I'm Even.`을 출력한다.
case6_command="python whatis.py 0"
case6_expected="I'm Even."

func_run_test "$case6_command" "$case6_expected"


# TEST CASE 7 - 숫자가 아닌 경우, AssertionError가 발생한다.
case7_command="python whatis.py 111s443"
case7_expected="AssertionError: argument is not an integer"

func_run_test "$case7_command" "$case7_expected"