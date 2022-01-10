# Part 1
## [memset](https://www.notion.so/memset-04aa0d186601409da02f728d06589833)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_memset.c)

> ```
> #include <string.h>
> 
> void *memset(void *ptr, int value, size_t num);
> ```

> #### 설명
> - 메모리 주소에 특정값을 채우는 함수
> - 첫번째 인자인 ptr이 가리키는 메모리 주소에 접근하여, num바이트만큼 value값으로 채워준다.
> - 이때 value값을 unsigned char로 해석한다.

> #### 반환값
> - ptr이 가르키는 주소
> 



-----


## [bzero](https://www.notion.so/bzero-e00d6683b90b4e0fadcee209d133954f)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_bzero.c)

> ```
> #include <string.h>
> 
> void bzero(void *ptr, size_t num);
> ```

> #### 설명
> - 메모리 주소에 0을 채우는 함수
> - 첫번째 인자인 ptr이 가리키는 메모리 주소에 접근하여, num바이트만큼 0으로 채워준다.

> #### 반환값
> - X



-----


## [memcpy](https://www.notion.so/memcpy-ff20c08cc9e44775836580b71505bdfd)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_.c)

> ```
> #include <string.h>
> 
> void *memcpy(void *dst, const void *src, size_t n);
> ```

> #### 설명
> - 메모리 블록을 복사하는 함수
> - src가 가리키는 메모리 주소에 접근해서, n바이트만큼 복사한 뒤 dst가 가리키는 메모리 주소에 붙여넣는다.

> #### 반환값
> - dst가 가르키는 메모리 주소값


-----


## [memccpy](https://www.notion.so/memccpy-a83f36578390427dbc7a48c646f01a7c)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_memccpy.c)

> ```
> #include <string.h>
> 
> void *memccpy(void *dst, const void *src, int c, size_t n);
> ```

> #### 설명
> - 메모리 블록을 특정 값까지만 복사하는 함수
> - src가 가리키는 메모리 주소에 접근해서 최대 n바이트만큼 복사한 뒤 dst가 가리키는 메모리 주소에 붙여넣는다.
> - n바이트 메모리 안에 c값이 저장된 메모리가 있다면, 해당 메모리까지만 복사가 이루어지고 진행을 중단
> - c값이 저장된 메모리를 찾지 못하면 끝까지 복사가 이루어 진다.

> #### 반환값
> - n바이트 메모리 안에 c값이 저장된 메모리가 있고, 그 인덱스를 i라고 한다면 dst + i + 1
> - n바이트 메모리 안에 c값이 저장된 메모리가 없다면, NULL


-----


## [memmove](https://www.notion.so/memmove-5494d80048df40f297a3f36e5d25f5e8)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_memmove.c)

> ```
> #include <string.h>
> 
> void *memmove(void *dst, const void *src, size_t num);
> ```

> #### 설명
> - 메모리 블록을 이동하는 함수
> - src가 가리키는 메모리 주소에 접근해서 num바이트만큼 복사한 뒤 dst가 가리키는 메모리 주소에 붙여넣는다.

> #### 반환값
> - dst가 가리키는 메모리 주소값


-----


## [memchr](https://www.notion.so/memchr-eea913c18a7240589e18e521fb9c79a1)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_memchr.c)

> ```
> #include <string.h>
> 
> void	*memchr(const void *ptr, int value, size_t n)
> ```

> #### 설명
> - 메모리 블록에서 특정값(unsigned char)을 찾는 함수
> - ptr이 가리키는 메모리 주소에 접근해서 num바이트 안에 value값을 가진 메모리 블럭을 찾아 그 주소를 반환
> - 비교를 위해 ptr 메모리 블록의 값을 unsigned char로 해석하여 value와 비교

> #### 반환값
> - 찾았을 경우, return (void *)(s);
> - 없을 경우, NULL


-----


## [memcmp](https://www.notion.so/memcmp-59951c35e0bd4f509f858970af757330)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_memcmp.c)

> ```
> #include <string.h>
> 
> int memcmp(const void *ptr1, const void *ptr2, size_t num);
> ```

> #### 설명
> - 두 메모리 블록을 비교하는 함수
> - ptr1과 ptr2가 가리키는 메모리 주소에 접근해서 최대 num바이트를 비교


