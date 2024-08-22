////////////////////////////////////////////////////////////////////////
// CP1521 22T1 --- Assignment 2: `chicken', a simple file archiver
// <https://www.cse.unsw.edu.au/~dp1092/22T1/assignments/ass2/index.html>
//
// Written by YOUR-NAME-HERE (z5555555) on INSERT-DATE-HERE.
//
// 2022-14-03   v1.0     

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "chicken.h"


// ADD ANY extra #defines HERE
#define MAGIC_NUMBER 0x63
#define MASK 0b11111111

// ADD YOUR FUNCTION PROTOTYPES HERE

// print the files & directories stored in egg_pathname (subset 0)
//
// if long_listing is non-zero then file/directory permissions, formats & sizes are also printed (subset 0)

void list_egg(char *egg_pathname, int long_listing) {

    // REPLACE THIS CODE WITH YOUR CODE

    //printf("list_egg called to list egg: '%s'\n", egg_pathname);
    FILE *fp = fopen(egg_pathname, "r");
    if (fp == NULL) {
        perror(egg_pathname);
        exit(1);
    }
    int first_byte;
    while ((first_byte = fgetc(fp)) != EOF) {
        int egg_format = fgetc(fp);
        int i = 0;
        int permissions[10];
        while (i < 10) {
            permissions[i] = fgetc(fp);
            i++;
        }
        int pathname_length = fgetc(fp);
        pathname_length = pathname_length + (fgetc(fp) << 8);
        i = 0;
        int pathname[pathname_length];
        while(i < pathname_length){           
            pathname[i] = fgetc(fp);
            i++;
        }
        uint64_t content_length = fgetc(fp);
        uint64_t content;
        i = 1;
        while (i < 6) {
            content = fgetc(fp);
            content_length = content_length + (content << 8*i);
            i++;
        }
        fseek(fp, content_length, SEEK_CUR);
        fgetc(fp);
        if(long_listing) {
            i = 0;
            while (i < 10) {
                fputc(permissions[i], stdout);
                i++;
            }
            printf("  %c  %5lu  ", egg_format, content_length);
        }
        i = 0;
        while (i < pathname_length){            
            fputc(pathname[i],stdout);
            i++;
        }
        printf("\n");
    }
    fclose(fp);
}


// check the files & directories stored in egg_pathname (subset 1)
//
// prints the files & directories stored in egg_pathname with a message
// either, indicating the hash byte is correct, or
// indicating the hash byte is incorrect, what the incorrect value is and the correct value would be

void check_egg(char *egg_pathname) {
    // REPLACE THIS PRINTF WITH YOUR CODE
    //printf("check_egg called to check egg: '%s'\n", egg_pathname);
    FILE *fp = fopen(egg_pathname, "r");
    if (fp == NULL) {
        perror(egg_pathname);
        exit(1);
    }
    int first_byte;

    while ((first_byte = fgetc(fp)) != EOF) {
        if (first_byte != MAGIC_NUMBER) {
            fprintf(stderr,"error: incorrect first egglet byte: 0x%x should be 0x%x\n", first_byte, MAGIC_NUMBER);
            return;
        }
        int fp_hash = MAGIC_NUMBER;

        int egg_format = fgetc(fp);
        fp_hash = egglet_hash(fp_hash, egg_format);

        int i = 0;
        int permission;
        while (i < 10) {
            permission = fgetc(fp);
            fp_hash = egglet_hash(fp_hash, permission);
            i++;
        }
        
        int pathname_length_1 = fgetc(fp);
        fp_hash = egglet_hash(fp_hash, pathname_length_1);
        int pathname_length_2 = fgetc(fp);
        fp_hash = egglet_hash(fp_hash, pathname_length_2);
        int pathname_length = pathname_length_1 + (pathname_length_2 << 8);
        
        i = 0;
        char pathname[pathname_length];
        while(i < pathname_length){           
            pathname[i] = fgetc(fp);
            fp_hash = egglet_hash(fp_hash, pathname[i]);
            i++;
        }
        uint64_t content_length = 0;
        uint64_t cont;
        i = 0;
        while (i < 6) {
            cont = fgetc(fp);
            fp_hash = egglet_hash(fp_hash, cont);
            content_length = content_length + (cont << 8*i);
            i++;
        }
        i = 0;
        int content;
        while(i < content_length){
            content = fgetc(fp);
            fp_hash = egglet_hash(fp_hash, content);
            i++;
        }
        int hash = fgetc(fp);
        if (fp_hash == hash) {
            i = 0;
            while (i < pathname_length){            
            fputc(pathname[i],stdout);
            i++;
            }
            printf(" - correct hash\n");
        } else {
            i = 0;
            while (i < pathname_length){            
                fputc(pathname[i],stdout);
                i++;
            }
            printf(" - incorrect hash 0x%x should be 0x%x\n", fp_hash, hash);
        }
    }
    fclose(fp);
}


// extract the files/directories stored in egg_pathname (subset 2 & 3)

