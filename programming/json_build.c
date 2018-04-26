#include <stdio.h>
#include <string.h>

void main (void)
{
    char j[512];
    int  l = 0;

    sprintf (j, "%s", "{\"host_name\": \"sjc-004\", \"domains\": [{\"domain_name\": \"rocketfuel.com\",\"rev_stats\":{\"time_stamp\": 1406236941,\"page_count\": 0,\"bytes_count\": 0,\"attack_count\": 0,\"status\": \"success\"}},{\"domain_name\": \"universini.com\",\"rev_stats\":{\"time_stamp\": 1406236941,\"page_count\": 0,\"bytes_count\": 0,\"attack_count\": 0,\"status\": \"success\"}},"); 

    l = (int)strlen(j);
    printf ("length: %d\n", l);

    j[l-1] = ']';
    j[l] = '}';

    printf ("json: %s\n", j);
}
