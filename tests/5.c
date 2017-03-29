#include<stdio.h>
#include "userthread.h"
void func1(void *arg)
{
	printf("I am func1\n");
}

void func2(void *arg)
{
	printf("I am func2\n");
}

void func3(void *arg)
{
	printf("I am func3\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret1 = thread_create(func1, NULL, 0);
	int ret2 = thread_create(func2, NULL, 0);
	int ret = thread_join(ret1);
	int ret3 = thread_create(func3, NULL, 0);
	printf("Main exiting\n");
	return 0;
}
