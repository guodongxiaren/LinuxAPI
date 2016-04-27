从父进程派生出子进程，子进程完全拷贝父进程的stack，data，heap segment。
>两者并不共享地址空间，所以的变量是独立的，一方修改，另一方不会变化。

###函数原型
```c
#include <unistd.h>

pid_t fork(void);
```
###特点
一次调用，两次返回
