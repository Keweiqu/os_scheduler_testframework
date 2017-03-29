#include<stdio.h>
#include "userthread.h"
int ret1, ret2, ret3;
void busy_wait(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 100000; j++) {
    }
  }
}

void func1(void *arg) {
  busy_wait(3);
  thread_join(ret1);
  printf("I am func1\n");
}

void func2(void *arg) {
  busy_wait(2);
  thread_join(ret2);
  printf("I am func2\n");
}

void func3(void *arg) {
  busy_wait(1);
  thread_join(ret3);
  printf("I am func3\n");
}

void func4(void *arg)  {	
  printf("I am func4\n");
}

void func5(void *arg) {
  printf("I am func5\n");
}

void func6(void *arg) {
  printf("I am func6\n");
}

int main() {
  thread_libinit(SJF);
  int retfirst = thread_create(func1, NULL);
  int ret = thread_create(func2, NULL);
  ret = thread_create(func3, NULL);
  ret1 = thread_create(func4, NULL);
  ret2 = thread_create(func5, NULL);
  ret3 = thread_create(func6, NULL);
  busy_wait(4);
  ret = thread_join(retfirst);
  printf("Main exiting\n");
  return 0;
}