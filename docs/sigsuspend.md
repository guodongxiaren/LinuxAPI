##函数原型
```c
#include <signal.h>

int sigsuspend(const sigset_t *mask);
```
##描述
用mask所指的信号集临时替代调用进程的信号屏蔽，然后挂起调用进程直到有不属于mask的信号到达为止。
##返回值
**一直返回-1**，有错误会设置errno
##相关函数
[[pause()|pause]]