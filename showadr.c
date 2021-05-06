#include <stdio.h>

void
main(void)
{
  int onstack;
  fprintf(stderr, "my pid is %d\n", getpid());
  fprintf(stderr, "fun main() is at   0x%08lx\n", (unsigned long) &main);
  fprintf(stderr, "stack var  is at   0x%08lx\n", (unsigned long) &onstack);
  fprintf(stderr, "Hit Ctrl-C to exit.\n");
  while (1)
    sleep (1);
}
