复制文件描述符号
##函数原型
```c
#include <unistd.h>

int dup(int oldfd);
int dup2(int oldfd, int newfd);

```
另外还有dup3()，不常用。

##dup，dup2
- dup参数是一个文件描述符，返回一个文件描述符，值是当前未使用的最小数字，指向的位置和参数相同。
- dup2，可以自己指定要返回的文件描述的数值newfd，如果newfd是一个已经打开的文件描述符，则会将其关闭。

##dup2，fcntl
```c
dup2(fd,fd2);
//等价于
close(fd2);
fcntl(fd,F_DUPFD,fd2);
```
功能上可以等价于close()和fcntl()的组合，但是dup2是一个原子操作（关闭fd2，和复制fd不会被中断）。