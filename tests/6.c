#include<stdio.h>
#include "userthread.h"
void func(void *arg)
{
	printf("I am func\n");
}

int main()
{
	thread_libinit("fcfs");
	int ret = thread_create(func, NULL, 0);
	int j_ret = thread_join(ret+1);
	printf("Main exiting - Join returned : %d\n", j_ret);
	return 0;
}
