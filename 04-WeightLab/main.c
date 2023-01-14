//
//  main.c
//  Giannell_Anthony_WeightLab
//
//  Created by Anthony Giannell on 2/16/19.
//  Copyright © 2019 CSCI. All rights reserved.
//

#include <stdio.h>

FILE *fp;

int main(int argc, const char * argv[]) {

    float mercury, venus, mars, jupiter, saturn, uranus, neptune, weight;
    
    fp = fopen("csis.txt", "w");
    mercury = .378;
    venus = .907;
    mars = .377;
    jupiter = 2.360;
    saturn = .916;
    uranus = .889;
    neptune = 1.120;
    weight = 200;
    
    printf("The weight of a 200 lb person on different planets is as follows:\n\n");
    fprintf(fp, "The weight of a 200 lb person on different planets is as follows:\n\n");
    printf("%10s: %5.1f lbs\n", "Mercury", weight * mercury);
    fprintf(fp, "%10s: %5.1f lbs\n", "Mercury", weight * mercury);
    printf("%10s: %5.1f lbs\n", "Venus", weight * venus);
    fprintf(fp, "%10s: %5.1f lbs\n", "Venus", weight * venus);
    printf("%10s: %5.1f lbs\n", "Mars", weight * mars);
    fprintf(fp, "%10s: %5.1f lbs\n", "Mars", weight * mars);
    printf("%10s: %5.1f lbs\n", "Jupiter", weight * jupiter);
    fprintf(fp, "%10s: %5.1f lbs\n", "Jupiter", weight * jupiter);
    printf("%10s: %5.1f lbs\n", "Saturn", weight * saturn);
    fprintf(fp, "%10s: %5.1f lbs\n", "Saturn", weight * saturn);
    printf("%10s: %5.1f lbs\n", "Uranus", weight * uranus);
    fprintf(fp, "%10s: %5.1f lbs\n", "Uranus", weight * uranus);
    printf("%10s: %5.1f lbs\n\n", "Neptune", weight * neptune);
    fprintf(fp, "%10s: %5.1f lbs\n\n", "Neptune", weight * neptune);
    
    fclose(fp);
    return 0;
}
