# 笔记
### 纤程
```c
可以由用户态决定调用关系的线程
栈需要由应用程序提供

头文件: #include <ucontext.h>
保存当前状态:   getcontext(ucontext_t *ucp)   
调用:   sercontext(ucontext_t *ucp)
创建:   makecontext(ucontext_t *ucp,void(* func)(),int argc)

纤程状态并不会保存在内核中的TCB里，而是保存在参数ucp里
```