##函数原型<kbd>ANSI C</kbd>
```c
#include <time.h>

time_t time(time_t *t);
```
##参数
如果t是非空指针，那么该函数的返回值也将保存在t中。
##返回值
返回自epoch（1970年1月1日00:00:00）以来的经过了的总秒数。

epoch被称为UNIX纪元。