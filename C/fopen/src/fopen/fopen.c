#include <stdio.h>

int main(void){

  FILE *fp;

  fp = fopen("test.txt", "r");
  if (fp == NULL){

    printf("fopen error!\n");
    return -1;

  }

  printf("fopen succeed.(fp == %p)\n", fp);

  fclose(fp);

  return 0;

}
