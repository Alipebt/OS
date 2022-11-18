#include <bits/sigstack.h>
#include <stdio.h>
#include <ucontext.h>

ucontext_t utp, utc;
int c;

void produce()
{
    if (c <= 100)
    {
        printf("Produce...\tc = %d\n", ++c);
    }
    else
    {
        printf("FULL\n");
    }
    setcontext(&utc);
}

void consumer()
{
    if (c > 0)
    {
        printf("Consumer...\tc = %d\n", --c);
    }
    else
    {
        printf("EMPTY\n");
    }
    setcontext(&utp);
}

int main()
{
    char stackp[SIGSTKSZ];
    char stackc[SIGSTKSZ];

    getcontext(&utp);
    utp.uc_link = NULL;
    utp.uc_stack.ss_sp = stackp;
    utp.uc_stack.ss_size = sizeof(stackp);
    makecontext(&utp, (void (*)(void))produce, 0);

    getcontext(&utc);
    utc.uc_link = NULL;
    utc.uc_stack.ss_sp = stackc;
    utc.uc_stack.ss_size = sizeof(stackc);
    makecontext(&utc, (void (*)(void))consumer, 0);

    setcontext(&utp);

    return 0;
}