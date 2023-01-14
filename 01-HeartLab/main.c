//
//  main.c
//  Giannell_Anthony_HeartLab
//
//  Created by Anthony Giannell on 2/9/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int main(void)
{
    int beats_per_second, seconds_per_hour, hours_per_day, days_per_year, beats_per_year, beats_per_50_years;
    
    fp = fopen("csis.txt", "w");
    beats_per_second = 1;
    seconds_per_hour = 3600;
    hours_per_day = 24;
    days_per_year = 365;
    beats_per_year = beats_per_second * seconds_per_hour * hours_per_day * days_per_year;
    beats_per_50_years = beats_per_year * 50;
    
    printf("The average heart will beat %d times in 50 years.\n", beats_per_50_years);
    fprintf(fp, "The average heart will beat %d times in 50 years.\n", beats_per_50_years);
    fclose(fp);
    return 0;
}
