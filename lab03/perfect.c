#include <stdio.h>
int main()
{
    int n,i,sum;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("The factors of %d are: \n",n);
    i=1;
    sum=0;
    while(i<=n)
    {
        if(n%i ==0){
        printf("%d\n",i);
        sum= sum+i;}
        i=i+1;
    }
    printf("Sum of factors = %d\n",sum);
    if (sum-n==n){
    printf("%d is a perfect number\n", n);
    }
    else{
        printf("%d is not a perfect number\n", n);
        }
    return 0;
}
