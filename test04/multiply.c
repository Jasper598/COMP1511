#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a,b,c;
    scanf("%d %d",&a,&b);
    c=a*b;
    if(c==0){
      printf("zero\n");
    }
    else if(c<0){
         printf("%d\n",abs(c));
    }
    else{
        printf("%d\n",c);
     }
     return 0;
}
