##函数原型
```c
#include <sys/epoll.h>

int epoll_wait(int epfd, struct epoll_event *events,
               int maxevents, int timeout);
```
##参数
###events
出参，记录准备好的fd。该参数为向量（数组），由调用方分配空间。  
###maxevents
最大监听**fd**。epoll_wait会检测从0到maxevents的所有fd是否就绪，如果就绪就保存到events中。    
###timeout
- 0，不阻塞立即返回
- -1，阻塞直到监听的一个fd上有一个感兴趣事件发生
- >0，阻塞指定时间。直到监听的fd上有感兴趣事件发生，或者捕捉到信号

##返回值
- >0，返回准备好的fd数量
- 0，超时
- -1，出错

通常遍历events[0]~events[返回值-1]的元素。这些都是就绪的。并且保存了就绪的事件。
>events下标与fd并不相同