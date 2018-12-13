#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *input;
	char data[100];
	int total = 0;
	input = fopen("frequency_changes.txt", "r");
	while (fgets(data, 100, input) != NULL) {
		total += atoi(data);
	}
	fclose(input);
	printf("Part 1: %d\n", total);
	return total;
}