ftell
------
tell就是说话的意思，该函数功能为报告当前位置距离文件开始处是第几个字符
###函数原型
```c
#include <stdio.h>

long ftell(FILE *fp);
```
###返回值
返回fp所指向文件流的当前位置。如果出错返回-1
