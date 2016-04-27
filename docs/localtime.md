##函数原型
```c
#include <time.h>

struct tm *localtime(const time_t *timep);
```
##描述
将参数中timep代表的秒数转换为结构体tm类型。出现错误时返回NULL。    
注意，此时参数timep中的必须是经过time()初始化过的变量。
所以通常的用法是：
```c
struct tm* t;
time_t currentTime;

time(&currentTime);
t = localtime(&currentTime);
```
**注意返回的tm的年份是从1900开始计数的，月份是从0开始计数的**
##tm <kbd>struct</kbd>
```c
struct tm {
   int tm_sec;    /* Seconds (0-60) */
   int tm_min;    /* Minutes (0-59) */
   int tm_hour;   /* Hours (0-23) */
   int tm_mday;   /* Day of the month (1-31) */
   int tm_mon;    /* Month (0-11) */
   int tm_year;   /* Year - 1900 */
   int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
   int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
   int tm_isdst;  /* Daylight saving time */
};
```