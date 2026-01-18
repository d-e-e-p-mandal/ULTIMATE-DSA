/*
N = 5
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

#include<stdio.h>
void pattern(int n) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if((i+j)%2 == 0) {
                printf("1 ");
            }
            else printf("0 ");
        }
        printf("\n");
    }
}
int main() {
    int n;

    printf("Enter value of N : ");
    scanf("%d",&n);

    pattern(n);
    return 0;
}

/*Output :
Enter value of N : 7
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 
0 1 0 1 0 1 
1 0 1 0 1 0 1 
*/