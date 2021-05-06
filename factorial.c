/* factorial fact(n) = n*(n-1)*....2*1 */
#include <stdio.h>
#include <stdlib.h>

int y=2, m=9;

main()
{
    printf("y=%d and m= %d.\n", y, m);
    int n, m;
 for (;;)
 {
    printf("Enter a number: ");
    scanf("%d", &n);

    m = fact(n);
    printf("The factorial of %d is %d.\n", n, m);
    
 }
}

fact(n)
int n;
{
    if (n == 0)
        return(1);

    return(n * fact(n-1));
}

