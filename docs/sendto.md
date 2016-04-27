##
```c
#include <sys/socket.h>

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
              const struct sockaddr *dest_addr, socklen_t addrlen);
```
##描述
sendto()的前面四个参数同[[sendto()|sendto]]，对于简单的数据报C/S例子，flags字段总为0。   

参数src_addr和addrlen类似[[connect()|connect]]的最后两个参数：  
在**发送数据报**时，要在套接字地址结构dest_addr中填入协议地址以指明数据报发给谁。  

注意addrlen是整数，而recvfrom的最后一个参数addrlen是指向整数的指针。这个差别就是**[[值-结果参数|值-结果参数]]**
##返回值
同send()，表示实际发送的字节数。失败的时候返回-1，并设置errno