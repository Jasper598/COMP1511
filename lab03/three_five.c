#include <stdio.h>

int main(void)
{
  int a=1;
  int b;
  printf("Enter number: ");
  scanf("%d",&b);
   
   while (a<b) {
         if(a%5==0||a%3==0){
            printf("%d\n", a);
         }
         a=a+1;
    }
return 0;
}
