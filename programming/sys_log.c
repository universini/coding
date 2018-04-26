#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

#define PCM_LOG_ERROR(format, args...) \
    do { \
        openlog ("pcmp_error", LOG_PID|LOG_CONS, LOG_USER); \
        syslog (LOG_ERR, "[%s]: "format, __TIME__, args); \
        closelog (); \
    } while (0)

int main (void)
{
    int a =10;
    char buf[128];

    PCM_LOG_ERROR ("%s: value received %d", __FUNCTION__, a);

    return 0;
}
