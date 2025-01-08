source ../run_test.sh

echo "========== TEST ex05 =========="

# TEST CASE 1 - 2개 이상의 프로그램 인수를 입력한 경우, [AssertionError]를 출력한다.
case1_command="python building.py arg1 arg2"
case1_expected="[AssertionError] Please enter no more than one argument."

func_run_test "$case1_command" "$case1_expected"


# TEST CASE 2 - 1개의 프로그램 인수를 입력한 경우, 입력 받은 문자열의 정보를 출력한다.
case2_command='python building.py "Python 3.0, released in 2008, was a major revision that is not completely backward-compatible with earlier versions. Python 2 was discontinued with version 2.7.18 in 2020."'
case2_expected="The text contains 171 characters:
2 upper letters
121 lower letters
8 punctuation marks
25 spaces
15 digits"

func_run_test "$case2_command" "$case2_expected"


# TEST CASE 2 - 프로그램 인수를 입력하지 않은 경우, 문자열을 입력 받고 그 문자열의 정보를 출력한다.
case3_command='echo "Hello World!" | python building.py'
case3_expected="The text contains 13 characters:
2 upper letters
8 lower letters
1 punctuation marks
2 spaces
0 digits"

func_run_test "$case3_command" "$case3_expected"