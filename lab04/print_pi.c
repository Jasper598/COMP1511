#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    int a,i;
    i=0;
    scanf("%d",&a);
    while(i<a){
         if(i==1){
           printf(".");}
         printf("%d",pi[i]);
         i=i+1;
         }
         printf("\n");

    return 0;
}
