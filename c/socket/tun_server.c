#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>

#define SIZE_BYTES 2000
#define SERV_PORT 22222

#define MAX_FD(a, b) ((a) > (b) ? (a) : (b))

char *program;

/*
 * my_error()
 *  - prins custom error messaage on stderr.
 */
void my_debug(char *msg, ...) {
  va_list argp;

  va_start(argp, msg);
  vfprintf(stderr, msg, argp);
  va_end(argp);
}

/*
 * Read wrapper
 */
int my_read(int fd, char *buf, int len) {
  int rbytes;

  if ((rbytes = read(fd, buf, len)) < 0) {
    perror("read()");
    exit(1);
  }

  return (rbytes);
}

/*
 * Write wrapper
 */
int my_write(int fd, char *buf, int len) {
  int wbytes;

  if ((wbytes = write(fd, buf, len)) < 0) {
    perror("write()");
    exit(1);
  }

  return (wbytes);
}

void usage(void) {
  fprintf(stderr, "usage:\n");
  fprintf(stderr, "%s -i <tun_name>\n", program);
  fprintf(stderr, "-h: help\n");
  exit(1);
}

/*
 * Create tun interafce.
 */
int tun_create(char *name, int flags) {
  struct ifreq if_req;
  int tun_fd, ret;

  if ((tun_fd = open("/dev/net/tun", O_RDWR)) < 0) {
    perror("open()");
    exit(1);
  }

  memset(&if_req, 0, sizeof(if_req));
  if_req.ifr_flags = flags;

  strncpy(if_req.ifr_name, name, IFNAMSIZ);

  if ((ret = ioctl(tun_fd, TUNSETIFF, (void *)&if_req)) < 0) {
    perror("ioctl()");
    close(tun_fd);
    return (ret);
  }

  return (tun_fd);
}

/*
 * main()
 *  - main function to create and accept connection from clients.
 */
int main(int argc, char *argv[]) {
  struct sockaddr_in serv_addr;
  struct sockaddr_in cli_addr;
  int sock_fd;
  uint16_t rbytes, wbytes, pkt_len;
  int cli_len, opt;
  int flags = IFF_TUN, enable = 1;
  int tun_id, net_id, max_fd;
  char buffer[SIZE_BYTES];
  char device[IFNAMSIZ];

  program = argv[0];

  while ((opt = getopt(argc, argv, "i:h")) > 0) {
    switch (opt) {
      case 'i':
        strncpy(device, optarg, IFNAMSIZ - 1);
        break;
      case 'h':
        usage();
        break;
      default:
        usage();
    }
  }

  if (device[0] == '\0') {
    puts("invalid option");
    usage();
  }

  /* create open tun device */
  tun_id = tun_create(device, flags | IFF_NO_PI);
  if (tun_id != -1) {
    my_debug("Tun device created (id: %d)\n", tun_id);
  }

  /* create a socket  for tcp connection */
  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket()");
    exit(1);
  }

  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) <
      0) {
    perror("setsockopt()");
    close(sock_fd);
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(SERV_PORT);

  if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind()");
    close(sock_fd);
    exit(1);
  }

  if (listen(sock_fd, 5) < 0) {
    perror("listen()");
    close(sock_fd);
    exit(1);
  }

  cli_len = sizeof(cli_addr);
  memset(&cli_addr, 0, sizeof(cli_addr));

  if ((net_id = accept(sock_fd, (struct sockaddr *)&cli_addr, &cli_len)) < 0) {
    perror("accept()");
    close(sock_fd);
    exit(1);
  }

  my_debug("Serever accepted a connection from client\n");

  max_fd = MAX_FD(net_id, tun_id) + 1;

  while (1) {
    int status;
    fd_set rd_set;

    FD_ZERO(&rd_set);
    FD_SET(tun_id, &rd_set);
    FD_SET(net_id, &rd_set);

    status = select(max_fd, &rd_set, NULL, NULL, NULL);

    if (status < 0 && errno == EINTR) {
      continue;
    }

    if (status < 0) {
      perror("select()");
      close(sock_fd);
      close(net_id);
      close(tun_id);
      exit(1);
    }

    /*
     * Handle net_id to tun_id data.
     */
    if (FD_ISSET(tun_id, &rd_set)) {
      /*
       * Read reply from net_id and write it to tun_id.
       */
      rbytes = my_read(tun_id, buffer, SIZE_BYTES);
      my_debug("Read %d bytes from tun_id\n", rbytes);

      pkt_len = htons(rbytes);
      wbytes = my_write(net_id, (char *)&pkt_len, sizeof(pkt_len));
      wbytes = my_write(net_id, buffer, rbytes);
      my_debug("Written %d bytes to net_id\n", rbytes);
    }

    /*
     * Handle tun_id to net_id data.
     */
    if (FD_ISSET(net_id, &rd_set)) {
      /*
       * Read reply from net_id and write it to tun_id.
       */
      rbytes = my_read(net_id, (char *)&pkt_len, sizeof(pkt_len));
      if (rbytes == 0) {
        break;
      }

      rbytes = my_read(net_id, buffer, ntohs(pkt_len));
      my_debug("Read %d bytes from net_id\n", rbytes);

      wbytes = my_write(tun_id, buffer, rbytes);
      my_debug("Written %d bytes to tun_id\n", rbytes);
    }
  }

  close(sock_fd);
  close(net_id);
  close(tun_id);
  return (0);
}
