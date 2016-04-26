用指定属性初始化互斥锁
##函数原型
```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
          const pthread_mutexattr_t *restrict attr);
```
##参数
|形参|描述
|---|-----
|mutex|指向要初始化的互斥锁指针
|attr|指针类型，为要初始化的互斥锁定义属性，如果为NULL则为默认属性

restrict是C99关键字，视其变量不与其他变量关联，用于提高编译效率

------------
##PTHEREAD_MUTEX_INITIALIZER
静态初始化宏，初始化互斥锁，而无须调用pthread_mutex_init()
```c
#ifdef __PTHREAD_MUTEX_HAVE_PREV
# define PTHREAD_MUTEX_INITIALIZER \
  { { 0, 0, 0, 0, 0, 0, { 0, 0 } } }
    # ifdef __USE_GNU
    #  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, 0, { 0, 0 } } }
    #  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0, { 0, 0 } } }
    #  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, 0, { 0, 0 } } }
    # endif
#else
# define PTHREAD_MUTEX_INITIALIZER \
  { { 0, 0, 0, 0, 0, { 0 } } }
    # ifdef __USE_GNU
    #  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, 0, { 0 } } }
    #  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0, { 0 } } }
    #  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
      { { 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, 0, { 0 } } }
    # endif
#endif
```