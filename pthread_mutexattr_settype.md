设置互斥锁属性对象（**pthread_mutexattr_t**）的属性
##函数原型
```c
#include <pthread.h>

int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int kind);
```
##参数
- attr是要设置属性的互斥锁属性对象
- kind是互斥锁的种类（即属性）

##返回值
成功返回0，失败返回**非0**的错误代码

##属性种类
Linux支持3种互斥锁锁，它们的名称以后缀**_NP**结尾，表示non-portable，是不标准的锁名称。但实际上它们在实现的时候常常和POSIX标准的三种锁等价。

|Linux 互斥锁|对应的POSXI互斥锁
|-----|------
|PTHREAD_MUTEX_FAST_NP|PTHREAD_MUTEX_NORMAL
|PTHREAD_MUTEX_RECURSIVE_NP|PTHREAD_MUTEX_RECURSIVE
|PTHREAD_MUTEX_ERRORCHECK_NP|PTHREAD_MUTEX_ERRORCHECK
为保持程序兼容性，应该避免使用NP后缀的互斥锁名称。
###正常锁
（PTHREAD_MUTEX_NORMAL）

这种互斥锁不能自己检测死锁，如果一个线程尝试给已经加锁的互斥锁再次加锁，就会导致死锁。解锁一个被其他线程加锁的互斥锁会导致未定义结果。
>Linux中另有一互斥锁**PTHREAD_MUTEX_DEFAULT**与该锁等价。

###递归锁
（PTHREAD_MUTEX_RECURSIVE）
递归锁维护一个锁的数量。同一线程可以多次加锁，每加锁一次，锁的数量加1。解锁一次，锁的数量减一，直到锁的数量为0，该锁被释放。  
当线程解锁其他线程的递归锁的时候，解锁会失败。
###错误检查锁
（PTHREAD_MUTEX_ERRORCHECK）

锁的每一个操作都会进行错误检查，因此错误检查锁较慢，但是容易调试，便于发现一个应用程序在哪里违反了锁的规则。