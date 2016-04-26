结束一个线程
##函数原型
```c
#include <pthread.h>

void pthread_exit(void *retval);
```
##参数
retval用来保存线程退出状态
##返回值
为空。因为该函数**永远成功**。