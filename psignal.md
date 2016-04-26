##函数原型
```c
#include <signal.h>

void psignal(int sig, const char *msg);
```
##描述
打印sig对应信号的描述信息到标准错误流。
##参数
sig为信号对应的数。  
msg如果不为NULL，那么将msg作为输出消息的前缀。在msg和消息描述之间默认会有一个冒号和一个空格。

##相关函数
[[psiginfo|psiginfo]]