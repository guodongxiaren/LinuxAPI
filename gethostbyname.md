##函数原型
```c
#include <netdb.h>
extern int h_errno;

struct hostent *gethostbyname(const char *name);

#include <sys/socket.h>       /* for AF_INET *//*貌似不加也可以*/
struct hostent *gethostbyaddr(const void *addr,
        socklen_t len, int type);
```
