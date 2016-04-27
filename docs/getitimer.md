##函数原型
```c
#include <sys/time.h>

int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value,
             struct itimerval *old_value);
```
##参数
###which
指定使用哪一种计时器。Linux 操作系统为每一个进程提供了 3 个内部间隔计时器：
* ITIMER_REAL:减少实际时间.到时的时候发出 SIGALRM 信号。
* ITIMER_VIRTUAL:减少有效时间(进程执行的时间)。产生 SIGVTALRM 信号。
* ITIMER_PROF:减少进程的有效时间和系统时间(为进程调度用的时间)。产生 SIGPROF 信号。

>后两者经常结合使用用来计算系统内核时间和用户时间

###getitimer
获取当前的计时器。
###setitimer
设置新计时器new_value，如果原计时器不为空，则保存到old_value中。
##结构体itimerval和timeval
```c
struct itimerval {
       struct timeval it_interval; /* 间隔，it_value为0以后会重置为it_interval */
       struct timeval it_value;    /* 当前值 */
};

struct timeval {
       time_t      tv_sec;         /* 秒 */
       suseconds_t tv_usec;        /* 微秒 */
};
```
