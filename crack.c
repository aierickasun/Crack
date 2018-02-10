/**
 * C Program uses dictionary attack against password
 * hashed with C's DES-based crypt function.
 * Author: Eric Ngo
 **/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#include <string.h>

char* crack(char *hash, FILE* theDict);
char *crypt(const char *key, const char *salt);
void ridNewLine(char *string);

int main(int argc, char * argv[]){
    if(argc!=2){
        printf("Usage: ./crack hash\n");
    }
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    
    char *plainText = crack(argv[1], fp);
    printf("%s\n", plainText);

    fclose(fp);
    return 0;
}
//Launches dictionary attack to try to find the hash.
char* crack(char *hash, FILE* theDict){
    char *pt = malloc(30);
    char *plain = malloc(30);
    char comp[2];
    comp[0] = hash[0];
    comp[1] = hash[1];
    while(fgets(plain, 29, theDict)!= NULL){
        ridNewLine(plain);
        pt = crypt(plain, comp);
        
        if(strcmp(pt, hash)==0){
            
            return plain;
        }
    }
  
    plain = "No String Found";
   return plain;
}
//Goes through the string and replaces the first newline
//with the null terminator.
void ridNewLine(char *string){
    for(int i = 0; i < strlen(string); i++){
        if(string[i]=='\n'){
            string[i] = '\0';
            break;
        }
    }
}