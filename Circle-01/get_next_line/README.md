# Prototype
```c
int		get_next_line(int fd, char **line);
```

# Parameters
1. file descriptor for reading

2. The value of what has been read

# Return value
> 1 : A line has been read
>
> 0 : EOF has been reached
>
> -1 : An error happened

# Description

- Write a function which returns a line read from a file descriptor, without the newline.