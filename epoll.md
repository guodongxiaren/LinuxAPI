##主要函数
|函数|描述
|----|----
|[[epoll_create|epoll_create]]|创建一个epoll的文件描述符
|[[epoll_ctl|epoll_ctl]]|epoll的事件注册函数
|[[epoll_wait|epoll_wait]]|收集在epoll监控的事件中已经发送的事件

##结构体
###epoll_event
```c
typedef union epoll_data {
    void *ptr;
    int fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

struct epoll_event {
    __uint32_t events; /* Epoll events */
    epoll_data_t data; /* User data variable */
};
```
##HINT
epoll_create生成的epfd，是内核中epoll结构的唯一标识。**epoll结构不直接面向应用程序员**。它维持着每个epoll处理要监视的fd及其感兴趣事件。要修改它只能通过epoll_ctl。