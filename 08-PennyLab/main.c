//
//  main.c
//  Giannell_Anthony_PennyLab
//
//  Created by Anthony Giannell on 3/17/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int tableHeader(void);
double goalDays(double day, double deposit, double balance, double goal);

int main(int argc, const char * argv[]) {
	fp = fopen("csis.txt", "w");
	int daysNeeded = goalDays(1,0,0,0);
	
	printf("\nIt took %d days to accumulate at least $1000000.00.\n", daysNeeded);
	fprintf(fp, "\nIt took %d days to accumulate at least $1000000.00.\n", daysNeeded);
	
	fclose(fp);
    return 0;
}

int tableHeader(void) {
	printf("\n%5s %15s %15s\n", "DAY", "DEPOSIT", "BALANCE");
	printf("%5s %15s %15s\n", "---", "-------", "-------");
	fprintf(fp, "%5s %15s %15s\n", "DAY", "DEPOSIT", "BALANCE");
	fprintf(fp, "%5s %15s %15s\n", "---", "-------", "-------");

	
	return 0;
}

double goalDays(double day, double deposit, double balance, double goal) {
	day = 1;
	deposit = .01;
	balance = deposit;
	
	printf("Please enter the amount of money you want to accumulate: ");
	fprintf(fp, "Please enter the amount of money you want to accumulate: ");
	scanf("%lf", &goal);
	tableHeader();
	while(balance < goal){
		printf("%5.0lf %15.2lf %15.2lf\n", day, deposit, balance);
		fprintf(fp, "%5.0lf %15.2lf %15.2lf\n", day, deposit, balance);
		day ++;
		deposit *= 2;
		balance += deposit;
		
	}
	
	return day;
}
