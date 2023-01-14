//
//  main.c
//  Giannell_Anthony_Final
//
//  Created by Anthony Giannell on 5/19/19.
//  Copyright © 2019 CSCI. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

FILE *fpIn1, *fpIn2, *fpOut;

typedef struct {
    char itemNumber[8];
    char itemDescription[14];
    int qtySold;
    double unitPrice;
    double totalSales;
} Item;

int processSalesFile(int sales[], Item list[]);
int processListFile(Item list[]);
void strsub(char buf[], char sub[], int start, int end);
void outputItemsSold(Item list[], int itemCount);
void outputItemsSales(Item list[], int itemCount);
void outputTotalSales(Item list[], int itemCount);
void freqDist(int sales[], Item list[], int salesCount);
void sortAscending (int sales[], int salesCount);
void sortByQTY(Item list[], int itemCount);
void sortBySales(Item list[], int itemCount);
 
int main(void) {
    Item list[MAX];
    int sales[MAX];

    if (!(fpIn1 = fopen("ItemSales.txt", "r"))) {
        printf("ItemSales.txt could not be opened for input.");
        exit(1);
    }
    if (!(fpIn2 = fopen("ItemList.txt", "r"))) {
        printf("ItemList.txt could not be opened for input.");
        exit(1);
    }
    if (!(fpOut = fopen("SalesSummary.txt", "w"))) {
        printf("SalesSummary.txt could not be opened for output.");
        exit (1);
    }
    
    int salesCount = processSalesFile(sales, list);
    int itemCount = processListFile(list);
    outputItemsSold(list, itemCount);
    outputItemsSales(list, itemCount);
    outputTotalSales(list, itemCount);
    
    fclose(fpIn1);
    fclose(fpIn2);
    fclose(fpOut);
    return 0;
}

int processSalesFile(int sales[], Item list[]) {
    char buf[MAX], tempSales[MAX];
    int i = 0;
	int j;
	
	for(j = 0; j < MAX; j++) {
		sales[j] = 0;
	}
    
    while(!feof(fpIn1)) {
        fgets(buf, MAX, fpIn1);
        strsub(buf, tempSales, 6, 6);
            sales[i] = atoi(tempSales);
        i++;
    }
	
	int salesCount = i - 1;

    freqDist(sales, list, salesCount);
	
    return salesCount;
}

int processListFile(Item list[]) {
    char buf[MAX], tempUnitPrice[MAX];
    int i = 0;
     
    while(!feof(fpIn2)) {
        fgets(buf, MAX, fpIn2);
        strsub(buf, list[i].itemNumber, 0, 6);
        strsub(buf, list[i].itemDescription, 8, 20);
        strsub(buf, tempUnitPrice, 22, 26);
            list[i].unitPrice = atof(tempUnitPrice);
        i++;
    }
	
	int itemCount = i - 1;


    return itemCount;
}

void strsub(char buf[], char sub[], int start, int end) {
    int i, j;
     
    for (j = 0, i = start; i <= end; i++, j++) {
        sub[j] = buf[i];
    }
    sub[j] = '\0';
     
    return;
}

void outputItemsSold(Item list[], int itemCount) {
    int i;
    
    sortByQTY(list, itemCount);
    
    printf("************* QUANTITY OF ITEMS SOLD ************\n");
    printf("%s\t\t%s\t%s\n", "Item Number", "Item Description", "Quantity Sold");
    printf("-------------------------------------------------\n");
    fprintf(fpOut, "*************** QUANTITY OF ITEMS SOLD **************\n");
    fprintf(fpOut, "%s\t%s\t%s\n", "Item Number", "Item Description", "Quantity Sold");
    fprintf(fpOut, "-----------------------------------------------------\n");    
    
    for(i = 0; i < itemCount; i++) {
    printf("%s\t\t\t%s\t\t%d\n", list[i].itemNumber, list[i].itemDescription, list[i].qtySold);
    fprintf(fpOut, "%s\t\t%s\t\t%d\n", list[i].itemNumber, list[i].itemDescription, list[i].qtySold);
    }
    
    printf("*************************************************\n\n");
    fprintf(fpOut, "*****************************************************\n\n");
    
    
    return;
}

