创建一个管道，Linux系统中有pipe()和pipe2()两个函数。
>Linux仅支持半双工管道

pipe
----
###函数原型
```c
#include <unistd.h>

int pipe(int pipefd[2]);
```
###参数
    pipefd[0]  读端
    pipefd[1]  写端
 
###返回值
    0  成功
    -1 失败，并自动设置 errno
----
----
pipe2
----
pipe2非POSIX标准，仅被Linux支持
###函数原型
```c
#include <unistd.h>
#include <fcntl.h>
#define _GNU_SOURCE

int pipe2(int pipefd[2],int flags);
```

