#include <stdio.h>
#include <time.h>

int main(void){

  time_t t;

  t = time(NULL);
  printf("UNIX Time: %d\n", t);

  return 0;

}
