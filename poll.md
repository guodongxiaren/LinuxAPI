poll()和select()原理相同，但实现方式不同。select()用的更为频繁，但`据说`poll()效率更高，不过自`Linux 2.5.44`后被epoll取代。
##函数原型
```c
#include <poll.h>

int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```
##参数
###fds
[pollfd](#pollfd)结构的数组。  
检测每个结构中的fd对应的events事件是否就绪。在poll返回的时候将就绪情况写入到revents中。
###nfds
nfds_t是`unsigned long`类型，据《UNP》所言，该类型过大了。
###timeout
- -1：永远等待（一说：负数）
- 0：不等待，立即返回
- >0：等待指定数目的毫秒数

##返回值
- 0： 表示超时返回
- -1：表示出错
- >0：表示就绪的的文件描述符的数量

>poll()与select()返回正数时，其含义有差别：
- select()： 如果同一个文件描述符在多个fd集（select有三个fd集合）中返回，则返回值也统计多次
- poll()：即使同一个fd出现在多个pollfd元素的`revents`成员中，也只被统计一次。

----------
##pollfd
非`typedef`的结构体类型

|成员|类型|说明
|----|----|----
|fd|int|
|events|short|
|revents|short|
events和revents都是`bit masks`。events是输入，revents是输出（返回），events由用户设置，revents在函数返回时被设置。其取值可以是如下宏的按位或的结果：

|输入事件bit位|events的输入？|revents的结果？|说明
|---|:-------:|:------:|:------:
|POLLIN|√|√|有数据可读
|POLLRDNORM|√|√|等价于**POLLIN**
|POLLPRI|√|√|高优先级数据可读
|POLLRDHUP|√|√|对等套接字关闭
|**输出事件bit位**|**events的输入？**|**revents的结果？**|**说明**
|POLLOUT|√|√|普通数据可写
|POLLWRNORM|√|√|等价于**POLLOUT**
|POLLWRBAND|√|√|优先级数据可写
|**错误事件bit位**|**events的输入？**|**revents的结果？**|**说明**
|POLLERR||√|发生错误
|POLLHUP||√|发生挂起
|POLLNVAL||√|（invalid）fd没有被打开

>POLLRDHUP 从`Linux 2.6.17`开始被支持  
差异性：《UNP》中提到的POLLRDBAND其实并不被Linux支持；此外《UNP》中POLLIN与POLLRDNORM，POLLOUT与POLLWRNORM也并非等价。  


 