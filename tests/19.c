#include<stdio.h>
#include "userthread.h"
int ret;
void func2(void *arg)
{
	int ret1 = thread_join(ret);
	printf("I am func2\n");
}

void func1(void *arg)
{
	printf("func1 before calling yield\n");
	thread_yield();
	printf("I am func1\n");
}

int main()
{
	thread_libinit(FIFO);
	ret = thread_create(func1, NULL);
	int ret1 = thread_create(func2, NULL);
	ret1 = thread_join(ret1);
	printf("Main exiting\n");
	return 0;
}
