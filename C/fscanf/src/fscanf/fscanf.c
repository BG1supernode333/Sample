#include <stdio.h>

int main(void){

  FILE *fp;
  int i;
  float f;
  char c;
  char s[128];

  fp = fopen("test.txt", "r");
  if (fp == NULL){

    printf("fopen error!\n");
    return -1;

  }

  fscanf(fp, "%d %f %c %s", &i, &f, &c, s);

  printf("scan this data.\n");

  printf("i = %d\n", i);
  printf("f = %f\n", f);
  printf("c = %c\n", c);
  printf("s = %s\n", s);

  fclose(fp);

  return 0;

}
