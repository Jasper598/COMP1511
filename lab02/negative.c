#include <stdio.h>
int main(void) {
    int x;
    scanf("%d", &x);
    if(x>0) {
      printf("You have entered a positive number.");
    }
    if(x==0) {
      printf("You have entered zero.");
    }
    if(x<0) {
      printf("Don't be so negative!");
    }
    printf("\n");

    return 0;
}
     
