命令行参数识别
##函数原型
```c
#include <unistd.h>
int getopt(int argc, char * const argv[],
            const char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

#include <getopt.h>

int getopt_long(int argc, char * const argv[],const char *optstring,
const struct option *longopts, int *longindex);

int getopt_long_only(int argc, char * const argv[],const char *optstring,
   const struct option *longopts, int *longindex);
```
##参数
getopt的前两个参数无须多言，关键是第三个optstring
* 单个字符，表示选项
* 单个字符后面接一个冒号:表示该选项后必须跟一个参数。参数紧跟在选项后或者用空格隔开，
该参数的指针赋给optarg
* 单个字符后面接两个冒号::表示该选项后可以跟一个参数，且必须紧跟在选项后，不能以空格隔开，
该参数的指针赋给optarg

##返回值

getopt()成功执行后将返回第一个选项，并设置如下全局变量。
* optarg：指向当前选项的参数（如果有）的指针
* optind：再次调用getopt()时的下一个argv指针的索引
* optopt：存储不可知或错误选项
