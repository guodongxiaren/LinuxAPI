/*
 * 经测试在msgget未指定id权限的时候，缺省mode为0000。
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "../lib/ansi.h"
int main(int argc,char **argv){
    key_t key;
    int id;
    if((key = ftok(".",'k')) < 0){
        err_exit("ftok error");
    }
    printf("key:%d\n",key);
    if((id = msgget(key,IPC_CREAT|IPC_EXCL)) < 0){
        err_exit("msgget error");
    }
    printf(" id:%d\n",id);
    struct msqid_ds buf;
    if(msgctl(id,IPC_STAT,&buf) < 0){
        err_exit("msgctl error");
    }
    printf("----------ipc_perm----------\n");
    printf("__key:\t%d\n",buf.msg_perm.__key);
    printf("  uid:\t%d\n",buf.msg_perm.uid);
    printf("  gid:\t%d\n",buf.msg_perm.gid);
    printf(" cuid:\t%d\n",buf.msg_perm.cuid);
    printf(" guid:\t%d\n",buf.msg_perm.cgid);
    printf(" mode:\t%o\n",buf.msg_perm.mode);
    printf("----------------------------\n");
}

