共享内存的控制
##函数原型
```c
#include <sys/ipc.h>
#include <sys/shm.h>

int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```
##参数
###shmid
由shmget函数生成，不同的key值对应不同的id值。
###cmd
操作字段，包括：
* 公共的IPC选项（ipc.h中）：
  * `IPC_RMID             //删除`
  * `IPC_SET              //设置ipc_perm参数`
  * `IPC_STAT             //获取ipc_perm参数`
  * `IPC_INFO             //如ipcs`
* 共享内存自己的选项（shm.h中）【需要root权限】
  * `SHM_LOCK             //锁定共享内存段`
  * `SHM_UNLOCK           //解锁共享内存段`