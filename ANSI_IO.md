##文件数据格式
分为：
* ASCII文件（文本文件，字符文件）
* 二进制文件

区别：  
比如一个数字-1000，在文本文件中分别存储五个字符的二进制码。而在二进制文件中直接存储该数字的二进制值。  
文本文件更直观(可以直接用cat命令查看，或用任何编辑器打开观看)，但二进制文件更节约存储空间。
##FILE文件指针
```c
//在/usr/inclue/stdio.h中
typedef _IO_FILE FILE;
//在/usr/inclue/libio.h中
struct _IO_FILE{
  char* _IO_read_ptr;	/* Current read pointer */
  char* _IO_read_end;	/* End of get area. */
  char* _IO_read_base;	/* Start of putback+get area. */
  char* _IO_write_base;	/* Start of put area. */
  char* _IO_write_ptr;	/* Current put pointer. */
  char* _IO_write_end;	/* End of put area. */
  char* _IO_buf_base;	/* Start of reserve area. */
  char* _IO_buf_end;	/* End of reserve area. *
...
  int _filene;          /*文件描述符*/
};
```
##注意事项
文件操作结束后，都应该：
* 关闭打开的文件，fclose(fp);
* 文件指针置空，fp=NULL；
