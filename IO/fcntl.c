#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd;
    fd = open("a.c",O_RDWR);
    int flags;
    fcntl(fd,F_SETFD,FD_CLOEXEC);
    int fd2 = dup2(fd,5);
    int flags2;
    //测试fd标签是否能被复制
    flags = fcntl(fd,F_GETFD);
    flags2 = fcntl(fd2,F_GETFD);
    printf("%x\n",flags);
    if(flags&FD_CLOEXEC)
        printf("hello1\n");
    if(flags2&FD_CLOEXEC)
        printf("hello2\n");
    //测试fd状态标签是否能被复制
    flags = fcntl(fd,F_GETFL);
    if((flags&O_ACCMODE) == O_RDWR){
        printf("以可读可写模式打开\n");
    }

}
