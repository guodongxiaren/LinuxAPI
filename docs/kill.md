##函数原型
```c
#include <sys/types.h>
#include <signal.h>

int kill(pid_t pid,int sig);
```
##描述
pid|描述|
:-----:|----
>0|kill发送信号sig给进程pid
0|kill发送信号给和当前进程在同一进程组的所有进程
-1|信号发送给系统内的所有进程
<-1|kill发送信号sig给进程组-pid中的每个进程


##返回值
* 如果成功完成返回值0
* 失败返回-1，并设置errno