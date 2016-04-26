创建共享内存，通过key返回id。
##函数原型
```c
#include <sys/ipc.h>
#include <sys/shm.h>

int shmget(key_t key, size_t size, int shmflg);
```
##参数
###key
不消多说
###size
欲创建的共享内存段的大小
###shmflg
共享内存段的创建标识：
* 公共的IPC选项（在**/usr/include/linux/ipc.h中定义**）
  * `IPC_CREAT //如果不存在就创建`
  * `IPC_EXCL  //如果存在则返回失败`
  * `IPC_NOWAIT //如不等待直接返回`
* 共享内存自己的选项(在**/usr/include/linux/shm.h中定义**)
  * `SHM_R //可读`
  * `SHM_W //可写`
