##函数原型
```c
#include <sys/types.h>
#include <unistd.h>

pid_t vfork(void);
```
##描述
同样是创建子进程，其效率比fork()要快。两者区别有：
- vfork()不会创建并复制父进程的地址空间，而是和父进程共享
- vfork()会阻塞父进程，只运行子进程运行
- 当子进程调用exec()或_exit()时，内核返回地址空间给父进程并唤醒它