void extract_egg(char *egg_pathname) {

    // REPLACE THIS PRINTF WITH YOUR CODE

    //printf("extract_egg called to extract egg: '%s'\n", egg_pathname);
    FILE *fp = fopen(egg_pathname, "r");
    if (fp == NULL) {
        perror(egg_pathname);
        exit(1);
    }
    int first_byte;
    while ((first_byte = fgetc(fp)) != EOF) {
        fseek (fp, 2, SEEK_CUR); // skip the egg_format
        int i = 0;
        int permissions = 0;
        while (i < 9){
            int j = fgetc(fp);
            if (j == '-'){
                j = 0;
            }
            else {j = 1;}
            permissions = permissions | (j<<(8-i));
            i++;
        }

        uint64_t pathname_length, pathname_length_1, pathname_length_2;
        pathname_length_1 = fgetc(fp);
        pathname_length_2 = fgetc(fp);
        pathname_length = pathname_length_1 + (pathname_length_2<<8);

        char pathname[pathname_length+1];
        for(i = 0; i < pathname_length; i++){
            pathname[i] = fgetc(fp);
        }
        pathname[i] = '\0';

        FILE *fw = fopen(pathname, "w");
        uint64_t content_length = fgetc(fp);
        uint64_t j;

        for (i = 1; i < 6; i++){
            j = fgetc(fp);
            content_length = content_length + (j << 8*i);
        }

        for(i = 0; i < content_length; i++){
            fputc(fgetc(fp), fw);
        }

        if(chmod(pathname, permissions) != 0) {
            perror(pathname);
            exit(1);
        }
        printf("Extracting: %s\n", pathname);
        fclose(fw);
        fgetc(fp);
        
    }
    fclose(fp);

}


// create egg_pathname containing the files or directories specified in pathnames (subset 3)
//
// if append is zero egg_pathname should be over-written if it exists
// if append is non-zero egglets should be instead appended to egg_pathname if it exists
//
// format specifies the egglet format to use, it must be one EGGLET_FMT_6,EGGLET_FMT_7 or EGGLET_FMT_8

void create_egg(char *egg_pathname, int append, int format,
                int n_pathnames, char *pathnames[n_pathnames]) {

    // REPLACE THIS CODE PRINTFS WITH YOUR CODE

    //printf("create_egg called to create egg: '%s'\n", egg_pathname);
    //printf("format = %x\n", format);
    //printf("append = %d\n", append);
    //printf("These %d pathnames specified:\n", n_pathnames);
    //for (int p = 0; p < n_pathnames; p++) {
    //    printf("%s\n", pathnames[p]);
    //}
    char *state = "w";
    if(append){
        state = "a";
    }
    FILE *egg = fopen(egg_pathname, state);
    if (egg == NULL) {
        perror(egg_pathname);
        exit(1);
    }
                   
    int i = 0;
    while(i < n_pathnames) {
        FILE *fp = fopen (pathnames[i],"r");
        if(fp == NULL){
            perror(pathnames[i]);
            exit(1);
        }
        struct stat size;
        if (stat(pathnames[i], &size) != 0) {
            perror("pathnames[i]");
            exit(1);
        }
        //magic number
        fputc(MAGIC_NUMBER, egg);
        uint fp_hash = MAGIC_NUMBER;
        //format
        fputc(format, egg);
        fp_hash = egglet_hash(fp_hash, format);
        
        //permission
        uint mode = size.st_mode;
        char permissions[11] = "-rwxrwxrwx\0";
        if (S_ISDIR(mode)) {
            permissions[0] = 'd';
        }
        int j = 0;
        while (j < 9) {
            if ((mode & (1 << j)) == 0) {
                permissions[9 - j] = '-';
            }
            j++;
        }
        j = 0;
        while (j < 10) {
            fp_hash = egglet_hash(fp_hash, permissions[j]);
            j++;
        }

        fwrite(permissions, 1, 10, egg);
        int pathname_length = strlen(pathnames[i]);
        uint pathname_length_1 = pathname_length & MASK;
        uint pathname_length_2 = pathname_length >> 8;
        fputc(pathname_length_1, egg);
        fputc(pathname_length_2, egg);

        fp_hash = egglet_hash(fp_hash, pathname_length_1);
        fp_hash = egglet_hash(fp_hash, pathname_length_2);

        fwrite(pathnames[i], 1, pathname_length, egg);
        j = 0;
        while (j < pathname_length) {
            fp_hash = egglet_hash (fp_hash, pathnames[i][j]);
            j++;
        }
        uint64_t content_length = size.st_size;
        int cont = content_length;
        j = 0;
        while (j < 6){
            fputc(cont & MASK, egg);
            fp_hash = egglet_hash(fp_hash, (cont & MASK));
            cont = cont>>8;
            j++;
        }
        j = 0;
        while(j < content_length){
            int content = fgetc(fp);
            fp_hash = egglet_hash(fp_hash, content);
            fputc (content, egg);  
            j++;         
        }
        fputc(fp_hash, egg);
        printf("Adding: %s\n", pathnames[i]);
        i++;
    }
        
    
}


// ADD YOUR EXTRA FUNCTIONS HERE
