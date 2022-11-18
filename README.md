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

* fork的时候只复制当前线程到子进程。这意味着在多线程环境中，会导致“线程蒸发”。
* 因为线程蒸发，它们所持有的锁也可能未释放，这将导致子进程在获取锁时进入死锁。
* fork的时候会复制锁的状态，如果此时恰好某个锁被锁了，那么在fork产生的子进程中也是lock的状态。