该函数的操作对象为信号量，而非信号量集合。这是一个原子操作。 
为`semaphore operate`的缩写 
##函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semop(int semid, struct sembuf *sops, unsigned nsops);

int semtimedop(int semid, struct sembuf *sops, unsigned nsops,
               struct timespec *timeout);
```
##参数
###semid
要操作的信号量集合标识符
###sops
此结构体为：
```c
struct sembuf {
	unsigned short  sem_num;	/* 数组中的信号量下标 */
	short		sem_op;		/* 信号量操作 */
	short		sem_flg;	/* 操作标识 */
};
```
成员解读：
* sembuf为信号量的编号
* sem_op是要进行的操作（[PV操作](#pv)）：
  * 如果为正整数，表示增加信号量的值（若为3，则加上3）
  * 如果为负整数，表示减小信号量的值
  * 如果为0，表示对信号量当前值进行是否为0的测试
* sem_flg为操作标识：
  * IPC_NOWAIT：如果不能对信号量集合进行操作，则立即返回
  * SEM_UNDO：当进程退出后，该进程对sem进行的操作将撤销

###nsops

----------
###PV
信号量是最早出现的用来解决进程同步与互斥问题的机制。  
P原语操作的动作是：

1. sem减1；
2. 若sem减1后仍大于或等于零，则进程继续执行；
3. 若sem减1后小于零，则该进程被阻塞后进入与该信号相对应的队列中，然后转进程调度。

V原语操作的动作是：

1. sem加1；
2. 若相加结果大于零，则进程继续执行；
3. 若相加结果小于或等于零，则从该信号的等待队列中唤醒一等待进程，然后再返回原进程继续执行或转进程调度。
