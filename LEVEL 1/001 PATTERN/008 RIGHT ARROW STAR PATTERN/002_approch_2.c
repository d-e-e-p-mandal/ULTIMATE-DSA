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
    for(int i=0; i<2*n-1; i++) {
        int space = (i<n) ? i*2 : 2*(2*n-2-i);
        int star = (i<n) ? n-i: i-n+2;
        for(int j=0; j< space; j++) {
            printf(" ");
        }
        for(int j=0; j<star; j++) {
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