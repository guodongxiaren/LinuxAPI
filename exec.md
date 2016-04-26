exec函数族的作用是让fork出的子进程能够执行与父进程不同的代码段，实现不同的功能。
###exec由6个函数组成
```c
int execl(const char *path,const char *arg,...);
int execlp(const char *file,const char *arg,...);
int execle(const char *path,const char *arg,...,char *const encp[]);

int execv(const char *path,const char *argv[]);
int execvp(const char *file,const char *argv[]);
int execve(const char *path,const char *argv[],char *const envp[]);
```
###如何记忆
|字符|原型|描述|
|---|---|---|
|l|list|选项列表，对应函数的省略号，可以写多个参数，以NULL结尾|
|v|vector|将命令的多个选项放到一个数组里，作为第二个参数|
|p|path|在系统PATH变量的路径里搜索，无p字符的函数则需要给出可执行文件的全路径名|
|e|enviroment|表示将一份新的环境变量传给他？|

###样例
```c
execlp("ls", "ls", "-a", (char *)NULL);
char *v[] = {"ls", "-a", NULL};
execvp("ls", v);
```