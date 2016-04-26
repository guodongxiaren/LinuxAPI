##函数原型
```c
#include <sys/socket.h>

ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```
##参数
前三个参数和[[read|read]]相同。最后一个参数是标志。  

|flags|描述
|------|-----
|0|则等价于read
|MSG_PEEK|窥视套接字上的数据而不实际读出它们
|MSG_OOB|读带外数据
|MSG_WAITALL|函数阻塞直至接收到所请求的全部数据

flags参数由以上标志按**逻辑或**操作形成。
##相关函数
|[[send|send]]|[[write|write]]|[[read|read]]
|---------|-------|---------