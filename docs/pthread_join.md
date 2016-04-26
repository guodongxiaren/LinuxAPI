为了回收资源，主线程会等待子线程结束。该函数就是用来等待线程终止的。类似与进程中的wait函数。  
此函数将阻塞调用当前线程的进程，直到此线程退出。  
##函数原型
```c
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);
```
##参数
###thread
被等待线程的ID
###retval
如果此值非NULL，pthread_join复制线程的退出状态
##返回值
成功返回0，失败返回非0
