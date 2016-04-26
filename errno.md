错误
----
###errno
在头文件**error.h**中定义。在函数调用出错的时候会设置相应的errno的值。
- [x] 注意
* 如果系统调用或库函数正确执行的话，errno的值是不会被置0。
* 系统调用或库函数正确执行，并不保证errno的值不会被改变！
* 任一函数都不会将errno值置0。
* 任何错误号（即发生错误时errno的取值）都是非0的。

###perror
头文件**stdio.h**    
打印错误信息。打印出来就是**stderr**。
###strerror
将error翻译成具体错误信息。实际使用时需要包含：
```c
#include <errno.h>
#include <string.h>
```
两个头文件。