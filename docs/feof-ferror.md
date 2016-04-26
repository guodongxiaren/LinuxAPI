feof/ferror
-----
###函数原型
```c
int feof(FILE *fp);
int ferror(FILE *fp);
```
###功能描述
####feof
测试fp指向的流是否设置了EOF标记（end-of-file indicator）。
即是否到达文件结尾。    
该标记只能被clearerr函数清除。
若fp当前位置是文件结尾，则返回非0值，否则返回0。  
####ferror 
测试fp指向的流是否设置了错误标记（error indicator）。
是否到达文件结尾。  
该标记只能被clearerr函数清除。
若该标记被设置，则返回非0值。即表示出错。  
###示例
```c
...
while(!feof(fp))
{
    ...
}
```
若不是文件结尾则执行循环。


