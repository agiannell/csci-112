//
//  main.c
//  Giannell_Anthony_BodyMassIndexLab
//
//  Created by Anthony Giannell on 3/10/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

double calculateBMI(double weightInPounds, double heightInInches);

int main(int argc, const char * argv[]) {
	int i;
	
	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calculateBMI(0, 0);
	}
	fclose(fp);
    return 0;
}

double calculateBMI(double weightInPounds, double heightInInches) {
	
	printf("Enter your weight in pounds: \n");
	fprintf(fp, "Enter your weight in pounds: \n");
	scanf(" %lf", &weightInPounds);
	printf("Enter your height in inches: \n");
	fprintf(fp, "Enter your height in inches: \n");
	scanf(" %lf", &heightInInches);
	
	double BMI;
	BMI = (weightInPounds * 703) / (heightInInches * heightInInches);
	
	printf("Your BMI is %.1lf, which means you are ", BMI);
	fprintf(fp, "Your BMI is %.1lf, which means you are ", BMI);
	
	if(BMI < 18.5) {
		printf("Underweight\n\n");
		fprintf(fp, "Underweight\n\n");

	}
	else if(BMI < 25.0) {
		printf("Normal\n\n");
		fprintf(fp, "Normal\n\n");
	}
	else if(BMI < 30.0) {
		printf("Overweight\n\n");
		fprintf(fp, "Overweight\n\n");
	}
	else if(BMI >= 30.0) {
		printf("Obese\n\n");
		fprintf(fp, "Obese\n\n");
	}
	
	return 0;
}
