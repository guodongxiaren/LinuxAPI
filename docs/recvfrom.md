##函数原型
```c
#include <sys/socket.h>

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen);
```
##描述
recvfrom()的前面四个参数同[[recv()|recv]]，对于简单的数据报C/S例子，flags字段总为0。   

参数src_addr和addrlen类似[[accept()|accept]]的最后两个参数：  
在**函数返回**时，它们给出套接字的地址以告知是谁发送的数据报。如果对这一信息不感兴趣，可以指定成空指针。
##返回值
同recv()，表示实际读的字节数。失败的时候返回-1，并设置errno