> #### 반환값
> - 만약 두 포인터가 가리키는 메모리 블록의 값을 모두 비교했는데 num바이트까지 모두 같다면 0을 반환
> - 그렇지 않다면 처음으로 찾은 두 메모리 블록 값의 차이를 반환 


-----


## [strlen](https://www.notion.so/strlen-84f87394c0d149f6b4df8a3c97699001)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strlen.c)

> ```
> #include <string.h>
> 
> size_t strlen(const char *str);
> ```

> #### 설명
> - 문자열의 길이를 계산하는 함수

> #### 반환값
> - 문자열 str의 길이를 반환


-----


## [strlcpy](https://www.notion.so/strlcpy-strlcat-d419988e521e49bbb69baeff1a31c70f)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strlcpy.c)

> ```
> #include <string.h>
> 
> size_t strlcpy(char *dst, const char *src, size_t dstsize);
> ```

> #### 설명
> - 크기가 제한된 문자열을 복사
> - src가 가리키는 메모리 주소에 접근해서, 최대 dstsize - 1개 문자를 dst에 복사
> - 복사가 이루어지는 dst문자열은 반드시 \0문자로 끝난다.

> #### 반환값
> - 문자열 src의 길이


-----


## [strlcat](https://www.notion.so/strlcpy-strlcat-d419988e521e49bbb69baeff1a31c70f)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strlcat.c)

> ```
> #include <string.h>
> 
> size_t strlcat(char *dst, const char *src, size_t dstsize);
> ```

> #### 설명
> - 크기가 제한된 문자열을 연결하는 함수
> src가 가리키는 메모리 주소에 접근해서 dstsize - strlen(dst) - 1개의 문자를 dst의 뒤에 복사
> 복사가 이루어지는 dst문자열은 반드시 \0문자로 끝난다.

> #### 반환값
> - strlen(dst)와 dstsize중에서 작은 값 + strlen(src)
> - (strlen(dst) > dstsize) ? (dstsize + strlen(src)) : (strlen(dst) + strlen(src))


-----


## [strchr](https://www.notion.so/strchr-strrchr-1e9948872e074b32b3b93e0496ac4556)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strchr.c)

> ```
> #include <string.h>
> 
> char *strchr(const char *s, int c);
> ```

> #### 설명
> - 문자열에서 특정 문자가 처음으로 등장한 위치를 찾는 함수
> - s가 가리키는 문자열에 접근해서 c값을 가진 문자가 가장 처음으로 등장하는 주소를 반환
> - 이때 c값을 char로 해석

> #### 반환값
> - s에서 c가 가장 처음으로 등장하는 주소값
> - 없으면 NULL


-----


## [strrchr](https://www.notion.so/strchr-strrchr-1e9948872e074b32b3b93e0496ac4556)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strrchr.c)

> ```
> #include <string.h>
> 
> char *strrchr(const char *s, int c);
> ```

> #### 설명
> - 문자열에서 특정 문자가 마지막으로 등장하는 위치를 찾는 함수
> - s가 가리키는 문자열에 접근해서 c값을 가진 문자가 가장 마지막으로 등장하는 주소를 반환
> - 이때 c값을 char로 해석

> #### 반환값
> - s에서 문자 c가 가장 마지막으로 등장하는 주소값
> - 없으면 NULL


-----


## [strnstr](https://www.notion.so/strnstr-8b7d311e08cc463984e7ec2a39a7e5d6)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strnstr.c)

> ```
> #include <string.h>
> 
> char	*strnstr(const char *s1, const char *s2, size_t len)
> ```

> #### 설명
> - 문자열 내에서 부분문자열을 탐색하는 함수
> - strstr()함수는 문자열 s1 내에서 문자열 s2를 찾아서 첫번째로 나온 결과를 탐색한다. (NULL 전까지)
> - strnstr()함수는 strstr()함수와 같지만 문자열은 최대 len만큼 탐색한다.
> - 문자열들은 \0를 만나면 더 이상 찾지 않는다.

> #### 반환값
> - 문자열 s2를 찾은 문자열 중 첫 글자를 가리키는 포인터를 반환
> - 문자열 s2이 비어있을 경우, 문자열 s1을 반환
> - 문자열 s2가 문자열 s1내에 없는 경우 NULL을 반환


-----


