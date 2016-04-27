因为最早出自System V系统中，故又称System V IPC。  
分为：
* 消息队列
* 信号量
* 共享内存

这个三种通信方式共用了许多概念。都用到一个头文件**ipc.h**。  
>ipc.h位于/usr/include/linux/ipc.h

##IPC结构
```c
struct ipc_perm {
    key_t          __key; /* Key supplied to semget(2) */
    uid_t          uid;   /* Effective UID of owner */
    gid_t          gid;   /* Effective GID of owner */
    uid_t          cuid;  /* Effective UID of creator */
    gid_t          cgid;  /* Effective GID of creator */
    unsigned short mode;  /* 权限 */
    unsigned short __seq; /* Sequence number */
};
```
权限mode字段，对于IPC结构而言，都没有执行的权限。  
消息队列和共享内存使用术语读（read）和写（write），而信号量使用术语读（read）和更改（alter）。
>结构限制  
每种结构都有内置的限制。Linux可以用`ipcs -l`命令查看

##函数
###公共函数
  * [ftok](ftok)

###其他函数
|分类|创建函数|控制函数|独立函数
|-----|:---:|:-----:|:-----:
|消息队列|[[msgget|msgget]]|[[msgctl|msgctl]]|[msgsnd/msgrcv](msgsnd-msgrcv)
|信号量|[[semget|semget]]|[[semctl|semctl]]|[semop](semop)
|共享内存|[[shmget|shmget]]|[[shmctl|shmctl]]|[shmat/shmdt](shmat-shmdt)

###操作
三个函数中都会使用一个**操作**参数。有四个操作是公共操作，定义在ipc.h中。  
下面**以消息队列举例子**讲解这四个公共操作:
####IPC_RMID
删除消息队列。从系统中删除给消息队列以及仍在该队列上的所有数据，这种删除立即生效。
仍在使用这一消息队列的其他进程在它们下一次试图对此队列进行操作时，将出错，并返回EIDRM。 此命令只能由如下两种进程执行：
其有效用户ID等于msg_perm.cuid或msg_perm.guid的进程。
另一种是具有超级用户特权的进程。
####IPC_SET
设置消息队列的属性。按照buf指向的结构中的值，来设置此队列的msqid_id结构。
该命令的执行特权与上一个相同。
####IPC_STAT
读取消息队列的属性。取得此队列的msqid_ds结构，并存放在buf*中。
####IPC_INFO
读取消息队列基本情况。
