##函数原型
```c
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

int socket(int domain, int type, int protocol);
```
该函数在通信域domain中创建一个类型为type、使用协议protocol的套接字。
##参数
###domain
|常用domain|描述
|:---:|----
|AF_UNIX|Unix域套接字。同**AF_LOCAL**
|AF_INET|使用IPv4协议的网络通信
|AF_INET6|使用IPv6协议的网络通信

Unix域套接字，用于同一主机上的两个进程间的通信，在同一主机上IPC的时候，它比使用TCP连接通信效率更高。POSIX将其重命名为**AF_LOCAL**以消除它对应Unix操作系统的依赖。实际是一样的。
>AF是Address Family（地址族）的缩写。另有PF（Protocol Family协议族）开头的值，并不常用。
>>POSIX规范指定socket函数的第一个参数使用PF_值，而套接字地址结构(比如sockddr_in）的地址结构使用AF_值。实际上AF_两者都在使用 

###type
|常用type|描述
|:---:|----
|SOCK_STREAM|字节流套接字（流式套接字）
|SOCK_DGRAM|数据报套接字
|SOCK_RAW|原始套接字
###protocal
通常设置为0。自动采用合理协议
###domain和type合法组合
||AF_INET|AF_INET6|AF_UNIX
|---|:---:|:---:|:---:
|**SOCK_STREAM**|TCP|TCP|yes
|**SOCK_DRAG**|UDP|UDP|yes
|**SOCK_RAW**|IPv4|IPv6|
yes表示支持这一组合，但无相应协议名
##返回值
失败返回-1，并设置errno。成功返回一个描述符（类似文件描述符）。socket()和open()一样也返回最小的未使用的描述字，因此**给定的描述符要么代表一个打开的文件，要么代表一个套接字**。

-----------
套接字可以用**close()**函数来销毁。如果只想断开套接字连接，而不销毁它，可以用**shutdown()**函数。