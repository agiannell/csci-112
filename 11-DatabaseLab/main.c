//
//  main.c
//  Giannell_Anthony_DatabaseLab
//
//  Created by Anthony Giannell on 5/13/19.
//  Copyright © 2019 Anthony Giannell. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
 
FILE *fpIn, *fpOut;
 
typedef struct {
    char firstName[8];
    char middleInitial[2];
    char lastName[10];
    char street[17];
    char city[12];
    char state[3];
    char zipCode[6];
    int age;
    char gender[2];
    int tenure;
    double weeklySalary;
} Employee;
 
void processFile(Employee records[]);
void strsub(char buf[], char sub[], int start, int end);
void outputContents(Employee records[]);
void menNames(Employee records[]);
void richestGirl(Employee records[]);
void poorestBoy(Employee records[]);
double averageSalary(Employee records[]);
void isLetter(char sub[]);
void belowAverage_F(Employee records[], double meanSalary);
void salaryRatio_M(Employee records[], double meanSalary);
void filteredOutput(Employee records[]);
void raiseSalary(Employee records[]);
void sortByZip(Employee records[]);
 
int main(void) {
    Employee records[MAX];
     
    if (!(fpIn = fopen("payfile.txt", "r"))) {
        printf("payfile.txt could not be opened for input.");
        exit(1);
    }
    if (!(fpOut = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit (1);
    }
     
    processFile(records);
    outputContents(records);
    menNames(records);
    richestGirl(records);
    poorestBoy(records);
    double meanSalary = averageSalary(records);
    belowAverage_F(records, meanSalary);
    salaryRatio_M(records, meanSalary);
    filteredOutput(records);
    raiseSalary(records);
    sortByZip(records);
     
    fclose(fpIn);
    fclose(fpOut);
    return 0;
}
 
void processFile(Employee records[]) {
    char buf[MAX], tempAge[MAX], tempTenure[MAX], tempSalary[MAX];
    int i = 0;
     
    while(!feof(fpIn)) {
        fgets(buf, MAX, fpIn);
        strsub(buf, records[i].firstName, 0, 6);
        strsub(buf, records[i].middleInitial, 8, 8);
        strsub(buf, records[i].lastName, 10, 18);
        strsub(buf, records[i].street, 20, 35);
        strsub(buf, records[i].city, 37, 47);
        strsub(buf, records[i].state, 49, 50);
        strsub(buf, records[i].zipCode, 52, 56);
        strsub(buf, tempAge, 58, 59);
        records[i].age = atoi(tempAge);
        strsub(buf, records[i].gender, 61, 61);
        strsub(buf, tempTenure, 63, 63);
        records[i].tenure = atoi(tempTenure);
        strsub(buf, tempSalary, 65, 70);
        records[i].weeklySalary = atof(tempSalary);
        i++;
    }
     
    return;
}
 
void strsub(char buf[], char sub[], int start, int end) {
    int i, j;
     
    for (j = 0, i = start; i <= end; i++, j++) {
        sub[j] = buf[i];
    }
    sub[j] = '\0';
     
    return;
}
 
void outputContents(Employee records[]) {
    
    printf("************************************* DATABASE OF EMPLOYEES *************************************\n");
    printf("%s %5s %5s %12s %14s %12s %9s %4s %7s %7s %7s\n", "First", "MI", "Last", "Street", "City", "State", "Zip Code", "Age", "Gender", "Tenure", "Salary");
    printf("-------------------------------------------------------------------------------------------------\n");
    fprintf(fpOut, "************************************* DATABASE OF EMPLOYEES *************************************\n");
    fprintf(fpOut, "%s %5s %5s %12s %14s %12s %9s %4s %7s %7s %7s\n", "First", "MI", "Last", "Street", "City", "State", "Zip Code", "Age", "Gender", "Tenure", "Salary");
    fprintf(fpOut, "-------------------------------------------------------------------------------------------------\n");
     
    int i;
     
    for(i = 0; i <= 13; i++) {
        printf("%s %2s %11s %17s %11s %2s %9s %6d %3s %7d %12.2f\n", records[i].firstName,
                                                                     records[i].middleInitial,
                                                                     records[i].lastName,
                                                                     records[i].street,
                                                                     records[i].city,
                                                                     records[i].state,
                                                                     records[i].zipCode,
                                                                     records[i].age,
                                                                     records[i].gender,
                                                                     records[i].tenure,
                                                                     records[i].weeklySalary);
                                                                     
        fprintf(fpOut, "%s %2s %11s %17s %11s %2s %9s %6d %3s %7d %12.2f\n", records[i].firstName,
                                                                             records[i].middleInitial,
                                                                             records[i].lastName,
                                                                             records[i].street,
                                                                             records[i].city,
                                                                             records[i].state,
                                                                             records[i].zipCode,
                                                                             records[i].age,
                                                                             records[i].gender,
                                                                             records[i].tenure,
                                                                             records[i].weeklySalary);
    }
    
    printf("*************************************************************************************************\n");
    fprintf(fpOut, "*************************************************************************************************\n");
    
    return;
}
 
void menNames(Employee records[]) {
     
    printf("\nThe names of all the men are:\n");
    fprintf(fpOut, "\nThe names of all the men are:\n");
     
    int i;
     
    for(i = 0; i <= 13; i++) {
        if(*records[i].gender == 'M') {
            printf("%s %10s\n", records[i].firstName, records[i].lastName);
            fprintf(fpOut, "%s %10s\n", records[i].firstName, records[i].lastName);
        }
    }
     
    return;
}
 
void richestGirl(Employee records[]) {
    int i;
    int highestPaid = records[0].weeklySalary;
    int location;
    
    for(i = 0; i <= 13; i++) {
        if(*records[i].gender == 'F' && records[i].weeklySalary > highestPaid) {
            highestPaid = records[i].weeklySalary;
            location = i;
        }
    }
    
    char firstName[MAX];
    char lastName[MAX];
    strcpy(firstName, records[location].firstName);
    strcpy(lastName, records[location].lastName);
    isLetter(firstName);
    isLetter(lastName);
    
    printf("\nThe highest paid woman is %s %s\n", firstName, lastName);
    fprintf(fpOut, "\nThe highest paid woman is %s %s\n", firstName, lastName);
     
    return;
}

void poorestBoy(Employee records[]) {
    int i;
    int lowestPaid = records[0].weeklySalary;
    int location;
    
    for(i = 0; i <= 13; i++) {
        if(*records[i].gender == 'M' && records[i].weeklySalary < lowestPaid) {
            lowestPaid = records[i].weeklySalary;
            location = i;
        }
    }
    
    char firstName[MAX];
    char lastName[MAX];
    strcpy(firstName, records[location].firstName);
    strcpy(lastName, records[location].lastName);
    isLetter(firstName);
    isLetter(lastName);
    
    printf("The lowest paid man is %s %s\n", firstName, lastName);
    fprintf(fpOut, "The lowest paid man is %s %s\n", firstName, lastName);
     
    return;
}

double averageSalary(Employee records[]) {
    int i;
    double sum = 0;
    int count = 0;
     
    for (i = 0; i <= 13; ++i) {
        sum = sum + records[i].weeklySalary;
        count++;
    }
    
    double meanSalary = sum / (double)count;
     
    printf("\nThe average salary is $%.2f\n", meanSalary);
    fprintf(fpOut, "\nThe average salary is $%.2f\n", meanSalary);
    
    return meanSalary;
}

void belowAverage_F(Employee records[], double meanSalary) {
    int i;
    char firstName[MAX];
    char lastName[MAX];
    
    printf("\nThe names of the women earning less than the average salary are:\n");
    fprintf(fpOut, "\nThe names of the women earning less than the average salary are:\n");
    
    for(i = 0; i <= 13; i++) {
        if(*records[i].gender == 'F' && records[i].weeklySalary < meanSalary) {
            strcpy(firstName, records[i].firstName);
            strcpy(lastName, records[i].lastName);
            isLetter(firstName);
            isLetter(lastName);
            printf("%s %s\n", firstName, lastName);
            fprintf(fpOut, "%s %s\n", firstName, lastName);
        }
    }
    
    return;
}

void salaryRatio_M(Employee records[], double meanSalary) {
    int i, j;
    int countAbove = 0;
    int countBelow = 0;
    
    for(i = 0; i <= 13; i++) {
        if(*records[i].gender == 'M' && records[i].weeklySalary > meanSalary) {
            countAbove++;
        }
    }
    for(j = 0; j <= 13; j++) {
        if(*records[j].gender == 'M' && records[j].weeklySalary < meanSalary) {
            countBelow++;
        }
    }
    
    double ratio = (double)countAbove / (double)countBelow;
    
    printf("\nThe ratio of men earning above average salary to men earning below average salary is %.3f\n", ratio);
    fprintf(fpOut, "\nThe ratio of men earning above average salary to men earning below average salary is %.3f\n", ratio);
    
    return;
}

void filteredOutput(Employee records[]) {
    int i;
    char firstName[MAX];
    char lastName[MAX];
    
    printf("\nThe names of the employees earning more than $35,000/year, have been with the company at least five years and who are older than thirty are:\n");
    fprintf(fpOut, "\nThe names of the employees earning more than $35,000/year, have been with the company at least five years and who are older than thirty are:\n");
    
    for(i = 0; i <= 13; i++) {
        if (records[i].weeklySalary > 35000 / 52 && records[i].tenure >= 5 && records[i].age > 30) {
            strcpy(firstName, records[i].firstName);
            strcpy(lastName, records[i].lastName);
            isLetter(firstName);
            isLetter(lastName);
            printf("%s %s\n", firstName, lastName);
            fprintf(fpOut, "%s %s\n", firstName, lastName);
        }
    }

    return;
}

void raiseSalary(Employee records[]) {
    int i;
    double newSalary;
    
    printf("\nEmployees making less than $350.00/week will receive a %s raise\n", "10%");
    printf("%s %5s %18s\t%s\n", "First", "Last", "Current Salary", "New Salary");
    printf("-------------------------------------------\n");
    fprintf(fpOut, "\nEmployees making less than $350.00/week will receive a %s raise\n", "10%");
    fprintf(fpOut, "%s %5s %18s\t%s\n", "First", "Last", "Current Salary", "New Salary");
    fprintf(fpOut, "------------------------------------------\n");
    
    for(i = 0; i <= 13; i++) {
        if (records[i].weeklySalary < 350.00) {
            newSalary = records[i].weeklySalary + (records[i].weeklySalary * 0.1);
            printf("%s%s$%.2f\t\t$%.2f\n", records[i].firstName, records[i].lastName, records[i].weeklySalary, newSalary);
            fprintf(fpOut, "%s%s$%.2f \t\t$%.2f\n", records[i].firstName, records[i].lastName, records[i].weeklySalary, newSalary);
        }
    }
    
    return;
}

void sortByZip(Employee records[]) {
    int i, j;
    
    printf("\n**** SORTED BY ZIP CODE ****\n");    
    printf("%s %7s %14s\n", "First", "Last", "Zip Code");
    printf("----------------------------\n");
    fprintf(fpOut, "\n**** SORTED BY ZIP CODE ****\n");
    fprintf(fpOut, "%s %7s %14s\n", "First", "Last", "Zip Code");
    fprintf(fpOut, "----------------------------\n");
     
    Employee temp;

    for (i = 0; i <= 13; i++) {
        temp = records[i];
        j = i - 1;
        while (j >= 0 && strcmp(temp.zipCode, records[j].zipCode) < 0) {
            records[j+1] = records[j];
            j--;
        }
    records[j+1] = temp;
    }
    
    for(i = 0; i <= 13; i++) {
        printf ("%s %10s %6s\n", records[i].firstName, records[i].lastName, records[i].zipCode);
        fprintf (fpOut, "%s %10s %6s\n", records[i].firstName, records[i].lastName, records[i].zipCode);
    }
    
    return;
}

void isLetter(char sub[]) {
    int i, j;
    
    for(i = 0; i <= 13; i++) {
        while (!( (sub[i] >= 'a' && sub[i] <= 'z') || (sub[i] >= 'A' && sub[i] <= 'Z') || sub[i] == '\0') ) {
            for(j = i; sub[j] != '\0'; ++j) {
                sub[j] = sub[j+1];
            }
            sub[j] = '\0';
        }
    }
    
    return;
}