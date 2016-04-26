ftok函数
-------
取file to key之意
###函数原型
```c
#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok(const char *pathname, int proj_id);
```
###参数
pathname必须是存在的，且可访问的文件名（可以包括路径）。  
proj_id的低8位会被用到。该参数不能为0。
###返回值
返回一个key_t（*int*）类型的key值。  
* key的31~24位为ftok第二个参数的低8位。
* key的23~16位为该文件st_dev属性的低8位。
* key的15~0位为该文件st_ino属性的低16位。