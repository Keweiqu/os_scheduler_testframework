#include<stdio.h>
#include "userthread.h"
void func1(void *arg)
{
	thread_yield();
	printf("I am func1\n");
}

void func2(void *arg)
{
	thread_yield();
	printf("I am func2\n");
}

void func3(void *arg)
{
	thread_yield();
	printf("I am func3\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret = thread_create(func1, NULL);
	ret = thread_create(func2, NULL);
	ret = thread_create(func3, NULL);
	ret = thread_join(ret);
	printf("Main exiting\n");
	return 0;
}
