##函数原型
```c
#include <sys/epoll.h>

int epoll_create(int size);

```
##参数
size参数自从Linux 2.6以后被忽略了。

--------------------------------------
>epoll_create1

```c
#include <sys/epoll.h>
int epoll_create1(int flags);
```