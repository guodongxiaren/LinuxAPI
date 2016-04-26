##函数原型
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);
```
三个函数的关系与chown，fchown，lchown的关系相同。
* stat检查符号链接时，实际检查的是符号链接所引用的文件
* lstat检查符号链接时，检查的是符号链接本身
* fstat功能与stat相同，不过它的参数是文件的描述符

##返回值
成功返回**0**；失败返回**-1**，并设置相应errno的值。
>结构体stat的内容
```c
struct stat {
    dev_t     st_dev;     /* 设备号（主设备号，次设备号）*/
    ino_t     st_ino;     /* inode的数量 */
    mode_t    st_mode;    /* 文件的类型和存取的权限 */
    nlink_t   st_nlink;   /* 硬链接的数量 */
    uid_t     st_uid;     /* 所用者的uid */
    gid_t     st_gid;     /* 所有者的组id */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* 总大小,字节数 */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* 最后访问时间（access）*/
    time_t    st_mtime;   /* 最后修改时间（modification）文件内容的改动时间 */
    time_t    st_ctime;   /* 最后改动时间（change）文件属性的改动时间 */
};
```