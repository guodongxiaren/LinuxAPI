##函数原型
```c
#include <sys/epoll.h>

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```
##参数
###epfd
是[[epoll_create|epoll_create]]的返回值。
###op
表示动作，它由三个宏来表示
- EPOLL_CTL_ADD：注册新的fd到epfd中；
- EPOLL_CTL_MOD：修改已经注册的fd的监听事件；
- EPOLL_CTL_DEL：从epfd中删除一个fd；

###fd
要监听的文件描述符
###event
可以是以下几个宏`逻辑或`的组合

|宏|描述
|---|----
EPOLL**IN** |表示对应的文件描述符可以读（包括对端SOCKET正常关闭）
EPOLL**OUT**|表示对应的文件描述符可以写
EPOLL**PRI**|表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）
EPOLL**ERR**|表示对应的文件描述符发生错误
EPOLL**HUP**|表示对应的文件描述符被挂断
EPOLL**ET**| 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的
EPOLL**ONESHOT**|只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里

检测event(struct epoll_event类型)是否包含某一标识
```c
if(event & EPOLLHUP){
...
}
if(event & (EPOLLPRI|EPOLLERR|EPOLLHUP)){
...
}
```