## [strncmp](https://www.notion.so/strcmp-strncmp-f09d2e275e5c479191766349636cb8c2)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strncmp.c)

> ```
> #include <string.h>
>
> int strncmp(const char* str1, const char* str2, size_t num);
> ```

> #### 설명
> - 두 개의 문자열을 비교한다.
> - 문자열 st1의 처음 num개의 문자와 문자열 str2의 처음 num개의 문자를 비교한다.
> - 처음 문자부터 비교를 수행하되, 다른 문자가 나타가거나 NULL에 도달하거나 num을 넘어갈때까지 비교를 수행

> #### 반환값
> - 만일 num 개의 문자가 모두 일치한다면 0 을 리턴한다.
> - 비교한 num 개의 문자 중 최초로 일치하지 않는 문자의 값이 str1 이 더 큰 경우 0 보다 큰 값을, str2 가 더 큰 경우 0 보다 작은 값을 리턴한다.
> - return ((unsigned char)s1[index] - (unsigned char)s2[index]);


-----


## [atoi](https://www.notion.so/atoi-atol-atoll-5d9acdd3858f4ddb9cd0d099c1de7568)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_atoi.c)

> ```
> #include <stdlib.h>
> 
> int atoi(const char* str);
> ```

> #### 설명
> - 문자열을 정수로 변환
> - 공백문자를 무시하고 비-공백 문자부터 최대한 많은 숫자들을 수로 변환
> - 숫자의 앞부분에 +나 -가 올 수 있다.
> - 숫자들 다음에 나타나는 문자들은 모두 무시

> #### 반환값
> - 문자열을 정수로 변환한 값을 반환


-----


## [is series](https://www.notion.so/is-series-886a1deb04b84cfca223bf90d22941f9)
> #### [ft_isalpha 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_isalpha.c)
> #### [ft_isdigit 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_isdigit.c)
> #### [ft_isalnum 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_isalnum.c)
> #### [ft_isascii 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_isascii.c)
> #### [ft_isprint 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_isprint.c)


> ```
> #include <ctype.h>
>
> int ft_isalpha(int c);
> int ft_isdigit(int c);
> int ft_isalnum(int c);
> int ft_isascii(int c);
> int ft_isprint(int c);
> ```

> #### 설명
> - ft_isalpha: c가 알파벳인지 검사
> - ft_isdigit: c가 숫자인지 검사
> - ft_isalnum: c가 알파벳 혹은 숫자인지 검사
> - ft_isascii: c가 ASCII인지 검사
> - ft_isprint: c가 출력가능한 문자의 ASCII 코드 값인지 검사

> #### 반환값
> - 참이면 1
> - 거짓이면 0


-----


## [toupper, tolower](https://www.notion.so/toupper-tolower-9ba6db868ef14c1691af83ed13cd5f5b)
> #### [tosupper 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_toupper.c)
> #### [tolower 소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_tolower.c)

> ```
> #include <ctype.h>
> 
> int toupper(int c);
> int tolower(int c);
> ```

> #### 설명
> - toupper: 소문자를 대문자로 변환
> - tolower: 대문자를 소문자로 변환

> #### 반환값
> - 변화된 값을 반환


-----


## [calloc](https://www.notion.so/malloc-calloc-valloc-realloc-reallocf-ae32a840c4da452683820f41cc22d3f2)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_calloc.c)

> ```
> #include <stdlib.h>
> 
> void	*calloc(size_t count, size_t size)
> ```

> #### 설명
> - malloc은 할당된 공간의 값을은 바꾸지 않는다.
> - calloc은 할당된 공간의 값을 모두 0으로 바꾼다.
> - 배열을 할당하고 모두 0으로 초기화할 필요가 있을경우에는 calloc을 쓰면 편하다.

> #### 반환값
> - 성공하면 할당된 메모리의 포인터를 반환
> - 오류가 있는 경우 NULL


-----


## [strdup](https://www.notion.so/strdup-cacab8c4dcbe43279a3ed6c9fa9cf45e)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strdup.c)

> ```
> #include <string.h>
> 
> char *strdup(const char *s);
> ```

> #### 설명
> - 문자 s 를 복사하고 복사된 문자열을 가리키는 포인터를 반환
> - 문자를 복사할 공간을 확보하기 위해서 내부적으로 malloc(3)이 호출
> - 그러므로 strdup() 함수를 호출해서 문자열 복사를 했다면 free(3) 등을 통해서 공간이 필요없게 되었을때 커널에 되돌려주어야 한다.

