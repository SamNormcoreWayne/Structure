## Test volatile/atomic/mutex in multithreading 

OS: Ubuntu 18.04.2 LTS [WSL]
Complier: g++ (gcc 7.4.0)
Args: "-std=c++17", "-pthread", ("-O2")

1. naive:
    * 无优化时可正常退出
    * O2优化死循环
2. volatile bool flag:
    * O2优化正常退出？
    * 根据大佬的博客https://zhuanlan.zhihu.com/p/33074506，尽管if(bool...)不会被优化，但是优化时仍然可能变换thread2种执行顺序

3. atomic:
4. mutex:
    正常