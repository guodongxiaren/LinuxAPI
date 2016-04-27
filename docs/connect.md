客户端函数。属于进程到内核的传递套接字地址结构的函数。
##函数原型
```c
#include <sys/types.h>  /* POSIX.1-2001以及Linux都不需要包含此头文件 */
#include <sys/socket.h>

int connect(int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen);
```
##参数
- sockfd必须是套接字描述符
- addr是要连接的远程套接字的地址，依据通信域的不同而不同（使用的时候需要进行类型转换）:

|通信域|addr|
|----|-----
|AF_UNIX|sockaddr_un
|AF_INET|sockaddr_in
|AF_INET6|sockaddr_in6
- addrlen为套接字地址结构的长度，属于**值参数**。POSIX建议socklen_t定义为uint32_t。  

##返回值
成功返回0，失败返回-1，并设置errno。可能的错误条件有：

|errno|描述
|-----|----
|EBADD|参数socket不是合法的套接字描数字
|EALREADY|已经有一悬挂的连接正在被处理
|ETIMEDOUT|建立连接的时间限已过而未能建立连接
|ECONNREFUSED|服务端拒绝此连接
|EINTR|建立连接的企图被捕获的信号所中断


>　　正常情况下，当连接不能立即建立时，connect()等待知道服务程序回答了连接请求，或等待时间超过了某个时间限制之后才返回。
如果是超时返回，**connect()**将失败并且流产（abort）连接请求。如果**connert()**在阻塞期间由于收到信号而被中断，它将失败并置**errno**为**EINTER**，但是连接请求不会流产，而是异步地被建立。  
　　可以对套接字socket设置非阻塞方式，从而使connect()不等待回答就直接返回。对套接字设置非阻塞方式的方法同文件描述字一样使用fcntl()。  
　　如果对套接字socket设置了非阻塞标志**O_NONBLOCK**，当连接不能立即建立时，**connect()**将失败并置errno为**EINPROGRESS**，但是连接请求不会被流产而是被异步地建立。在连接建立之前，后继对同一套接字调用connect()将导致EALREADY而失败。  
　　对于异步建立的连接，可用**select()**和**poll()**来指出套接字就绪。  
　　客户进程调用**connect()**之前不必调用**bind()**，内核在必要时会为该套接字选择适当的地址。
>>引用自《Unix/Linux程序设计教程》（赵克佳、沈志宇编）P380  