void outputItemsSales(Item list[], int itemCount) {
    int i, j;
    
    printf("*************************** TOTAL SALES PER ITEM **************************\n");
    printf("%s\t\t%s\t%s\t%s\t%s\n", "Item Number", "Item Description", "Quantity Sold", "Unit Price", "Total Sales");
    printf("---------------------------------------------------------------------------\n");
    fprintf(fpOut, "******************************* TOTAL SALES PER ITEM ******************************\n");
    fprintf(fpOut, "%s\t%s\t%s\t%s\t%s\n", "Item Number", "Item Description", "Quantity Sold", "Unit Price", "Total Sales");
    fprintf(fpOut, "-----------------------------------------------------------------------------------\n");    
    
    for(i = 0; i < itemCount; i++) {
        list[i].totalSales = list[i].unitPrice * list[i].qtySold;
    }
    
    sortBySales(list, itemCount);    
    
    for(j = 0; j < itemCount; j++) {
    printf("%s\t\t\t%s\t\t%d\t\t\t\t%s%5.2f\t\t%s%6.2f\n", list[j].itemNumber, list[j].itemDescription, list[j].qtySold, "$", list[j].unitPrice, "$", list[j].totalSales);
    fprintf(fpOut, "%s\t\t%s\t\t%d\t\t%s%5.2f\t\t%s%6.2f\n", list[j].itemNumber, list[j].itemDescription, list[j].qtySold, "$", list[j].unitPrice, "$", list[j].totalSales);
    }
    
    printf("***************************************************************************\n\n");    
    fprintf(fpOut, "***********************************************************************************\n\n");    
    
    
    return;
}

void outputTotalSales(Item list[], int itemCount) {
    int i;
    double sum = 0;
    
    for (i = 0; i < itemCount; i++) {
        sum = sum + list[i].totalSales;
    }
    
    printf("The total sales is $%.2f", sum);
    fprintf(fpOut, "The total sales is $%.2f", sum);
    
    return;
}

void freqDist(int sales[], Item list[], int salesCount) {
    int freq[MAX];
    int i, j, count;
    
    sortAscending(sales, salesCount);
    
    for (i = 0; i < salesCount; i++) {
        freq[i] = -1;
        list[i].qtySold = 0;
    }   
     
    for (i = 0; i < salesCount; i++) {
        count = 1;
         
        for (j = i + 1; j < salesCount; j++) {
            if(sales[i] == sales[j]) {
                count ++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0) {
            freq[i] = count;
        }
    }    
    
    int n = 0;
    for (i = 0; i < salesCount; ++i) {
        if(freq[i] != 0) {
            list[n].qtySold = freq[i];
            n++;
            }
    }   
     
    return;
}

void sortAscending (int sales[], int salesCount) {
    int i, temp, sort;
     
    while (1) {
        sort = 0;
         
        for (i = 0; i < salesCount -1; ++i) {
            if(sales[i] > sales[i + 1]) {
                temp = sales[i];
                sales[i] = sales[i + 1];
                sales[i + 1] = temp;
                sort = 1;
            }
        }
        if(sort == 0) {
            break;
        }
    }
    return;
}

void sortByQTY(Item list[], int itemCount) {
    int i, j;
    Item temp;
    
    for(i = 0; i < itemCount; i++) {
        for(j = 0; j < itemCount; j++) {
            if(list[j].qtySold < list[j + 1].qtySold) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    
    return;
}

void sortBySales(Item list[], int itemCount) {
    int i, j;
    Item temp;
    
    for(i = 0; i < itemCount; i++) {
        for(j = 0; j < itemCount; j++) {
            if(list[j].totalSales < list[j + 1].totalSales) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    
    return;
}
