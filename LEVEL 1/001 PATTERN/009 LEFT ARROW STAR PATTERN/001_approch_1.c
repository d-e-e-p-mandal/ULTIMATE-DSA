/*
N = 5 
    *****
   ****
  ***
 **
*
 **
  ***
   ****
    *****
*/

#include<stdio.h>
void pattern(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            printf(" ");
        }
        for(int j=0; j<n-i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<=i; j++) {
            printf(" ");
        }
        for(int j=0; j<=i+1; j++) {
            printf("*");
        }
        printf("\n");
    }
}
int main() {
    int n;

    printf("Enter N : ");
    scanf("%d",&n);
    pattern(n);
    return 0;
}

/*Output :
Enter N : 7
Enter N : 7
      *******
     ******
    *****
   ****
  ***
 **
*
 **
  ***
   ****
    *****
     ******
      *******
*/