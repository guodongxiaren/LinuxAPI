##函数原型
```c
#include <netdb.h>

struct servent *getservbyname(const char *name, const char *proto);
```
##描述
查询服务数据库，匹配服务名为name，使用了proto协议的服务，并返回其servent结构。
##参数
|参数|类型|描述|
|----|----|-----
|name|const char*|服务名称
|proto|const char*|协议名（tcp或udp），如果该参数为NULL则自动匹配
##返回值
错误或读到/etc/services文件结尾则返回NULL，成功返回对应的servent指针