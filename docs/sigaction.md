本节包括sigaction函数和结构体sigaction两个部分。  
函数sigaction
------------
<kbd>System Call</kbd>用于测试和改变一个信号的行为。
###函数原型
```c
#include <signal.h>

int sigaction(int signum, const struct sigaction *act,
                 struct sigaction *oldact);
```
|参数|描述|
|----|---|
|signum|指定要改变的信号
|act|一个函数指针，如果不为空，则指定收到该信号后的行为
|oldact|如果oldact不为空，则将原行为保存在函数指针oldact中
********
结构体sigaction
--------------
###结构体原型
```c
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
};
```
####sa_handler
是一个函数指针，其含义与 signal 函数中的信号处理函数类似。  
####sa_sigaction
是另一个信号处理函数，它有三个参数，可以获得关于信号的更详细的信息。当 sa_flags 成员的值包含了 SA_SIGINFO 标志时，系统将使用 sa_sigaction 函数作为信号处理函数，否则使用 sa_handler 作为信号处理函数。
>在某些系统中，成员 sa_handler 与 sa_sigaction 被放在联合体中，因此使用时不要同时设置。

####sa_mask
成员用来指定在信号处理函数执行期间需要被屏蔽的信号，特别是当某个信号被处理时，它自身会被自动放入进程的信号掩码，因此在信号处理函数执行期间这个信号不会再度发生。  
####sa_flags
成员用于指定信号处理的行为，它可以是以下值的“按位或”组合。
 * SA_RESTART：使被信号打断的系统调用自动重新发起。  
 * SA_ONSTACK：系统将在调用[[sigalstack|sigalstack]]替代信号栈上运行信号句柄；否则使用用户栈来交付信号。 
 * SA_NOCLDSTOP：使父进程在它的子进程暂停或继续运行时不会收到 SIGCHLD 信号。  
 * SA_NOCLDWAIT：使父进程在它的子进程退出时不会收到 SIGCHLD 信号，这时子进程如果退出也不会成为僵尸进程。  
 * SA_NODEFER：使对信号的屏蔽无效，即在信号处理函数执行期间仍能发出这个信号。  
 * SA_RESETHAND：信号处理之后重新设置为默认的处理方式。  
 * SA_SIGINFO：使用 sa_sigaction 成员而不是 sa_handler 作为信号处理函数。  

>该段文字整理自[博客园](http://www.cnblogs.com/wblyuyang/archive/2012/11/13/2768923.html)  

##相关函数
- [[signal|signal]]
- [[sigemptyset|sigemptyset]]