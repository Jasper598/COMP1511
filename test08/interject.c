// COMP1511 Week 7 Test: Interject
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// This program adds interjections to strings.

#include <stdio.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    char temp1[MAX_SIZE];
    int i = 0;
    while(i<index){
        temp1[i]=str[i];
        i++;
    }
    int j=0;
    while(interject[j] != '\0'){
         temp1[i+j]=interject[j];
         j++;
    }
    while(str[i] != '\0'){
        temp1[i+j]=str[i];
        i++;
    }
    temp1[i+j]='\0';
    int n=0;
    while(temp1[n] != '\0'){
        str[n] = temp1[n];
        n++;
    }
    str[n]='\0';
         
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
