# 笔记
### 纤程:

可以由用户态决定调用关系的线程
栈需要由应用程序提供

```c
头文件: #include <ucontext.h>
保存当前状态:   getcontext(ucontext_t *ucp)   
调用:   sercontext(ucontext_t *ucp)
创建:   makecontext(ucontext_t *ucp,void(* func)(),int argc)
```

纤程状态并不会保存在内核中的TCB里，而是保存在参数ucp里

在多线程程序中使用 fork，可能会导致一些意外：

* 子进程中只剩下一个线程，它是父进程中调用 fork 的线程的副本构成。这意味着在多线程环境中，会导致“线程蒸发”，莫名奇妙的失踪！
* 因为线程蒸发，它们所持有的锁也可能未释放，这将导致子进程在获取锁时进入死锁。