> #### 반환값
> - 복사된 문자열을 가리키는 포인터를 반환


-----


# Part 2
## [ft_substr](https://www.notion.so/ft_substr-5960992978c8435fb8847bfa3cc11d61)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_substr.c)

> ```
> char *ft_substr(char const *s, unsigned int start, size_t len);
> ```

> #### 설명
> - 문자열의 특정 위치(start)부터 시작하여 특정 길이(len)만큼 문자열을 반환

> #### 반환값
> - malloc(3)을 할당하고 문자열 's'에서 substring을 반환


-----


## [ft_strjoin](https://www.notion.so/ft_strjoin-d04b1049e2e444609cb419d19eb6f61a)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strjoin.c)

> ```
> char *ft_strjoin(char const *s1, char const *s2);
> ```

> #### 설명
> - 문자열 s1과 문자열 s2를 연결시켜 반환

> #### 반환값
> - malloc(3)을 할당하고 's1'과 's2'를 연결한 결과인 새 문자열을 반환


-----


## [ft_strtrim](https://www.notion.so/ft_strtrim-4266d595855842d7a52ea61463102be5)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strtrim.c)

> ```
> char *ft_strtrim(char const *s1, char const *set);
> ```

> #### 설명
> - 문자열 좌/우 공백 제거

> #### 반환값
> - malloc(3)를 할당하고 문자열의 시작과 끝 부분에서 'set'에 지정된 문자가 제거된 's1'의 복사본을 반환


-----


## [ft_split](https://www.notion.so/ft_split-0bdf1df337db4de5848d411643cc1ce0)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_split.c)

> ```
> char **ft_split(char const *s, char c);
> ```

> #### 설명
> - 문자열을 특정 문자(c)를 기준으로 나눠서 배열에 담은 뒤 반환
> - 배열은 NULL 포인터로 끝나야함

> #### 반환값
> - malloc(3)를 할당하고 'c' 문자를 구분 기호로 사용하여 's'를 분할하여 얻은 문자열 배열을 반환



-----


## [ft_itoa](https://www.notion.so/ft_itoa-50052d0fbd25454cb4ba72424094dc86)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_itoa.c)

> ```
> char *ft_itoa(int n);
> ```

> #### 설명
> - 정수를 문자로 바꿔주는 함수
> - atoi와 반대


> #### 반환값
> - malloc(3)를 사용하여 할당하고 인수로 수신된 정수를 나타내는 문자열을 반환
> - 음수를 처리해야함



-----


## [ft_strmapi](https://www.notion.so/ft_strmapi-e8a7a37b8df0408689890e6cb1eb18e7)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_strmapi.c)

> ```
> char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
> ```

> #### 설명
> - 문자열 's'의 각 문자에 'f' 기능을 적용하여 'f'의 연속적인 적용으로 인해 발생하는 새 문자열(malloc(3))을 생성

> #### 반환값
> - f함수를 통해 변환된 새로운 문자열
> - 할당이 실패할 경우 NULL


-----


## [ft_putchar_fd](https://www.notion.so/ft_putchar_fd-3fa96b7daf7a47b7bbe9067566aa75b5)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_putchar_fd.c)

> ```
> void ft_putchar_fd(char c, int fd);
> ```

> #### 설명
> - 지정된 파일 설명자(fd)로 문자 'c'를 출력합니다.

> #### 반환값
> - X


-----


## [ft_putstr_fd](https://www.notion.so/ft_putstr_fd-3e6f43160a024fadaf1ff4b590152a8b)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_putstr_fd.c)

> ```
> void ft_putstr_fd(char *s, int fd);
> ```

> #### 설명
> - 주어진 파일 설명자로 문자열 's'를 출력합니다.

> #### 반환값
> - X


-----


## [ft_putendl_fd](https://www.notion.so/ft_putendl_fd-ba8cb27e9a8440ac85fb49cc1a5c48cc)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_putendl_fd.c)

> ```
> void ft_putendl_fd(char *s, int fd);
> ```

> #### 설명
> - 지정된 파일 설명자로 문자열 's'를 출력한 다음 새 줄을 출력

> #### 반환값
> - X


-----


