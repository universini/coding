#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void write_buf (int fd, char *buf, char *str, int *num)
{
    int  len = 0;

    sprintf (buf, "%d:%s", *num, str);
    len = strlen (buf);
    write (fd, buf, len);

    return;
}

int main (void)
{
    char buf[16];
    int  fd;
    int  num = 1;
   
    fd = open ("/tmp/test.log",
               O_CREAT | O_APPEND | O_RDWR,
               0666);

    write_buf (fd, buf, "Sidde\r\n", &num);
    num = 2;
    write_buf (fd, buf, "Gowda\r\n", &num);

    close (fd);

    return 0;
}

