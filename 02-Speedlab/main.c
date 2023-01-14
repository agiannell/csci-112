//
//  main.c
//  Giannell_Anthony_Speedlab
//
//  Created by Anthony Giannell on 2/3/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int main(void)
{
    float miles, hour, miles_per_hour, meters_per_second, meters, second;
    
    fp = fopen("csis.txt", "w");
    miles = 275.5;
    hour = 8.5;
    miles_per_hour = miles / hour;
    meters = miles * 1600;
    second = hour * 3600;
    meters_per_second = meters / second;
    
    printf("The speed of the car is %.2f mph or %.2f m/s.\n", miles_per_hour, meters_per_second);
    fprintf(fp, "The speed of the car is %.2f mph or %.2f m/s.\n", miles_per_hour, meters_per_second);
    fclose(fp);
    return 0;
}
