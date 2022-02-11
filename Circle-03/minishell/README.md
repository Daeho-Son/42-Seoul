# Minishell - Simpler than bash

![Animation](https://user-images.githubusercontent.com/48791587/153360825-f39bef67-c126-4fda-918b-72cfc1b71931.gif)

<br>

## 개요
- Minishell은 bash의 일부 주요 기능을 구현한 shell입니다.
- command, redirection, pipe 그리고 signal은 bash와 유사합니다.

<br>

## 구현 사항
### Interpret commands
1. Builtin commands (자체 구현)
    - `echo` (with `-n`) 

    - `cd` (with `absolute` or `relative`)

    - `pwd` (without option)

    - `export` (without option)

    - `unset` (without option)

    - `env` (without option)

    - `exit` (without option)

2. non-builtin commands
    - PATH 환경변수를 활용해 실행파일을 실행합니다.

### Redirection and Pipe
1. Redirection
    - input redirection : `<`, `<<`
 
    - output redirection : `>`, `>>`

2. Pipe
    - `|`


### Signal catch
- `ctrl-C`는 새로운 줄에 새로운 프롬프트를 출력합니다

- `ctrl-D`는 쉘을 종료합니다.

- `ctrl-\`은 아무런 동작도 하지 않습니다.

### Environment variables
- `$`를 통해 환경변수 값에 접근할 수 있습니다.

- `$?`는 가장 최근에 실행한 포그라운드 파이프라인의 종료 상태를 확장합니다.

<br>

## Usage
```shell
# Installation
git clone https://github.com/JongHyun-GD/minishell.git
cd minishell

# Execute
./minishell
```

<br>

## 개발 기간
8주 (2021.10.29 ~ 2021.12.27)

<br>

## Contributors
[손대호](https://github.com/Sondho)  | `Command tokenizing`, `Environment variables`, `Non-builtin commands` <br>
[박종현](https://github.com/JongHyun-GD) |  `Builtin commands`, `Redirection and Pipe`, `Signal catch`
