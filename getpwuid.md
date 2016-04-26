##函数原型
```c
#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);

int getpwnam_r(const char *name, struct passwd *pwd,
                   char *buf, size_t buflen, struct passwd **result);
int getpwuid_r(uid_t uid, struct passwd *pwd,
                   char *buf, size_t buflen, struct passwd **result);
```
>缩写的含义  
**getpwnam**--->get password name   
**getpwuid**--->get password uid  

##结构体passwd
定义在头文件*pwd.h*中
```c
struct passwd {
       char   *pw_name;       /* 用户名 */
       char   *pw_passwd;     /* 用户密码 */
       uid_t   pw_uid;        /* 用户ID */
       gid_t   pw_gid;        /* 用户组ID */
       char   *pw_gecos;      /* 用户信息 */
       char   *pw_dir;        /* home目录 */
       char   *pw_shell;      /* shell程序 */
};
```