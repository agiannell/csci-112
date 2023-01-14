//
//  main.c
//  Giannell_Anthony_Midterm
//
//  Created by Anthony Giannell on 3/29/19.
//  Copyright Â© 2019 Anthony Giannell. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
 
int userInput (void);
char seriesRun (void);
 
int main(){
    
    fp = fopen("csis.txt", "w");
     
    char runAgain = seriesRun();
    
    do {
        seriesRun();
    }while(runAgain == 'y' || runAgain == 'Y');
    
    fclose(fp);
    return 0;
}
 
int userInput (void){
    int input;
     
    do {
        printf("Please enter a number greater than '2': ");
        fprintf(fp, "Please enter a number greater than '2': ");

        scanf("%d", &input);
        if(input > 2) {
            fprintf(fp, "%d", input);
        }else{
        printf("ERROR: INVALID ENTRY\n\n");

		}
    }while(input <= 2);
     
    return input;
}
 
char seriesRun (void){
    int input, t0, t1, tn, numberOfTerms;
    t0 = 0;
    t1 = 1;
    numberOfTerms = 2;
    input = userInput();
     
    printf("\nFibonacci series up to value less than or equal to %d:\n", input);
    printf(" %d, %d", t0, t1);
    fprintf(fp, "\nFibonacci series up to value less than or equal to %d:\n", input);
    fprintf(fp, " %d, %d", t0, t1);
     
    tn = t0 + t1;
     
    while(tn <= input){
        printf(", %d", tn);
        fprintf(fp, ", %d", tn);
        t0 = t1;
        t1 = tn;
        tn = t0 + t1;
        numberOfTerms ++;
    }
     
    printf("\n\nThe number of terms less than or equal to %d is: %d\n", input, numberOfTerms);
    printf("************************************************************\n\n");
    fprintf(fp, "\n\nThe number of terms less than or equal to %d is: %d\n", input, numberOfTerms);
    fprintf(fp, "************************************************************\n\n");
     
    char runAgain;
     
    printf("Would you like to display the series for another number? Y/N: ");
    fprintf(fp, "Would you like to display the series for another number? Y/N: ");
    scanf(" %c", &runAgain);
    if(runAgain == 'y' || runAgain == 'Y') {
        fprintf(fp, "%c", runAgain);
    }else if(runAgain == 'n' || runAgain == 'N'){
		fprintf(fp, "%c", runAgain);
        printf("\nHave a nice day.\n");
        fprintf(fp, "\nHave a nice day.\n");
        exit(0);
	}else {
		printf("ERROR: INVALID ENTRY. GOOD BYE.\n");
		exit(0);
    }
     
    return runAgain;
     
}

