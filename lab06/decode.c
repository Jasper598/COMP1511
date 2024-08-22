#include<stdio.h>

int change(int character,char line[27] );

int main(int argc,char *argv[]){
    int ch,i;
    i=0;
    char array[27];
    while(i<26){
        array[i]=argv[1][i];
        i++;
    }
    array[26]='\0';
    while((ch = getchar())!=EOF){
        ch = change(ch,array);
        putchar(ch);
    }
    
    return 0;
}
int change(int character,char line[27]){
    
    if(character >='a' && character<='z'){
       int num1=0;
       while(num1 < 26 && character != line[num1]){
           num1++;
       }
    character = num1 + 97;
    }
    else if ( character>='A' && character<='Z'){
       int num2=0;
       while(num2 < 26 && character + 32 != line[num2]){
          num2++;
        }
       character = num2 + 65;
    }
    return character;
}
