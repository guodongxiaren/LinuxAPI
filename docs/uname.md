##函数原型
```c
#include <sys/utsname.h>

int uname(struct utsname *buf);
```
##参数
该函数的参数是用来返回的，即声明一个结构体[utsname](#utsname)类型的变量，然后放入函数中。待uname()执行完毕后，会将系统内核信息返回到这个结构体[utsname](#utsname)变量中。
##返回值
成功返回0，失败返回-1，并设置errno。

----------
##utsname
```c
struct utsname {
	char sysname[];    /* 操作系统名称 (如, "Linux") */
	char nodename[];   /* Name within "some implementation-defined
		             network" */
	char release[];    /* 操作系统发行版本 (如, "2.6.28") */
	char version[];    /* 操作系统版本 */
	char machine[];    /* 硬件标识符 */
	#ifdef _GNU_SOURCE
	char domainname[]; /* NIS 或 YP 域名 */
	#endif
};
```