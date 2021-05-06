#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <errno.h>

/*
malloc
mmap
mlock
brk
sbrk
*/

#define BIGMEM (1024*1024*64) // 512MB - lots of mem
/* show the kernel PCB and page tables on ARM */
#define BIGSTACK (100000)

int *pAllocated;
unsigned long TotalAllocated;

void
fillstack(int total)
{
  char cArray[BIGSTACK];
  total = total + BIGSTACK;
  fprintf (stderr, "used stack total = %8d\n", total);
  usleep (10000); // sleep 100 msec
  fillstack(total);
}

int opt_stack = 0;
int opt_malloc = 0;

int
main(int argc, char *argv[])
{
  int VarOnStack;

  int i;

  for ( i=0 ; i<argc ; i++ )
    {
      if ( strcmp(argv[i],"--stack")==0 )
	opt_stack = 1;
      if ( strcmp(argv[i],"--malloc")==0 )
	opt_malloc = 1;
    }
  if ( opt_stack + opt_malloc == 0 )
    {
      fprintf (stderr, "need options: --malloc --stack (either one or both)\n");
      _exit(-1);
    }


  TotalAllocated = 0;
  pAllocated = malloc (4096); // allocate one page
  fprintf(stderr, "fun main() is at   %p\n", &main);
  fprintf(stderr, "stack end is near  %p\n", &VarOnStack);
  while (opt_malloc)
    {
      usleep (100000); // sleep 100 msec
      pAllocated = malloc(BIGMEM);
      if ( pAllocated )
	{
	  TotalAllocated += BIGMEM/(1024*1024);
	  fprintf(stderr, "malloc() from heap %p total %luMB\n", pAllocated, TotalAllocated);
        }
      else
	{
	  fprintf (stderr, "malloc() failed %d\n", errno, strerror(errno));
	  break;
	}
    }
  // now try to fill up the stack
  if ( opt_stack)
    fillstack(0);

}


