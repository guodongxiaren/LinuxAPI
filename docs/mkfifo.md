<kbd>3</kbd>创建一个命名管道
##函数原型
```c
#include <sys/types.h>
#include <sys/stat.h>

int mkfifo(const char *pathname, mode_t mode);
```
##参数
第二个参数的语义与[[open()|open]]的第3个参数相同，即权限。