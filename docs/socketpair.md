创建一对套接字
##函数原型
```c
#include <sys/types.h>     /* 基本不用，一些特殊的type需要包含此头文件 */
#include <sys/socket.h>

int socketpair(int domain, int type, int protocol, int filedes[2]);
```
##参数
domain、type和protocol的含义同[socket](socket)函数。不过Linux的doman参数仅仅支持**AF_UNIX(AF_LOCAL)**。
protocol值常为0，允许系统使用默认协议。

-------------------
##套接字与管道
两者类似，但不同。管道生成的两个描述字（描述符）分别掌管着写（fd[0]）和读(fd[1])，而套接字偶对生成的两个描述字分别代表着父进程(fd[1])和子进程（fd[0]），可分别进行IO。  
fd[1]可以用来父进程的IO。fd[0]可以用来子进程的IO。而不是单独代表I或O。