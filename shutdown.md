断开套接字连接
##函数原型
```c
#include <sys/socket.h>

int shutdown(int socket,int how);
```
##参数
shutdown()函数可以部分或全部断开套接字socket的连接。它可以只关闭此连接的接收或发送。具体视参数how而定。  
how取值：
- SHUT_RD:停止从此套接字接收数据
- SHUT_WR:停止从此套接字发送数据
- SHUT_RDWR:停止从该套接字接收和发送数据

