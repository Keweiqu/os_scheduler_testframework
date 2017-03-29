#include<stdio.h>
#include "userthread.h"
int join;
void func1(void *arg)
{
	printf("I am func1\n");
}

void func2(void *arg)
{
	int ret = thread_join(join);
	printf("I am func2\n");
}

void func3(void *arg)
{
	printf("I am func3\n");
}

void func4(void *arg)
{
	printf("I am func4\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret = thread_create(func1, NULL);
	ret = thread_create(func2, NULL);
	ret = thread_create(func3, NULL);
	int ret1 = ret;
	ret = thread_create(func4, NULL);
	join = ret;
	ret = thread_join(ret1);
	printf("Main exiting\n");
	return 0;
}
