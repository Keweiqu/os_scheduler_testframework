#include<stdio.h>
#include "userthread.h"
int join[2];
void func1(void *arg)
{
	int ret = thread_join(join[0]);
	printf("I am func1\n");
}

void func2(void *arg)
{
	int ret = thread_join(join[1]);
	printf("I am func2\n");
}

void func3(void *arg)
{
	printf("I am func3\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret1 = thread_create(func1, NULL);
	int ret = thread_create(func2, NULL);
	join[0] = ret;
	ret = thread_create(func3, NULL);
	join[1] = ret;
	ret = thread_join(ret1);
	printf("Main exiting\n");
	return 0;
}
