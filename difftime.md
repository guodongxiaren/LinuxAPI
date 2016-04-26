计算两个时间的差值

一般人们会用两次time()的结果直接相减来获取差值，但是time_t的类型ANSI C并未规定，有的系统是整型有的系统是浮点型或其他编码。为了兼容性，ANSI C的difftime()统一返回双精度浮点数。
##函数原型
```c
#include <time.h>

double difftime(time_t time1, time_t time0);
```
##备注
实际上在POSIX系统中，常被定义成：
```c
#define difftime(t1,t0) (double)(t1 - t0)
```