#include <stdio.h>
int main(void){
    double a,b,c;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a){
       printf("triangle\n");
       }
     else{printf("not a triangle\n");}
     return 0;
     }

