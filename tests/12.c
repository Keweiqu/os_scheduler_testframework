#include<stdio.h>
#include "userthread.h"
void func1(void *arg)
{
	printf("I am func1\n");
}

void func2(void *arg)
{
	thread_yield();
	printf("I am func2\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret1 = thread_create(func1, NULL);
	int ret = thread_create(func2, NULL);
	ret = thread_join(ret1);
	printf("Main exiting\n");
	return 0;
}
