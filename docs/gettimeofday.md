##函数原型
```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
int settimeofday(const struct timeval *tv, const struct timezone *tz);
```
##参数
###结构体timeval
```c
struct timeval
{
    long tv_sec;/*秒数*/
    long tv_usec;/*微秒数*/
};
```
当前时间会返回给这个结构体指针tv。
###结构体timezone
可以设为NULL。
###返回值
- 0 ：成功
- -1：失败