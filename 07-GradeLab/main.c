//
//  main.c
//  Giannell_Anthony_GradeLab
//
//  Created by Anthony Giannell on 3/17/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

void calculateAverage (void);

int main(int argc, const char * argv[]) {
	int i;
	
	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calculateAverage();
	}
	
	fclose(fp);
    return 0;
}

void calculateAverage (void){
	float runningTotal = 0;
	float score = 0;
	float numberOfTests = 0;
	float average = 0;
	
	printf("Enter test scores: \n");
	fprintf(fp, "Enter test scores: \n");

	do {
		scanf(" %f", &score);
		if (score != -1) {
		printf("%.0f\n", score);
		fprintf(fp, "%.0f\n", score);
		}
		runningTotal += score;
		numberOfTests ++;
		average = runningTotal / numberOfTests;

	}while(score != -1);
	printf("\nThe average is %.2f\n", average);
	printf("--------------------\n\n");
	fprintf(fp, "\nThe average is %.2f\n", average);
	fprintf(fp, "--------------------\n\n\n");

}
