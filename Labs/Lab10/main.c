#include "lab10.h"
int main() {
	int size = 50;
	int *array = createArray(size);

	for(int i = 0; i < size; ++i) {
		array[i] = i;
	}

	if(binarySearch(array, 50) != -1) {
		puts("BinarySearch() unexpectedly returned true");
	} else {
		puts("BinarySearch() successfully returned false");
	}

	if(binarySearch(array, -1) != -1) {
		puts("BinarySearch() unexpectedly returned true");
	} else {
		puts("BinarySearch() successfully returned false");
	}

	if(binarySearch(array, 25) != 25) {
		puts("BinarySearch() failed to locate 25");
	} else {
		puts("BinarySearch() successfully located 25");
	}

	if(binarySearch(array, 0) != 0) {
		puts("BinarySearch() failed to locate 0");
	} else {
		puts("BinarySearch() successfully located 0");
	}

	freeArray(array);
}
