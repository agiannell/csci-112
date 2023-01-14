//
//  main.c
//  Giannell_Anthony_ChangeLab
//
//  Created by Anthony Giannell on 2/17/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int main(int argc, const char * argv[]) {

	int payment, price, totalChange, twenty, ten, five, one, quarter, dime, nickel, penny;
	
	payment = 10000;
	price = 2117;
	totalChange = payment - price; // 7883 //
	
	fp = fopen("csis.txt", "w");
	twenty = totalChange / 2000; // 3 //
	ten = (totalChange %= 2000) / 1000; // modulus = 1883 //
	five = (totalChange %= 1000) / 500;
	one = (totalChange %= 500) / 100;
	quarter = (totalChange %= 100) / 25;
	dime = (totalChange %= 25) / 10;
	nickel = (totalChange %= 10) / 5;
	penny = (totalChange %= 5) / 1;
	
	printf("A person purchased an item for $21.17 at the store.\n");
	fprintf(fp, "A person purchased an item for $21.17 at the store.\n");
	printf("They paid with a $100 dollar bill.\n");
	fprintf(fp, "They paid with a $100 dollar bill.\n");
	printf("The number of bills and coins used are as follows:\n\n");
	fprintf(fp, "The number of bills and coins used are as follows:\n\n");
	printf("%5s: %d\n", "$20", twenty);
	fprintf(fp, "%5s: %d\n", "$20", twenty);
	printf("%5s: %d\n", "$10", ten);
	fprintf(fp, "%5s: %d\n", "$10", ten);
	printf("%5s: %d\n", "$5", five);
	fprintf(fp, "%5s: %d\n", "$5", five);
	printf("%5s: %d\n", "$1", one);
	fprintf(fp, "%5s: %d\n", "$1", one);
	printf("%5s: %d\n", "$.25", quarter);
	fprintf(fp, "%5s: %d\n", "$.25", quarter);
	printf("%5s: %d\n", "$.10", dime);
	fprintf(fp, "%5s: %d\n", "$.10", dime);
	printf("%5s: %d\n", "$.05", nickel);
	fprintf(fp, "%5s: %d\n", "$.05", nickel);
	printf("%5s: %d\n\n", "$.01", penny);
	fprintf(fp, "%5s: %d\n\n", "$.01", penny);
	
	fclose(fp);
    return 0;
}
