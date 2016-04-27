I/O多路复用常用于I/O操作可能会被阻塞的情况
- select()出自BSD系统，poll()出自 System V系统。两者原理等价，实现方式不同。POSIX.1定义了两者。  
- epoll()出自Linux2.6，其他Unix系统无此函数，BSD系统（包括OSX系统）有类似的函数kequeue()