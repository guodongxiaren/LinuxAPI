##函数原型
```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```
##参数
参数同read函数

|参数|描述|
|:---:|----|
|fd|文件描述符|
|buf|读取的数据存放在buf指针指向的缓冲区|
|count|读取的字节数|
##返回值
如果函数调用成功，返回值为写入的**字节数**；否则返回值为**-1**，并设置相应的errno值。