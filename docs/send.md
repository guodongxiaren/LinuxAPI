##函数模型
```c
#include <sys/socket.h>

int send(int s, const void *msg, size_t len, int flags);
```
##参数
前面三个参数同[[write|write]]。最后一个是标志（flag）。它的取值是几个宏  

|flags|描述
|-----|-----
|MSG_OOB|导致send()发送的数据成为带外数据
|MSG_DONTROUTE|不在消息中包含路由信息

flags参数由以上标志按**逻辑或**操作形成。
##[[带外数据|带外数据]]

##相关函数
|[[recv|recv]]|[[write|write]]|[[read|read]]
|---------|-------|---------