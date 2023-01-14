//
//  main.c
//  Giannell_Anthony_CaesarCipherLab
//
//  Created by Anthony Giannell on 4/24/19.
//  Copyright © 2019 Anthony Giannell. All rights reserved.
//
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
FILE *fpIn, *fpOut;
 
void processFile(char congressLetter[]);
void cipher(char congressLetter[]);
void outputCode(char congressLetter[]);
void isletter(char congressLetter[]);
void strupr(char congressLetter[]);
 
int main(void) {
    char congressLetter[275];
     
    if (!(fpIn = fopen("congress.txt", "r"))) {
        printf("congress.txt could not be opened for input.");
        exit(1);
    }
    if (!(fpOut = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit (1);
    }
     
    processFile(congressLetter);
    strupr(congressLetter);
    cipher(congressLetter);
    outputCode(congressLetter);
     
    fclose(fpIn);
    fclose(fpOut);
    return 0;
}
void processFile(char congressLetter[]) {
    while(!feof(fpIn)) {
        fgets(congressLetter, 275, fpIn);
    }
     
    isletter(congressLetter);
	
    return;
}
 
void cipher (char congressLetter[]) {
    int i, shift;
    char hold;
     
    printf("Please input the shift value for the cipher: ");
    fprintf(fpOut, "\nPlease input the shift value for the cipher: ");
    scanf(" %d", &shift);
    fprintf(fpOut, "%d", shift);
     
    for(i = 0; congressLetter[i] != '\0'; ++i) {
        hold = congressLetter[i];
         
        if(hold >= 'a' && hold <= 'z') {
            hold = hold + shift;
             
            if(hold > 'z') {
                hold = hold - 'z' + 'a' - 1;
            }
             
            congressLetter[i] = hold;
        }
        else if(hold >= 'A' && hold <= 'Z') {
            hold = hold + shift;
             
            if(hold > 'Z') {
                hold = hold - 'Z' + 'A' - 1;
            }
             
            congressLetter[i] = hold;
        }
    }
     
     
    return;
}
 
void outputCode(char congressLetter[]) {
    int i;
     
    printf("\n");
    fprintf(fpOut, "\n");
    for (i = 0; congressLetter[i] != '\0'; ++i) {
        printf("%c", congressLetter[i]);
        fprintf(fpOut, "%c", congressLetter[i]);
        if((i + 1) % 5 == 0) {
            printf(" ");
            fprintf(fpOut, " ");
        }
        if((i + 1) % 50 == 0) {
            printf("\n");
            fprintf(fpOut, "\n");
        }
    }
    printf("\n");
    fprintf(fpOut, "\n");
     
    return;
}

void isletter(char congressLetter[]) {
    int i, j;
    
    for(i = 0; congressLetter[i] != '\0'; ++i) {
        while (!( (congressLetter[i] >= 'a' && congressLetter[i] <= 'z') || (congressLetter[i] >= 'A' && congressLetter[i] <= 'Z') || congressLetter[i] == '\0') ) {
            for(j = i; congressLetter[j] != '\0'; ++j) {
                congressLetter[j] = congressLetter[j+1];
            }
            congressLetter[j] = '\0';
        }
    }
    
    return;
}
 
void strupr(char congressLetter[]) {
    int i = 0;
     
    while (congressLetter[i] != '\0')
    {
        if (congressLetter[i] >= 'a' && congressLetter[i] <= 'z') {
            congressLetter[i] = congressLetter[i] - 32;
        }
        i++;
    }
     
    return;
}
