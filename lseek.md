##函数原型
```c
#include <sys/types.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
```
##参数
- fd是文件描述符
- offset是偏移量
- whence是偏移量的基准位置。它的取值有三个
  - *SEEK_SET*: 开始位置
  - *SEEK_CUR*: 当前位置
  - *SEEK_END*: 末尾位置

>为什么开始位置的后缀是**_SET**
>>实际上，在man手册中可以看出。这三个宏的描述是
- SEEK_SET The offset is set to offset bytes.
- SEEK_CUR The offset is set to its current location plus offset bytes.
- SEEK_END The offset is set to the size of the file plus offset bytes.

----------
##fd的偏移量
在内核中对一个文件描述符（fd）的偏移量只维护一个值，也就是说你用读写方式打开一个文件，如果先用read读取了n个字符，紧接着用write写入了n个字符，那么后来写入的n个字符并不是从文件第一个字符位置开始的，而是从n+1个字符位置开始的。所以通常我们需要使用lseek来使fd的偏移量置于文件开始位置。