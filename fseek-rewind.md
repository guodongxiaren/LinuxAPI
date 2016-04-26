fseek
-----
用于跳跃式地移动文件读写位置。
###函数原型
```c
#include <stdio.h>

int fseek(FILE *fp,long offset,int whence);
```
###参数
offset为相较whence的偏移量。   
whence为文件内部指针的基准：
* `SEEK_SET` 文件开始位置，其值为0
* `SEEK_CUR` 文件当前位置，其值为1
* `SEEK_END` 文件结束位置，其值为2

###返回值
如果执行成功，将返回0。如果失败返回-1

rewind
-------
rewind英文释义是`倒带`的意思。这里是重置文件指针到所指向的文件的开始位置。
###函数原型
```c
#include <stdio.h>

void rewind(FILE *fp);
```
