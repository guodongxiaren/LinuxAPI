##头文件
- semaphore.h
- sys/stat.h
- fcntl.h

##常用函数
|函数|说明
|---|---
|[[sem_open|sem_open]]|打开一个有名信号量
|[[sem_close|sem_close]]|关闭一个信号量
|[[sem_unlink|sem_unlink]]|删除一个信号量
|[[sem_post|sem_post]]|【V操作】释放操作：信号量的值加1
|[[sem_wait|sem_wait]]|【P操作】分配操作：信号量的值减1
|[[sem_getvalue|sem_getvalue]]|获取信号量的值
|[[sem_init|sem_init]]|初始化一个无名信号量
|[[sem_destroy|sem_destroy]]|破坏一个无名信号量