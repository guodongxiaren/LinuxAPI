###函数原型
```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```
###返回值
|-1 |错误|
|---|---|
|其他|被终止的子进程的id|
####错误类型
错误时，系统记录的错误代码**errno**，有两种：

|ECHILD|没有子进程|
|---|---|
|**EINTER**|收到中断信号**signal**，立即返回|
###检测退出状态的宏
|宏|缩写含义|描述|
|----|-----|----
|**WIFEXITED**|wait if exited|子进程正常退出时返回真值
|*WEXITSTATUS*|wait exit status|当上面宏为真时，返回子进程正常退出时状态
|**WIFSIGNALED**|wait if signaled|子进程由于信号导致终止，返回真值
|*WTERMSIG*|wait terminate signal|当上面宏为真时，返回终止子进程的信号类型
|**WIFSTOPPED**|wait if stopped|
|*WSTOPSIG*|wait stop signal|
|**WIFCONTINUED**|wait if continued|
上表记忆方式为3+1,三对加一单
>另外有书中提及**WCOREDUMP**，即wait core dump（核心转储），不过man手册中未提及此宏