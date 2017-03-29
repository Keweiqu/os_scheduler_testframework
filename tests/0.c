#include<stdio.h>
#include "userthread.h"
void func(void *arg) {
  printf("I am func\n");
}

int main() {
  thread_libinit(FIFO);
  int ret = thread_create(func, NULL, 0);
  int j_ret = thread_join(ret);
  printf("Main exiting\n");
  return 0;
}
