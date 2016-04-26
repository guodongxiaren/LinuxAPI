Linux环境编程API
===========

##内容概要
C语言API包含*部分*标准C的API、POSIX标准的系统编程API(一些Linux独有的系统API会单独注明)。
##头文件源码
大部分头文件源码在**/usr/include**目录下。
##安装man手册
因为涉及到大量的POSIX编程。所以最好下载POSIX函数的man手册。
###Ubuntu
```
sudo apt-get install manpages-posix        
sudo apt-get install manpages-posix-dev
```
默认安装了**manpages-dev**，所以不装POSIX的man手册是可以查看绝大部分API的。  
但是不装的话，有些API是不能看到的，比如**posix_spawn**函数。
###CentOS
```
yum install man-pages.noarch
```

---------
>关于目录
>>右侧的目录并非以**函数**为索引依据，主要是以系统的man手册页面为索引依据。   
比如[exec](./exec)里面包含6个函数、[pipe](./pipe)里面包含pipe()和pipe2()两个函数，但是它们都是属于一个man页面中。