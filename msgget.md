创建消息队列。如果把消息队列看做一个文件的话，那么该函数就相当于**[open](open)**。
###函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);
```
###参数
第一个参数是key值。  
第二个参数的地位用来确定消息队列的访问权限。可以附加参数：  
* IPC_CREAT //如果key不存在，则创建*(类似open函数的O_CREAT)*
* IPC_EXCL  //如果key存在，则返回失败*(类似open函数的O_EXCL)*
* IPC_NOWAIT  //如果需要等待，则直接返回错误

比如：`msgid=msgget(key,0666|IPC_CREAT)`
###返回值
成功执行时，返回消息队列标识符。失败返回-1，errno被设为以下的某个值 
* EACCES：指定的消息队列已存在，但调用进程没有权限访问它，而且不拥有CAP_IPC_OWNER权能 
* EEXIST：key指定的消息队列已存在，而msgflg中同时指定IPC_CREAT和IPC_EXCL标志 
* ENOENT：key指定的消息队列不存在同时msgflg中不指定IPC_CREAT标志 
* ENOMEM：需要建立消息队列，但内存不足 
* ENOSPC：需要建立消息队列，但已达到系统的限制 