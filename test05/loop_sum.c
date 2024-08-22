#include <stdio.h>

int main(void) {
    int i, j, a,howMany;
    printf("How many numbers: ");
    scanf("%d", &howMany);
       i = 0;
       j = 0;
       a = 0;
    while (i < howMany) {
        scanf("%d", &a);
        j=j+a;
        i = i + 1;
    }
    printf("The sum is: %d\n",j);
    return 0;
}
    
