#include <stdio.h>
#include <string.h>

#define SIZE 1024
                         
int main(int argc , char *argv[]) {
    
    //TODO: Your solution should go here
    //You can use functions if you would like to
    char line[SIZE]={0};
    fgets(line,1024,stdin);
    
    int i = 1;
    while (i < argc) {
        int j = 0;
        while(argv[i][j] != '\0'&& line[j] != '\0') {
            if (argv[i][j] == line[j]) {
                printf("%d %s\n", j, argv[i]);
                break;
            }
            j++;
        }
        i++;
    }
    return 0;
}

