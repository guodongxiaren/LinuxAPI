对一个信号指定新动作或回到其原先的动作
##函数原型
```c
#include <signal.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```

##参数
signum即信号值。后面的handler就是处理这个信号的动作。它的值为：
- SIG_DFL：默认动作
- SIG_IGN：忽略该信号（SIGKILL和SIGSTOP无法忽略，因为要保证root的绝对控制权）
- 信号句柄

##信号句柄
信号句柄即捕获函数（这里是函数指针类型），该函数必须是只有一个整型参数，且返回值为void。  

信号发送时，如果建立了信号句柄，系统在把控制转移到信号句柄之前有两种做法：
- 将阻塞后继新的信号直至信号句柄完成为止
- 或这首先改变该信号的动作为SIG_DEL(相当于调用signal(signum,SIG_DEL)，在执行完一次信号句柄之后，将其恢复为默认动作)

BSD系统使用前者，系统V使用后一种。Linux默认采用BSD的做法，但当设置了特征测试宏`_XOPEN_SOURCE`时，则采用系统V的做法，此时编译时要这样编译
```
gcc test.c -D_XOPEN_SOURCE
```
##返回值
返回值是指向信号signum前一次有效动作的指针。它和函数第二个参数类型相同。返回值是：
- SIG_DFL
- SIG_IGN
- 信号句柄指针

**可以保存这个值，并且在以后用它作为函数第二个参数再次调用signal()，从而恢复信号原来的动作**   

如果出错，返回**SIG_ERR**并设置**errno**。唯一地错误码（errno）是**EINVAL**
##相关函数
[[sigaction|sigaction]]