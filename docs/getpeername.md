##函数原型
```c
#include <sys/socket.h>

int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
##描述
获取与本地套接字sockfd连接的远程对等套接字的地址。
##返回值
成功返回0，失败为-1并设置errno