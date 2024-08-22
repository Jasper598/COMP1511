#include <stdio.h>

int main(void) {
    int x, y, sum;
    printf("How many scoops? ");
    scanf("%d",&x);
    printf("How many dollars does each scoop cost? ");
    scanf("%d",&y);
    sum=x*y;
    if (sum>10){
    printf("Oh no, you don't have enough money :(\n");
    }
    else {
    printf ("You have enough money!\n");
    }
    return 0;
 }
