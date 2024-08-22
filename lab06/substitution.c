#include<stdio.h>
#include<ctype.h>

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
       character = line[character - 97];
    }
    else if ( character>='A' && character<='Z'){
       character = toupper(line[character - 65]);
    }
    
    return character;
}
