#include<stdio.h>

int main(void){
    printf("Enter integer: ");
    int a;
    scanf("%d",&a);
    printf("Enter integer: ");
    int b;
    scanf("%d",&b);
    printf("Enter integer: ");
    int c;
    scanf("%d",&c);
    if(a>=b&&b>=c){
       printf("Middle: %d\n",b);
       }
     else if(c>=b&&b>=a){
       printf("Middle: %d\n",b);
       }
      else if(b>=a&&a>=c){
       printf("Middle: %d\n",a);
       }
       else if(c>=a&&a>=b){
       printf("Middle: %d\n",a);
       }
       else if(a>=c&&c>=b){
       printf("Middle: %d\n",c);
       }
        else if(b>=c&&c>=a){
       printf("Middle: %d\n",c);
       }
     return 0;
}
       
