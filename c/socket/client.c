#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd = 0;
  int n = 0;
  char rbuff[1024];
  struct sockaddr_in saddr;

  if (argc != 2) {
    printf("\n Usage: %s <ip of server> \n", argv[0]);
    return 1;
  }

  memset(rbuff, '0', sizeof(rbuff));

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Error : Could not create socket \n");
    return 1;
  }

  memset(&saddr, '0', sizeof(saddr));

  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(5000);

  if (inet_pton(AF_INET, argv[1], &saddr.sin_addr) <= 0) {
    printf("\n inet_pton error occured\n");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
    printf("\n Error : Connect Failed \n");
    return 1;
  }

  while ((n = read(sockfd, rbuff, sizeof(rbuff) - 1)) > 0) {
    rbuff[n] = 0;
    if (fputs(rbuff, stdout) == EOF) {
      printf("\n Error : Fputs error\n");
    }
  }

  if (n < 0) {
    printf("\n Read error \n");
  }

  return 0;
}
