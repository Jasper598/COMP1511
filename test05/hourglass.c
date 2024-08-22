#include <stdio.h>
int main(void){
    int n;
    printf("Please enter a size: ");
    scanf("%d",&n);
    int x,y;
    y=0;
    int b;
    b=(n-1)/2;
    while(y<b){ 
     x=0;             
       while(x<n){
             if(x<n-y&&x>=y&&y>0){
             printf("%d ",y);
            }
            else{
            printf("- ");}
           x=x+1;
            }   
         printf("\n");
         y=y+1;
      }
      if(y==b){
            y=y+1;
            
          } 
       int c; 
       while(y>b&&y<=n){ 
        x=0;  
        c=n-y;                 
       while(x<n){
             if(x<y&&x>=n-y&&y<n){
             printf("%d ",c);
            }
            else{
            printf("- ");}
           x=x+1;
            }   
         printf("\n");
         y=y+1;
      }
       
return 0;
}
         
         
