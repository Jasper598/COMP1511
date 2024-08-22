// Exam Question 7
// exam_q7.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// One line summary of what this exercise does.
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    // TODO: Complete this question.
    int array[6][6];
    int i = 0;
    int character = getchar();
    while(i < 6){
        int j = 0;
        while (j<6) {
            array[i][j] = character;
            
            character = getchar();
            j++;
        }
        i++;
    }
    int a=0;
    while(a<6){
        int b =0;
        while(b<6) {
            character = array[a][b];
            putchar(character);
            b++;
        }
        a++;
    }
    printf("\n");
    return 0;
}
