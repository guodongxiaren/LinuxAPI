>System V提供的三种IPC进制，有异曲同工之妙。

semget
-----
创建信号量结合
###函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semget(key_t key, int nsems, int semflg);
```
###参数
参数含义，与[msgget](msgget)类似，只是比它多了第二个参数。  
* key为[ftok](ftok)函数创建。
* nsems为创建的信号量的个数，每个信号量以数组方式存储。
* semflg用来标识信号量结合的权限。如**0700**。此外还可以附加以下ipc参数：

|宏名|描述|
|---------|-------|
|IPC_CREAT|如果key不存在，则创建*(类似open函数的O_CREAT)*
|IPC_EXCL|如果key存在，则返回失败*(类似open函数的O_EXCL)*
|IPC_NOWAIT|如果需要等待，则直接返回错误
