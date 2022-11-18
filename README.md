# 笔记
### 纤程
```c
可以由用户态决定调用关系的线程
栈需要由应用程序提供

头文件: #include <ucontext.h>
调用:   sercontext(ucontext_t *ucp)
创建:   makecontext(ucontext_t *ucp,void(* func)(),int argc)
```