## [ft_putnbr_fd](https://www.notion.so/ft_putnbr_fd-bf8cc69869c5489cb6e07e13a83dcad8)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_putnbr_fd.c)

> ```
> void ft_putnbr_fd(int n, int fd);
> ```

> #### 설명
> - 정수 'n'을 지정된 파일 설명자로 출력

> #### 반환값
> - X


-----


# Bonus
## [ft_lstnew](https://www.notion.so/ft_lstnew-f6a73d58d4834b9184db5941f80ebec1)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstnew.c)

> ```
> t_list *ft_lstnew(void *content);
> ```

> #### 설명
> - (malloc을 사용하여) 새 요소를 할당
> - 변수 'content'가 매개 변수 'content' 값으로 초기화됩니다.
> - '다음' 변수가 NULL로 초기화됩니다.

> #### 반환값
> - 새로 생성한 노드를 반환


-----


## [ft_lstadd_front](https://www.notion.so/ft_lstadd_front-241215d8da324582b390d221b44df1ff)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstadd_front.c)

> ```
> void ft_lstadd_front(t_list **lst, t_list *new);
> ```

> #### 설명
> - list의 시작 부분에 'new'노드를 추가

> #### 반환값
> - X


-----


## [ft_lstsize](https://www.notion.so/ft_lstsize-c39634edc6384dab9b123c338d834d8d)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstsize.c)

> ```
> int ft_lstsize(t_list *lst);
> ```

> #### 설명
> - list의 노드의 개수를 세는 함수

> #### 반환값
> - list 길이


-----


## [ft_lstlast](https://www.notion.so/ft_lstlast-4ae8cfe88dcc44759aea3847c0a766c8)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstlast.c)

> ```
> t_list *ft_lstlast(t_list *lst);
> ```

> #### 설명
> - t_list *ft_lstlast(t_list *lst);

> #### 반환값
> - list의 마지막 요소


-----


## [ft_lstadd_back](https://www.notion.so/ft_lstadd_back-30ace558e57f4c0a81905aff611bc31d)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstadd_back.c)

> ```
> void ft_lstadd_back(t_list **lst, t_list *new);
> ```

> #### 설명
> - list 끝에 'new'노드를 추가

> #### 반환값
> - X


-----


## [ft_lstdelone](https://www.notion.so/ft_lstdelone-6499a8622e334a8c9288e9baac69a8da)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstdelone.c)

> ```
> void ft_lstdelone(t_list *lst, void (*del)(void *));
> ```

> #### 설명
> - 매개변수로 주어진 함수 'del'을 사용하여 노드의 메모리를 해제하고 노드를 해제
> - 'next'의 메모리를 확보하면 안됨

> #### 반환값
> - X


-----


## [ft_lstclear](https://www.notion.so/ft_lstclear-da749412b78b4220b87d077e702e621d)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstclear.c)

> ```
> void ft_lstclear(t_list **lst, void (*del)(void *));
> ```

> #### 설명
> - 'del' 및 free(3) 함수를 사용하여 지정된 노드와 해당 노드의 모든 후속 항목을 삭제하고 해제
> - 마지막으로 list의 포인터를 NULL로 설정해야 합니다.
> 
> #### 반환값
> - X


-----


## [ft_lstiter](https://www.notion.so/ft_lstiter-7b671eb9585c4ce1b0073f1fcd6c7b7e)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstiter.c)

> ```
> void ft_lstiter(t_list *lst, void (*f)(void *));
> ```

> #### 설명
> - 'lst' 목록을 반복하고 각 요소의 내용에 'f' 함수를 적용

> #### 반환값
> - X


-----


## [ft_lstmap](https://www.notion.so/ft_lstmap-4ba756dd95c04f2b8cd3b477aa4daacd)
> #### [소스 코드](https://github.com/Sondho/libft/blob/master/src/ft_lstmap.c)

> ```
> t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
> ```

> #### 설명
> - 'lst' 목록을 반복하고 각 요소의 내용에 'f' 함수를 적용
> - 'f' 함수의 연속 응용 프로그램의 결과로 새 목록을 생성
> - 'del' 함수는 필요한 경우 요소의 내용을 삭제하는 데 사용. ex) 할당에 실패할 경우

> #### 반환값
> - 새로운 list
> - 할당이 실패하면 NULL입니다.


-----

