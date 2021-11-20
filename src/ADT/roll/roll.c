#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> // use time.h header file to use time  
      
int main()  
{  
    int num, i;  
    time_t t1; // declare time variable  
      
    printf(" Enter a number to set the limit for a random number \n");  
    scanf (" %d", &num);  
      
    /* define the random number generator */  
    srand ( (unsigned) time (&t1)); // pass the srand() parameter  
    printf("\n"); // print the space  
    /* generate random number between 0 to 50 */  
    for (i = 0; i <num; i++)  
    {  
        printf( "%d \n", rand() % 50);  
    }  
     return 0;  
}  