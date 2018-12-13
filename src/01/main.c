#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input;
	char data[100];
	int total = 0;
	int repeat = 0;
	int firstIteration = 0;
	int positives[1000000] = { 0 };
	int negatives[1000000] = { 0 };
	while (repeat == 0) {
		input = fopen("frequency_changes.txt", "r");
		while (fgets(data, 100, input) != NULL) {
			total += atoi(data);
			if (total < 0) {
				if (negatives[abs(total)] == 1 && repeat == 0) {
					printf("Part 2: %d\n", total);
					repeat = 1;
				}
				negatives[abs(total)] = 1;
			}
			else {
				if (positives[total] == 1 && repeat == 0) {
					printf("Part 2: %d\n", total);
					repeat = 1;	
				}
				positives[total] = 1;
			}
		}
		if (firstIteration == 0) {
			printf("Part 1: %d\n", total);
			firstIteration ++;
		}
	}
	fclose(input);

	return 0;
}