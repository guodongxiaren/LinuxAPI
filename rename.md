给文件改名，移动文件位置。
##函数原型
```c
#include <stdio.h>

int rename(const char *oldpath, const char *newpath);
```
##返回值
成功返回0，失败返回-1，并设置相应errno。