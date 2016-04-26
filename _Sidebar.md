<div align="center">
<a href="home">
<img src=http://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/NewTux.svg/150px-NewTux.svg.png />
</a>
</div>
####[[时间与定时|时间]]
|ANSI C|POSIX
|----|---
|[[time|time]]|[[gettimeofday|gettimeofday]]
|[[difftime|difftime]]|[[getitimer|getitimer]]
|[[localtime|localtime]]
|[[ctime|ctime]]

####[[系统管理|系统管理]]
####[[命令行|命令行]]
* [[getopt|getopt]]

####[[文件I/O|文件I O]]
- [x] 基于文件描述符
* [[open|open]]
* [[read|read]]
* [[write|write]]
- [[lseek|lseek]]
* [[fcntl|fcntl]]
* [[dup|dup]]
- [x] [[基于数据流|ANSI_IO]] <kbd>ANSI C</kbd>

|[[fopen|fopen]]|[[fclose|fclose]]
|----------|----------|
|[[fwrite|fwrite-fread#fwrite]]|[[fread|fwrite-fread#fread]]
|[[fputc|fputc-fgetc#fputc]]|[[fgetc|fputc-fgetc#fgetc]]
|[[fputs|fputs-fgets#fputs]]|[[fgets|fputs-fgets#fgets]]
|[[feof|feof-ferror#feof]]|[[ferror|feof-ferror#ferror]]
|[[fseek|fseek-rewind#fseek]]|[[rewind|fseek-rewind#rewind]]
|[[ftell|ftell]]|

####文件与目录
- [x] [[文件操作|文件操作]]
* [[chown|chown]]
* [[rename|rename]]
* [[stat|stat]]
* [[dirname|basename]]
* [[basename|basename]]
- [x] [[目录操作|目录操作]]
* [[getcwd|getcwd]]

####[[进程控制|进程控制]]
|[[fork|fork]]|[[vfork|vfork]]
|---|---
[[exec~|exec]]|[[system|system]]
|[[wait|wait]]|[[waitpid|waitpid]]

--------------------
###[[进程通信|进程通信]]
####管道
|[[pipe|pipe]]|[[mkfifo|mkfifo]]|
|------|--------

####[[信号处理|信号处理]]
* [[信号类型|信号类型]]
* [[psignal|psignal]]
* [[kill|kill]]
* [[raise|raise]]
* [[signal|signal]]
* [[sigaction|sigaction]]
* [[信号阻塞|信号阻塞]]
* [[sigsuspend|sigsuspend]]
* [[sigalstack|sigalstack]]

####[[IPC对象|XSI-IPC]] <kbd>System V</kbd>
|[[消息队列|消息队列]]|[[信号量|信号量]]|[[共享内存|共享内存]]
|:-----|:-------|:-------|
|[[msgget|msgget]]|[[semget|semget]]|[[shmget|shmget]]
|[[msgctl|msgctl]]|[[semctl|semctl]]|[[shmctl|shmctl]]
|[[msgsnd|msgsnd-msgrcv]]|[[semop|semop]]|[[shmat|shmat-shmdt]]
|[[msgrcv|msgsnd-msgrcv]]||[[shmdt|shmat-shmdt]]

####[[IPC对象|POSIX-IPC]] <kbd>POSIX</kbd>
- [[消息队列|POSIX消息队列]]
- [[信号量|POSIX信号量]]
- [[共享内存|POSIX共享内存]]

####[[网络编程|网络编程]]
|[[套接字结构|套接字结构]]|[[套接字函数|套接字函数]]
|------|--------
|[[字节序转换|字节序转换函数]]|[[地址转换|地址转换函数]]
|[[主机|主机]]|[[服务|服务]]

 
* [[带外数据|带外数据]]
  * [[sockatmark|sockatmark]]


-----------------------
####[[多线程|线程]]
-   基本编程
  * [[pthread_create|pthread_create]]
  * [[pthread_exit|pthread_exit]]
  * [[pthread_join|pthread_join]]
-  [[线程同步|线程同步]]
  - [[互斥锁|互斥锁]]
  - [[条件变量|条件变量]]
  - [[读写锁|读写锁]]
  - [[线程信号|线程信号]]
  - [[POSIX信号量|POSIX信号量]]

####[[I/O复用|I/O复用]]
- [[select|select]] <kbd>BSD</kbd>
- [[poll|poll]] <kbd>System V</kbd>
- [[epoll模型|epoll]]
  * [[epoll_create|epoll_create]] 
  * [[epoll_ctl|epoll_ctl]] 
  * [[epoll_wait|epoll_wait]] 

####[[异步IO(AIO)|AIO]]