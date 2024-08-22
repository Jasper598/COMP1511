#include <stdio.h>
#include <string.h>
#define MAX_SIZE 4096
int main(void) {
    printf("Enter a string: ");
    char str[MAX_SIZE];
    fgets(str,MAX_SIZE,stdin);
    int n = strlen(str);
    int i = 0;
    char str1[MAX_SIZE];
    if(n>1){
        while(i < (n)/2){   
            str1[i]=str[i];
            i++;
        }
        str1[i]='\0';
        char str2[MAX_SIZE];
        while (i >= (n)/2 && i < n) {
            str2[n-1-i]=str[i-1];
            i++;
        }
        str2[(n)/2]='\0';
        int j = 0;

        while(j<(n)/2){
            if(str1[j]!=str2[j]){
                printf("String is not a palindrome\n");
                return 0;
            }
            else{ j++; }
        }
    }
    printf("String is a palindrome\n");
    return 0;
}
