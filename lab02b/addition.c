#include <stdio.h>

int main(void) {
    int x, y, sum;
    printf("Please enter two integers: ");
    scanf("%d %d",&x,&y);
    sum=x+y;
    printf("%d + %d = %d \n",x,y,sum);
    return 0;
}
