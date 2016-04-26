fprintf/fscanf
-----------------
和printf与scanf及其类似。唯一的不同之处是print/scanf是面向标准输出/输入的。  
而fprintf/fscanf则是面向FILE指针。当然stdout/stdin 也是FILE指针。
###函数原型
```c
#include <stdio.h>

int fprintf(FILE *fp,const char *format,...);
int fscanf(FILE *fp,const char *format,...);
```
