#include <stdio.h>

int main(void){

  int i;
  float f;
  char c;
  char s[128];

  printf("i: ");
  scanf("%d", &i);

  printf("f: ");
  scanf("%f", &f);

  printf("c: ");
  scanf("%*c%c", &c);

  printf("s: ");
  scanf("%s", s);

  printf("\n");

  printf("i = %d\n", i);
  printf("f = %f\n", f);
  printf("c = %c\n", c);
  printf("s = %s\n", s);

  return 0;

}
