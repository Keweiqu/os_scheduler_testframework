#include<stdio.h>
#include "userthread.h"
void func3(void *arg)
{
	printf("I am func3\n");
}

void func2(void *arg)
{
	int ret = thread_create(func3, NULL, 0);
	printf("func2 before calling yield\n");
	thread_yield();
	ret = thread_join(ret);
	printf("I am func2\n");
}

void func1(void *arg)
{
	int ret = thread_create(func2, NULL, 0);
	printf("func1 before calling yield\n");
	thread_yield();
	ret = thread_join(ret);
	printf("I am func1\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret = thread_create(func1, NULL, 0);
	ret = thread_join(ret);
	printf("Main exiting\n");
	return 0;
}
