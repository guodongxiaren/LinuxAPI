##函数原型
```c
#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);
```
实际执行需要root权限。也就是使用root身份或者sudo来运行该程序的可执行文件。
>If the owner or group is specified as -1, then that ID is not changed.

###区别联系
* lchown修改符号链接时，修改的是符号链接权限。
* chown修改符号链接时，修改符号链接指向的文件的权限。 
* fchown修改符号连接时，行为和chown相同。只不过它的参数是文件的描述符。