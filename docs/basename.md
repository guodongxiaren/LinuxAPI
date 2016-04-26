**basename()和dirname()是一对。**
##函数原型
```c
#include <libgen.h>

char *dirname(char *path);

char *basename(char *path);
```
##功能比较
path      | dirname|   basename
|----|----|----
       /usr/lib|   /usr|      lib
       /usr/    |  /     |    usr
       usr       | .       |  usr
       /         | /      |   /
       .         | .     |    .
       ..        | .    |     ..

也可以用于**url**。