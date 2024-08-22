#include <stdio.h>

int main(void) {
    int ch1;
    int ch2;
    int i = 0;
    while ((ch1 = getchar()) != EOF) {
        if (i %2 == 1) {
            if (ch1 >= ch2) {
                putchar(ch2);
            }
            else if(ch1 < ch2) {
                putchar(ch1);
            }
        }
        else {
            ch2 = ch1;
        }
        i++;
    }
    putchar('\n');
    return 0;
}                    
