#include<stdio.h>
#include<math.h>
int main(void) {
    double a,b,c;
    double s;
    double A;
    printf("Enter side 1: ");
    printf("Enter side 2: ");
    printf("Enter side 3: ");
    scanf("%lf%lf%lf",&a,&b,&c);
    if((a+b>c)&&(a+c>b)&&(b+c>a)){
    s=(a+b+c)/2;
    A=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area = %f",A);
    }
    else {
     printf("Error: triangle inequality violated.");
     }
     printf("\n");
     return 0;
  }
    
