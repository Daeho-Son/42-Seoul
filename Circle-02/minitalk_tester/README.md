# 파일 경로

> ./minitalk
> - Makefile
> - minitalk_tester


# 실행 방법

0. cd minitalk_tester

1. ./test.sh (output.txt는 한번만 테스트)

2. 테스트하고 싶은 문자열 길이 입력
> ex)
> 
> Test count: 1000
>
> 길이가 1000인 문자열 생성 후, 테스트

# 주의

- ft_printf로 출력을 했을 경우 테스트가 작동하지 않을 수 있음. (write로 출력)

- 가끔 가다가 오작동할 수도 있음... (# output에 아무것도 출력이 안된다거나) 다시 시도하면 됨

- 테스트 파일과 비교를 하므로 결과에 다른 문자를 붙인다면 작동하지 않음
> ex)
> 
> 출력하고 싶은 문자열이 Hello World!일 경우, 실행 결과에 Hello World! 외의 문자가 있으면 안됨
>
> Result: Hello World! (x) => Result: 가 붙으면 안됨.
> 
> Hello World! (o)
