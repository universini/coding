#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int listenfd = 0;
  int connfd = 0;
  struct sockaddr_in saddr;
  char sbuff[1025];
  time_t ticks;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&saddr, '0', sizeof(saddr));
  memset(sbuff, '0', sizeof(sbuff));

  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(5000);

  bind(listenfd, (struct sockaddr *)&saddr, sizeof(saddr));

  listen(listenfd, 10);

  while (1) {
    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);

    ticks = time(NULL);
    snprintf(sbuff, sizeof(sbuff), "%.24s\r\n", ctime(&ticks));
    write(connfd, sbuff, strlen(sbuff));

    close(connfd);
    sleep(1);
  }
}
