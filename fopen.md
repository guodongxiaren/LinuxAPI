##函数原型
```c
#include <stdio.h>

FILE *fopen(const char *path, const char *mode);
FILE *fdopen(int fd, const char *mode);
FILE *freopen(const char *path, const char *mode, FILE *stream);
```
**`fopen`**
##参数
* path 要打开的文件路径名
* mode 文件的打开方式，6种取值

###mode
|字符|描述|
|:--|----
|r|只读，文件必须已存在
|r+|允许读写，文件必须已存在
|w|只写，文件不存在在创建，已存在则覆盖原内容写入
|w+|允许读写，文件不存在在创建，已存在则覆盖原内容写入
|a|只允许追加数据，文件不存在则创建
|a+|允许读和追加数据，文件不存在则创建
##返回值
如果调用成功，返回**文件指针**；否则返回**NULL**并设置适当的`errno`信息。