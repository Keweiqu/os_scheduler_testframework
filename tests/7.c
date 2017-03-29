#include<stdio.h>
#include "userthread.h"
static int count = 0;
void func(void *arg)
{
	printf("I am thread %d\n", count++);
}

int main()
{
	thread_libinit("fcfs");
	int ret, j_ret, i;
	for (i = 0 ;i < 99; i++) {
		ret = thread_create(func, NULL);
	}
	j_ret = thread_join(ret);
	printf("Main exiting\n");
	return 0;
}
