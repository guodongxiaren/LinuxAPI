这是一对函数，用于消息队列的发送和接收
###描述
msgsnd函数用于将新的消息添加到消息队列的尾端。  
msgrcv函数用于从消息队列中读取msqid指定的消息
###函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
                      int msgflg);
```
###参数
#### msgsnd
* msqid：消息队列标识符(由[msgget](msget)生成)
* msgp：指向用户自定义的缓冲区（[msgp](#msgp)）
* msgsz:接收信息的大小。范围在0～系统对消息队列的限制值
* msgflg:指定在达到系统为消息队列限定的界限时应采取的操作。
  * IPC_NOWAIT 如果需要等待，则不发送消息并且调用进程立即返回，errno为**EAGAIN**
  * 如果设置为0，则调用进程挂起执行，直到达到系统所规定的最大值为止，并发送消息

#### msgrcv
* msqid：消息队列标识符
* msgp：指向用户自定义的缓冲区（[msgp](#msg)）
* msgsz：如果收到的消息大于msgsz，并且msgflg&MSG_NOERROR为真，则将该消息截至msgsz字节，并且不发送截断提示
* msgtyp：用于指定请求的[消息类型](#msg)：
  * msgtyp=0：收到的第一条消息，任意类型。
  * msgtyp>0：收到的第一条msgtyp类型的消息。
  * msgtyp<0：收到的第一条最低类型（小于或等于msgtyp的绝对值）的消息。
* msgflg：用于指定所需类型的消息不再队列上时的将要采取的操作：
  * 如果设置了IPC_NOWAIT，若需要等待，则调用进程立即返回，同时返回-1，并设置errno为**ENOMSG**
  * 如果未设置IPC_NOWAIT，则调用进程挂起执行，直至出现以下任何一种情况发生：
    * 某一所需类型的消息被放置到队列中。
    * msqid从系统只能怪删除，当该情况发生时，返回-1，并将errno设为**EIDRM**。
    * 调用进程收到一个要捕获的信号，在这种情况下，未收到消息，并且调用进程按`signal(SIGTRAP)`中指定的方式恢复执行。

###返回值
毋庸置疑，成功0，失败-1。  
其他要注意的是，消息队列数据结构（msqid_ds类型）成员的变化：
####msgsnd
成功时：
* msg_qnum  以1为增量递增
* msg_lspid 设置为调用进程的pid
* msg_stime 设置为当前时间。

####msgrcv
成功时：
* msg_qnum  以1为增量递减
* msg_lrpid 设置为调用进程的pid
* msg_rtime 设置为当前时间。

*************
####msgp
该类型需要自己在编程时定义，用于存储消息的内容。  
下面给出一个范例，注意，里面的名称随意。
```c
struct msgbuf{
    long mtype;   //消息类型
    char mtext[1];//数组大小编程时自己指定
};
```