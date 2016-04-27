##函数原型
```c
#include <sys/socket.h>

int getsockopt(int sockfd, int level, int optname,
                      void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname,
                      const void *optval, socklen_t optlen);
```
##描述
###getsockopt
获得套接字sockfd在层次level上的选项optname的值。此选项之值存放子optval所指的缓冲区中。
###setsockopt
设置套接字sockfd在层次level上的选项optname的值。选项值传递optval所指缓冲区中，optlen给出缓冲区的大小。
##SOL_SOCKET层套接字选项
|optname|描述|数据类型
|-----|---------|-----------
|SO_BROADCAST|允许发送广播数据报|int
|SO_DEBUG|打开调试追踪|int
|SO_DONTROUTE|绕过协议的路由机制|int
|SO_KEEPALIVE|周期性地测试连接是否仍建立|linger
|SO_LINGER|如果有数据要发送，是否延迟关闭|int
|SO_OOBINLINE|嵌入方式接收带外数据|int
|SO_RCVBUF|接收缓冲区大小|int
|SO_SNDBUF|发送缓冲区大小|int
|SO_RCVTIMEO|接收超时|timeval
|SO_SNDTIMEO|发送超时|timeval
|SO_TYPE|套接字类型|int
以上选项除了SO_TYPE仅适用于getsockopt函数外，其余选项两个函数都适用。
