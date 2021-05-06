// compile using: gcc -g -w pointersgdb.c
// Use gdb to run the code, hit ctrl-C to cause signal
// use gdb to verify variables' memory address
// use info address some-symbol (symbol are variable names)
// use x/repeatcount address to display some memory.
// execute the program and see its map in the memory.

#include <stdio.h>
#include <time.h>

// define few ANSI terminal escape strings to change color and intensity

#define RED "\x1b[31;1m"
#define GREEN "\x1b[32;1m"
#define WHITE "\x1b[37;0m"

// declare global variables
int myvar;	//declare a variable "myvar" of type int   
// declare a variable of type pointer to int and assign it value of 0
// NULL is defined as (void *) 0 in stdio.h. Reading or writing memory at address 0 usually causes fault

int *myptr = 0; 
     
struct timespec ts_req, ts_rem; // define some structures for the nanosleep() function

int main (void)  
{   
myvar = 10;  // variable myvar now has value of 10
//Output the memory address of variable myvar
printf("Address of variable myvar is" GREEN " %p\n" WHITE, &myvar);
//Output the value of myvar	
printf("Value (stored at above address) of variable myvar is   " GREEN "%d\n" WHITE, myvar);
myptr = &myvar;
*myptr = 3;
//Output the address of the myptr   
printf("Adddress of variable myptr is" GREEN " %p\n" WHITE, &myptr);  
//Value at the address   
printf("Value stored at memory address pointed to by myptr is " GREEN" %d\n" WHITE, *myptr);
				
printf ("Kill me when ready with ctrl-C\n");
// get stuck here in an endless loop
  while (1)
    {
      // but without consuming processor time!
      ts_req.tv_sec = 1;
      ts_req.tv_nsec = 0;
      nanosleep (&ts_req, &ts_rem);
    }
}
