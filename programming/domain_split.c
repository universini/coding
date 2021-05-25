#include <stdio.h>
#include <string.h>

char nt[32];

int main(void) {
  char *t = NULL;
  char *np = NULL;
  char s[] = "dyn.sjc.revsw.net";

  np = strtok(s, ".");

  sprintf(nt, "%s.com", np);

  puts(nt);
}
