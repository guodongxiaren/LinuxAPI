控制信号量集合、信号量
##函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semctl(int semid, int semnum, int cmd, ...);
```
##参数
可以有三个参数，也可以有四个参数（利用的可变参数个数的函数定义）。
* semid是信号量集合的标识符，一般由[semget](semget)函数返回。
* semnum为集合中信号量的编号。
  * 如果标识某个信号量，此值为信号量下标（0～n-1）
  * 如果标识整个信号量集合，则设置为0【与上面冲突？】
* cmd为要执行的操作：
  * 共有的IPC四个操作
  * `GETVAL` //返回的是semnum的值
  * `GETALL` //设置semnum为0，那么获取信号集合的地址传递给第四个参数。返回值为0，-1
  * `GETNCNT` //设置semnum为0，返回值为等待信号量值的递增进程数，否则返回-1
  * `GETZCNT` //设置semnum为0，返回值是等待信号量值的递减进程数，否则返回-1
  * `SETVAL` //将第四个参数指定的值设置给编号为semnum的信号量。返回值为0，1
  * `SETALL` //设置semnum为0，将第四个参数传递个所有信号量。返回值0，1

>GET的四个操作中，只有GETVAL成功时返回0，其余的都是返相应取的值。SET两个操作都返回的是值

* [第四个参数]，根据cmd的不同而不同。其类型为[semun](#semun)的联合：
  * 如果cmd为SETVAL，那么该参数为val
  * 如果cmd为IPC_STAT&IPC_SET，那么该参数为struct semid_ds结构体变量
  * 如果cmd为GETVAL&SETALL，则该参数为数组地址array。
  * 如果cmd为IPC_INFO，则该参数为strcut seminfo结构体变量__buf


------------
###semun
```
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};
```