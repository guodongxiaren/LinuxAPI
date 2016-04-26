##函数原型
```c
#include <sys/socket.h>

int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
##描述
获取本地套接字sockfd的地址（本地可以有多个套接字，所以要指定）。
##返回值
成功返回0，出错返回-1并设置errno。