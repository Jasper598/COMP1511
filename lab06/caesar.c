#include<stdio.h>
#include<stdlib.h>
int change(int character, int shift);

int main(int argc, char *argv[]){

    int K = atoi(argv[1]);
    int ch;
    while((ch = getchar())!=EOF){
        ch = change(ch,K);
        putchar(ch);
    }
    
    return 0;
}

int change(int character, int shift){
    if(character >= 97 && character <=122) {
       character = character + shift;
       while(character > 122){
            character-=26;
       }
       while(character < 97){
            character+=26;
       }
     }
     else if (character >= 65 && character <= 90){
        character = character + shift;
        while(character >=  65 && character <=90) {
            character -=26;
        }
        while (character > 90){
            character -= 26;
        }
        while (character <65){
            character +=26;
        }
    }
    return character;
}
