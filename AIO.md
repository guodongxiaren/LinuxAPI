Linux 异步IO
>编译时链接实时库，使用选项 `-lrt`

##aiocb<kbd>struct</kbd>
aiocb是"asynchronous  I/O  control  block"的缩写。
```c
struct aiocb {
    /* The order of these fields is implementation-dependent */

    int             aio_fildes;     /* File descriptor */
    off_t           aio_offset;     /* File offset */
    volatile void  *aio_buf;        /* Location of buffer */
    size_t          aio_nbytes;     /* Length of transfer */
    int             aio_reqprio;    /* Request priority */
    struct sigevent aio_sigevent;   /* Notification method */
    int             aio_lio_opcode; /* Operation to be performed;
                                      lio_listio() only */

    /* Various implementation-internal fields not shown */
};

/* aio_lio_opcode: */
enum { LIO_READ, LIO_WRITE, LIO_NOP };
```
