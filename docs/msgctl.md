该函数用来对消息队列的基本属性进行控制、修改。
###函数原型
```
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgctl(int msqid, int cmd, struct msqid_ds *buf);
```
###参数
* msqid为消息队列标识符。
* cmd为执行的控制命令(在ipc.h中定义)：
  * [`#define IPC_RMID 0`](#ipc_rmid)
  * [`#define IPC_SET 1`](#ipc_set)
  * [`#define IPC_STAT 2`](#ipc_stat)
  * [`#define IPC_INFO 3`](#ipc_info)
* buf

cmd字段除了公共的四个操作以外，还有自己独立的操作。
-------------------
###IPC_RMID
删除消息队列。从系统中删除给消息队列以及仍在该队列上的所有数据，这种删除立即生效。  
仍在使用这一消息队列的其他进程在它们下一次试图对此队列进行操作时，将出错，并返回**EIDRM**。
此命令只能由如下两种进程执行：
* 其有效用户ID等于msg_perm.cuid或msg_perm.guid的进程。
* 另一种是具有超级用户特权的进程。

###IPC_SET
设置消息队列的属性。按照**buf**指向的结构中的值，来设置此队列的msqid_id结构。  
该命令的执行特权与上一个相同。
###IPC_STAT
读取消息队列的属性。取得此队列的**msqid_ds**结构，并存放在**buf***中。
###IPC_INFO
读取消息队列基本情况。