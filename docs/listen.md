**listen()不允许用于无连接的套接字。**
##函数原型
```c
#include <sys/socket.h>

int listen(int socket, int backlog);
```
listen()为socket建立一个连接请求侦听队列。
##参数
###backlog
backlog指明套接字侦听队列未完成连接的数目。通常指定其值大于系统规定的最大值，这时，当侦听队列的连接请求数超过系统的限制值时，系统会自动截断backlog之值为系统最大值。在Linux2.2开始，backlog的含义变成了**已经完成连接**正等待应用程序接收的套接字队列的长度。   
如果backlog小于0，该函数会自动设置侦听队列为0。  
##返回值
成功返回0，失败返回-1并设置errno错误条件。  
