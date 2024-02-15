// function that gets the minimum and maximum intergers from an array of intergers
// and also gets the number of distinct (not repeating) intergers in the array
void getInfo(int array[], int size, int *min, int *max, int *distinct)
{
    int i, j;
    int minimum = array[0], maximum = array[0];
    int miniDist = 0;
    int distinctValues = 0;

    for (i = 0; i < size; i++) // for loop to iterate through the array
    {
        if (array[i] > maximum) // checks if current array member is larger than the current maximum
            maximum = array[i]; // if true chances maximum to be current array member
        if (array[i] < minimum) // checks if current array member is larger than the current minimum
            minimum = array[i]; // if true chances minimum to be current array member

        miniDist = 0;
        for (j = 0; j < size; j++) // nested for loop that checks each interger in the array to see if it is the same as other values in the array
        {
            if (array[i] == array[j])
                miniDist++; // increments by one for each occurance
        }
        if (miniDist == 1) // if there is one occuance, increments distinct values by 1
            distinctValues++;
    }

    // sets the pointers that are passed in to the values from the function
    *max = maximum;
    *min = minimum;
    *distinct = distinctValues;
}