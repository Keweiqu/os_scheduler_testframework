#include<stdio.h>
#include "userthread.h"
int join;
void busy_wait(int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 100000; j++) {
		}
	}
}

void func1(void *arg)
{
	busy_wait(3);
	thread_yield();
	printf("I am func1\n");
}

void func2(void *arg)
{
	busy_wait(2);
	thread_yield();
	printf("I am func2\n");
}

void func3(void *arg)
{
	busy_wait(1);
	thread_yield();
	printf("I am func3\n");
}

void func4(void *arg) 
{	
	printf("I am func4\n");
}

int main()
{
	thread_libinit(SJF);
	int ret = thread_create(func1, NULL);
	ret = thread_create(func2, NULL);
	ret = thread_create(func3, NULL);
	ret = thread_create(func4, NULL);
	join = ret;
	busy_wait(4);
	ret = thread_join(ret);
	printf("Main exiting\n");
	return 0;
}
