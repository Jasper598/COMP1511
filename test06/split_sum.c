#include <stdio.h>

#define MAX_SIZE 100

/**
 * The array is split into two parts by the index passed in so 
 * the first part has indexes until the index non-inclusive and 
 * the second part has indexes including the index till the end of the array.
 * This function finds the sum of the first part and puts it into the first sum,
 * and finds the sum of the second part and puts it into the second sum.
 *
 * Takes in 
 * the array "array", 
 * the array's length "length", 
 * the index that splits the array into two parts "index", 
 * a pointer to where the value of the first part of the array's sum should be 
 * placed "first_sum" and 
 * a pointer to where the value of the second part of the array's sum should be 
 * placed "second_sum".
 *
 * Returns nothing.
 */
void split_sum(int array[], int length, int index, int *first_sum, int *second_sum) {
   int i=0;
   int a=0;
   int b=0;
   while(i<index){
      a=a+ array[i];
      i++;
   }
   while(i>=index && i<length){
      b=b + array[i];
      i++;
    }
     *first_sum =  a;
     *second_sum =  b;

    return;
}


int main(void) {

    printf("Enter length: ");
    int length;
    scanf("%d", &length);

    printf("Enter array values: ");
    int i = 0;
    int array[MAX_SIZE] = {0};
    while (i < length) {
        scanf("%d", &array[i]);
        i += 1;
    }

    printf("Enter index: ");
    int index;
    scanf("%d", &index);
    
    int first_sum;
    int second_sum;
    split_sum(array, length, index, &first_sum, &second_sum);

    printf("First sum: %d\n", first_sum);
    printf("Second sum: %d\n", second_sum);
    
    return 0;
}
