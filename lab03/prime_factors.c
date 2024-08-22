#include<stdio.h>

int main(void)
{
 int n,k,a,m;
 a=0;
 k=2;

 printf("Enter number: ");
 scanf("%d",&n);
 m=n;   
    while(k<n){
     while(m%k==0){
    if (a==0){ 
    printf("The prime factorization of %d is:\n",n);
    }
    printf("%d",k);
    m=m/k;
    a=1;   
    if (m>1){
    
    printf(" * ");
    }
    }
    k=k+1;
    }
    if(a==0)
  {
  printf("%d is prime\n",n);}

    
   
       else { printf(" = %d\n",n);}
    

      
  return 0;
}
