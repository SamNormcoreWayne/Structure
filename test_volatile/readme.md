## Test volatile/atomic/mutex in multithreading 

OS: Ubuntu 18.04.2 LTS [WSL]
Complier: g++ (gcc 7.4.0)
Args: "-std=c++17", "-pthread", ("-O2")

本来对volatile这个关键字没什么理解直到在秋招面某流量厂被提问了。可能是因为贵厂用的是Java吧。
提问的时候还贴心的加了一句你对**C++中**的volatile有什么理解。没学过嵌入式的我可真是打扰了。

1. naive:
    * 无优化时可正常退出
    * O2优化死循环
2. volatile bool flag:
    * O2优化正常退出？
    * 根据大佬的博客https://zhuanlan.zhihu.com/p/33074506，尽管if(bool...)不会被优化，但是优化时仍然可能变换thread2中执行顺序

3. atomic:
4. mutex:
    正常