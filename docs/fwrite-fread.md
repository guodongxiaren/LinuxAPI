##fwrite

###函数原型
```c
#include <stdio.h>

size_t fwrite(const void *ptr,size_t size,size_t n,FILE *fp);
```
###参数
ptr为基本类型或自定义的结构体类型的指针。
size代表要写入的数据字节数，通常为sizeof(数据类型)。  
n代表写入的数据的个数。  
fp即为文件指针。
###返回值
返回写入的数据的个数。  
如果成功写入则，文件内部指针会向右移动n*size。

fread
-----
###函数原型
```c
#include <stdio.h>

size_t fread(void *ptr,size_t size,size_t n,FILE *fp);
```
###参数
与fwrite含义相同。
###返回值
fread不区分文件结束和错误。如有必要，请使用[feof](feof-ferror)和[ferror](feof-ferror.md)。
