/*
 * 只包含ANSI C定义的头文件
 * POSIX的头文件在对应的目录下
 */
#ifndef _ANSI_H
#define _ANSI_H

#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    

void err_exit(char *error){
    perror(error);
    exit(EXIT_FAILURE);
}
#endif
