#include<stdio.h>
#include<math.h>

#define max_length 1000

void Euclidean_distance(int size, int array1[max_length],int array2[max_length]);

int main(int argc, char *argv[]) {
    int size;
    printf("Enter vector length: ");
    scanf("%d", &size);
    int array1[max_length]; 
    printf("Enter vector 1: ");   
    int i = 0;
    while (i < size) {
        scanf("%d", &array1[i]);
        i = i + 1;
    }
    int array2[max_length];
    printf("Enter vector 2: ");
    int j = 0;
    while (j < size) {
        scanf("%d", &array2[j]);
        j++;
    }
    Euclidean_distance(size,array1,array2);
    return 0;
}
void Euclidean_distance(int size, int array1[max_length],int array2[max_length]){
     double a,c;
     int b;
     a = 0;
     b = 0;
     c = 0;
     while(b<size){
       a=pow(array2[b]-array1[b],2);
       b=b+1;
       c=c+a;}
     double distance;
     distance=sqrt(c);
     printf("Euclidean distance = %lf\n",distance);
}
