用于阻塞信号（除SIGKILL和SIGSTOP外）
##函数原型
```c
#include <signal.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```
##参数
###how
指明如何改变信号屏蔽，它的值必须是下列之一：

|how|描述
|----|----
|SIG_BLOCK|阻塞set所指信号集中的信号（将它们加入当前信号屏蔽中）
|SIG_UNBLOCK|放在set所指信号集中的信号（将它们从当前信号屏蔽中去除）
|SIG_SETMASK|用set所指信号集作为进程的新信号屏蔽（抛弃原先信号屏蔽值）
###set和oldset
- set为NULL时，how没有意义
- oldset用于返回进程原先的信号屏蔽
- 若我们只想改变信号屏蔽而不查看它，则传递NULL给oldset
- 若我们只想查看当前信号屏蔽而不改变它，则传递NULL给set

##返回值
成功0，失败-1，并设置errno