//
//  main.c
//  Giannell_Anthony_StatisticsLab
//
//  Created by Anthony Giannell on 4/14/19.
//  Copyright © 2019 Anthony Giannell. All rights reserved.
//

#include <stdio.h>
#define MAX 30

FILE *fp;

void printScores (int scores[]);
void sortScores (int scores[]);
int freqDist (int scores[]);
void passFail (int scores[]);
void meanScores (int scores[]);
void modeScores (int mode);
void medianScore (int scores[]);
void outputScores (int scores[]);
void sortAscending (int scores[]);
void sortDescending (int scores[]);

int main(void) {
	int scores[MAX] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 };
	
	fp = fopen("csis.txt", "w");
	
	printScores(scores);
	sortScores(scores);
	int mode = freqDist(scores);
	printf("\n******************************************\n");
	fprintf(fp, "\n******************************************\n");
	passFail(scores);
	meanScores(scores);
	modeScores(mode);
	medianScore(scores);
	printf("\n******************************************\n");
	fprintf(fp, "\n******************************************\n");

	fclose(fp);
    return 0;
}

void printScores (int scores[]) {
	
	printf("Test Scores\n");
	printf("-----------\n");
	fprintf(fp, "Test Scores\n");
	fprintf(fp, "-----------\n");
	
	outputScores(scores);
    
    return;
}

void sortScores(int scores[]) {
	
	sortAscending(scores);
	
	printf("\n\nTest Scores (Sorted)\n");
	printf("--------------------\n");
	fprintf(fp, "\n\nTest Scores (Sorted)\n");
	fprintf(fp, "--------------------\n");
	
	outputScores(scores);
	
	return;
}

int freqDist(int scores[]) {
	int freq[MAX] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int i, j, count;
	int maxCount = 0;
	int mode = 0;
	
	sortDescending(scores);
	
	for (i = 0; i < MAX; ++i) {
		count = 1;
		
		for (j = i + 1; j < MAX; ++j) {
			if(scores[i] == scores[j]) {
				count ++;
				freq[j] = 0;
			}
		}
		if(freq[i] != 0) {
			freq[i] = count;
		}
		if(count > maxCount) {
			maxCount = count;
			mode = scores[i];
		}
	}
	
	printf("\n\n%s %15s\n", "Score", "Frequency");
	printf("%s %15s\n", "-----", "---------");
	fprintf(fp, "\n\n%s %15s\n", "Score", "Frequency");
	fprintf(fp, "%s %15s\n", "-----", "---------");
	
	for (i = 0; i < MAX; ++i) {
		if(freq[i] != 0) {
			printf("%4d %12d\n", scores[i], freq[i]);
			fprintf(fp, "%4d %12d\n", scores[i], freq[i]);
		}
	}
	
	return mode;
}

void passFail (int scores[]) {
	int i;
	int countPass = 0;
	int countFail = 0;
	
	for (i = 0; i < MAX; ++i) {
		if(scores[i] >= 60) {
			countPass++;
		}
		else {
			countFail++;
		}
	}
	
	float percentPass = ((float)countPass / (float)MAX) * 100;
	float percentFail = ((float)countFail / (float)MAX) * 100;
	
	printf("\nThe percentage of passing scores is %.1f%s\n", percentPass, "%");
	printf("The percentage of failing scores is %.1f%s\n", percentFail, "%");
	fprintf(fp, "\nThe percentage of passing scores is %.1f%s\n", percentPass, "%");
	fprintf(fp, "The percentage of failing scores is %.1f%s\n", percentFail, "%");
	
	return;
}

void meanScores (int scores[]) {
	int i;
	int sum = 0;
	
	for (i = 0; i < MAX; ++i) {
		sum = sum + scores[i];
	}
	
	float mean = (float)sum / (float)MAX;
	
	printf("The mean of the scores is %.2f\n", mean);
	fprintf(fp, "The mean of the scores is %.2f\n", mean);
	
	return;
}

void modeScores (int mode) {
	printf("The mode of the scores is %d\n", mode);
	fprintf(fp, "The mode of the scores is %d\n", mode);
	
	return;
}

void medianScore (int scores[]) {
	int m;
	int n = MAX / 2;
	
	sortAscending(scores);
	
	if(MAX % 2 != 0) {
		m = (MAX + 1) / 2 - 1;
	}
	else {
		m = MAX / 2 - 1;
	}
	
	float median;
	
	if(MAX % 2 != 0) {
		median = scores[m];
	}
	else {
		median = ((float)scores[m] + (float)scores[n]) / 2;
	}
	
	printf("The median score is %.1f\n", median);
	fprintf(fp, "The median score is %.1f\n", median);
	
	return;
}

void outputScores (int scores[]) {
	int i;
	
	for (i = 0; i < MAX; ++i) {
		printf(" %d", scores[i]);
		fprintf(fp, " %d", scores[i]);
		if (i % 5 == 4 || (i == MAX -1)) {
			printf("%c", '\n');
			fprintf(fp, "%c", '\n');
		}
		else if (scores[i] == 100) {
			printf("%4c", ' ');
			fprintf(fp, "%4c", ' ');
		}
		else {
			printf("%5c", ' ');
			fprintf(fp, "%5c", ' ');
		}
	}
	
	return;
}

void sortAscending (int scores[]){
	int i, temp, sort;
	
	while (1) {
		sort = 0;
		
		for (i = 0; i < MAX -1; ++i) {
			if(scores[i] > scores[i + 1]) {
				temp = scores[i];
				scores[i] = scores[i + 1];
				scores[i + 1] = temp;
				sort = 1;
			}
		}
		if(sort == 0) {
			break;
		}
	}
	return;
}

void sortDescending (int scores[]){
	int i, temp, sort;
	
	while (1) {
		sort = 0;
		
		for (i = 0; i < MAX -1; ++i) {
			if(scores[i] < scores[i + 1]) {
				temp = scores[i];
				scores[i] = scores[i + 1];
				scores[i + 1] = temp;
				sort = 1;
			}
		}
		if(sort == 0) {
			break;
		}
	}
	return;
}


