shmat是shared memory attach的缩写。而attach本意是贴的意思。  
如果进程要使用一段共享内存，那么一定要将该共享内存与当前进程建立联系。即经该共享内存挂接（或称映射）到当前进程。  
shmdt则是shmat的反操作，用于将共享内存和当前进程分离。在共享内存使用完毕后都要调用该函数。
##函数原型
```c
#include <sys/types.h>
#include <sys/shm.h>

void *shmat(int shmid, const void *shmaddr, int shmflg);

int shmdt(const void *shmaddr);
```
##参数
###shmid
共享内存空间的标识符，即ID。
###shmaddr
指定共享内存的映射地址。  
shmat中：如果为0（NULL），则由系统选择映射的地址，推荐设置为0。如果非0，并且没有指定**SHM_RND**,则该值即为映射共享内存的地址。
###shmflg
指定共享内存的访问权限和映射条件:
* SHM_RDONLY //只读
* SHM_RND //取整，取向下一个[SHMLBA](#shmlba)边界
* SHM_REMAP //take-over region on attach
* SHM_EXEC //执行权限

如果设置为0的话，则是**读写**权限。
##返回值
* shmat
  * 成功，则返回共享内存的地址
  * 失败，则返回-1，并设置errno
* shmdt
  * 成功，则返回0
  * 失败，则返回-1，并设置errno

-----------------
###SHMLBA
低边界地址倍数，它总是2的乘方。