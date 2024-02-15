#include "lab1.h"

int main(int argc, char *argv[])
{
    int array[5] = {1, 1, 1, 3, 1};
    int size = -1;
    int sum;
    float average;

    getAverage(array, size, &average);
    printf("\nAverage = %f", average);
    sumEven(array, size, &sum);
    printf("\nSum of Even Numbers = %d", sum);

    return 0;
}