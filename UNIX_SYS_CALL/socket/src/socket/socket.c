#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void){

  int soc;

  soc = socket(AF_INET, SOCK_STREAM, 0);
  if (soc < 0){

    printf("socket error!\n");
    return -1;

  }

  printf("socket succeed.(soc = %d)\n", soc);

  close(soc);

  return 0;

}
