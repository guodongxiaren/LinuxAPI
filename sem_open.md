##函数原型
```c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag,
                mode_t mode, unsigned int value);
```
##参数
和[[open()|open]]函数参数基本相同。唯一的限制是参数name必须是字符`/`打头。