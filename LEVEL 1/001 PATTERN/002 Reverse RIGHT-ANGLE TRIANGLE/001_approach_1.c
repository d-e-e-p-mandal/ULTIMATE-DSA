/*
N = 3
    * 
  * * 
* * * 

N = 5
        * 
      * * 
    * * * 
  * * * * 
* * * * * 

*/


#include<stdio.h>

void triangelPattern(int n) {
    int i, j;
    for(i=0; i<n; i++) {
        // print space
        for(int j=0; j<n-i; j++) {
            printf("  ");
        }
        
        // print star
        for(j=0; j<=i; j++) 
            printf("* ");
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    // pattern
    triangelPattern(n);

    return 0;
}


/* Output :
Enter N : 5
* 
* * 
* * * 
* * * * 
* * * * * 

*/