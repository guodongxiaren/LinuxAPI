##函数原型
```c
#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, ... /* arg */ );
```
##参数
参数可能有两个，也可能有三个，具体看第二个参数的取值。
- fd： 文件描述符
- cmd： 命令
- arg： 命令的参数

|常用cmd|arg|描述|
|---|---|---
|F_DUPFD||复制文件描述符
|F_GETFD|无|获取文件描述符标签
|F_SETFD||设置文件描述符标签
|F_GETFL||获取文件状态标签
|F_SETFL||设置文件状态标签
|F_GETFLK||获取文件锁
|F_SETFLK||设置文件锁
|F_SETLKW||类似**F_SETLK**，但等待完成
|F_GETOWN||获取收到SIGIO信号的进程或进程组ID
|F_SETOWN||设置接收SIGIO信号的进程或进程组ID

##文件描述符标签
- 文件描述符标签（flags）是一个整型，它的每一个二进制为，表明一种标志。  
- 复制的文件描述符，标签不会被复制，每个文件描述符有各自的标签

当前，只有一个标志**FD_CLOEXEC**，表明当执行exec()函数时，将关闭该文件描述符。默认情况下，此位是清除的，所以在执行exec()之后，之前的文件描述符会保留。  
```c
fcntf(fd,F_SETFD,FD_CLOEXEC);//设置该标志，但是其他标志就消失了。
//良好的写法是：
int oldflags = fcntl(fd,F_GETFD);
oldflags |= FD_CLOEXEC;//设置该标志
fcntl(fd,F_SETFD,oldflags);

//如果要清除该标志
oldflags &= ~FD_CLOEXEC;
```
##文件状态标签
文件状态标签被所有复制的文件描述符共享。表明文件打开的属性，也就是open()的flags参数所指明的。  
当判断一个文件的读写标志时，不能简单的通过**&**操作来判断，因为文件的读写标志有三种状态，系统中并非设置了三个独立位来表示，实际上是用了两个位来表示的。所以最好使用**O_ACCMODE**(0x3)来进行**&**操作。  
其他的标志可以直接用**&**来判断，如`flags&O_APPEND`
