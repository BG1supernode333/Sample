#include <stdio.h>

int main(void){

  FILE *fp;
  int i;
  float f;
  char c;
  char s[128];

  fp = fopen("test.txt", "w");
  if (fp == NULL){

    printf("fopen error!\n");
    return -1;

  }

  printf("i: ");
  scanf("%d", &i);

  printf("f: ");
  scanf("%f", &f);

  printf("c: ");
  scanf("%*c%c", &c);

  printf("s: ");
  scanf("%s", s);

  fprintf(fp, "%d %f %c %s", i, f, c, s);

  printf("print this data.\n");

  fclose(fp);

  return 0;

}
