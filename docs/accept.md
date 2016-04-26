##函数原型
```c
#include <sys/types.h>
#include <sys/socket.h>

int accept(int socket, struct sockaddr *cliaddr, socklen_t *addrlen);
```
##描述
accept()用于接收子服务套接字socket上的连接请求。在有客户进程企图与socket连接时，它创建一个新套接字与这个客户通信，并返回新套接字的描数字。新套接字与套接字socket的类型和通信域均相同。原来的套接字socket仍保持打开并且是未连接的，它可用来再次调用accept()接收另外的连接直到关闭为止。  
##参数
- cliaddr是出参（结果参数），返回客户端套接字的协议地址，可以置为NULL。
- addrlen是值-结果参数，必须被初始化为cliaddr所指定地址的字节数，返回其实际占用的字节数