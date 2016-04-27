##函数原型
```c
#include <sys/types.h>
#include <grp.h>

struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);
int getgrnam_r(const char *name, struct group *grp,
         char *buf, size_t buflen, struct group **result);

int getgrgid_r(gid_t gid, struct group *grp,
         char *buf, size_t buflen, struct group **result);
```
>缩写含义
**getgrnam**--->get group name
**getgruid**--->get group uid

##结构体group
定义在头文件*grp.h*中
```c
struct group {
       char   *gr_name;       /* 组名 */
       char   *gr_passwd;     /* 组密码 */
       gid_t   gr_gid;        /* 组ID */
       char  **gr_mem;        /* 组成员 */
};
```

