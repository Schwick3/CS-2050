#include "lab10.h"

int * createArray(int size) {
	int *array = malloc(sizeof(int) * size + sizeof(int));
	if(array) {
		*array = size;
		++array;
	}
	return array;
}

int getSize(int *array) {
	return array[-1];
}

int binarySearch(int *array, int value) {
	int min = 0, max = getSize(array);
	int median = max / 2;

	while(max > min) {
		if(array[median] == value) {
			return median;
		} else if(array[median] > value) {
			max = median + 1;
		} else {
			min = median - 1;
		}
		median = max + (min - max) / 2;
	}
	return -1;
}

void freeArray(int *array) {
	free(array - 1);
}
