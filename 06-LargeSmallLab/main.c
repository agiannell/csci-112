//
//  main.c
//  Giannell_Anthony_LargeSmallLab
//
//  Created by Anthony Giannell on 3/10/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int compare(int num1, int num2, int num3, int num4);

int main(int argc, const char * argv[]) {
    int i;
    
    fp = fopen("csis.txt", "w");
    for (i = 1; i <= 4; ++i) {
        compare(0, 0, 0, 0);
    }
    fclose(fp);
    return 0;
}

int compare(int num1, int num2, int num3, int num4) {
    printf("Please enter four numbers \n");
    fprintf(fp, "Please enter four numbers \n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    printf("%d %d %d %d\n\n", num1, num2, num3, num4);
    fprintf(fp, "%d %d %d %d\n\n", num1, num2, num3, num4);

    if (num1 < num2) {
        if(num1 < num3) {
            if(num1 < num4) {
                printf("%d is the smallest number\n", num1);
                fprintf(fp, "%d is the smallest number\n", num1);
            }
        }
    }
    if (num2 < num1) {
        if(num2 < num3) {
            if(num2 < num4) {
                printf("%d is the smallest number\n", num2);
                fprintf(fp, "%d is the smallest number\n", num2);
            }
        }
    }
    if (num3 < num1) {
        if(num3 < num2) {
            if(num3 < num4) {
                printf("%d is the smallest number\n", num3);
                fprintf(fp, "%d is the smallest number\n", num3);
            }
        }
    }
    if (num4 < num1) {
        if(num4 < num2) {
            if(num4 < num3) {
                printf("%d is the smallest number\n", num4);
                fprintf(fp, "%d is the smallest number\n", num4);
            }
        }
    }
    if (num1 > num2) {
        if(num1 > num3) {
            if(num1 > num4) {
                printf("%d is the largest number\n", num1);
                fprintf(fp, "%d is the largest number\n\n", num1);
            }
        }
    }
    if (num2 > num1) {
        if(num2 > num3) {
            if(num2 > num4) {
                printf("%d is the largest number\n", num2);
                fprintf(fp, "%d is the largest number\n\n", num2);
            }
        }
    }
    if (num3 > num1) {
        if(num3 > num2) {
            if(num3 > num4) {
                printf("%d is the largest number\n", num3);
                fprintf(fp, "%d is the largest number\n\n", num3);
            }
        }
    }
    if (num4 > num1) {
        if(num4 > num2) {
            if(num4 > num3) {
                printf("%d is the largest number\n", num4);
                fprintf(fp, "%d is the largest number\n\n", num4);
            }
        }
    }
    
    
    return 0;
}
