// --------------------------------------------------------------------------------
// Name: <Mariah Jackson>
// Class: 151-400
// Abstract: Homework 10 Resizable Arrays Part 1
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Includes – built-in libraries of functions
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------

void getArraySize(int* size);
int* allocateArray(int size);
void populateArray(int* arr, int size);
void printArray(int* arr, int size);
int findMax(int* arr, int size);
int findMin(int* arr, int size);
int calculateTotal(int* arr, int size);
double calculateAverage(int* arr, int size);
double calculateStdDev(int* arr, int size);


// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------

int main() {
    int size;
    getArraySize(&size);

    int* arr = allocateArray(size);
    populateArray(arr, size);
    printArray(arr, size);

    int max = findMax(arr, size);
    int min = findMin(arr, size);
    int total = calculateTotal(arr, size);
    double average = calculateAverage(arr, size);
    double stdDev = calculateStdDev(arr, size);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);
    printf("Standard Deviation: %.2f\n", stdDev);

    free(arr);
    return 0;
}



// --------------------------------------------------------------------------------
// Name: Get Array Size
// Abstract: 
// --------------------------------------------------------------------------------

void getArraySize(int* size) {
    printf("Enter array size (1 to 100,000): ");
    scanf_s("%d", size);
}



// --------------------------------------------------------------------------------
// Name: Generating size for Array
// Abstract: 
// --------------------------------------------------------------------------------

int* allocateArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    return arr;
}


// --------------------------------------------------------------------------------
// Name: populate array
// Abstract: 
// --------------------------------------------------------------------------------


void populateArray(int* arr, int size) {
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }
}


// --------------------------------------------------------------------------------
// Name: Print Array  location and components
// Abstract: 
// --------------------------------------------------------------------------------

void printArray(int* arr, int size) {
    printf("Array Contents:\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Location [%4d] = %6d\n", i + 1, arr[i]);
    }
    printf("\n");
}


// --------------------------------------------------------------------------------
// Name: Find Max
// Abstract: 
// --------------------------------------------------------------------------------
int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


// --------------------------------------------------------------------------------
// Name: FInd Min
// Abstract: 
// --------------------------------------------------------------------------------
int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


// --------------------------------------------------------------------------------
// Name: Total of Array
// Abstract: 
// --------------------------------------------------------------------------------
int calculateTotal(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}



// --------------------------------------------------------------------------------
// Name: Average fof Array
// Abstract: 
// --------------------------------------------------------------------------------
double calculateAverage(int* arr, int size) {
    int total = calculateTotal(arr, size);
    return (double)total / size;
}



// --------------------------------------------------------------------------------
// Name: Standard  deviation
// Abstract: 
// --------------------------------------------------------------------------------
double calculateStdDev(int* arr, int size) {
    double mean = calculateAverage(arr, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / size);
}



// --------------------------------------------------------------------------------
// Name: Add value to end
// Abstract: 
// --------------------------------------------------------------------------------
void AddValueToEnd(int** ppaintValues, int* pintArraySize, int intValueToAdd) {
    *ppaintValues = realloc(*ppaintValues, (*pintArraySize + 1) * sizeof(int));
    (*ppaintValues)[*pintArraySize] = intValueToAdd;
    (*pintArraySize)++;
}


// --------------------------------------------------------------------------------
// Name: Add value to front
// Abstract: 
// --------------------------------------------------------------------------------
void AddValueToFront(int** ppaintValues, int* pintArraySize, int intValueToAdd) {
    *ppaintValues = realloc(*ppaintValues, (*pintArraySize + 1) * sizeof(int));
    for (int i = *pintArraySize; i > 0; i--) {
        (*ppaintValues)[i] = (*ppaintValues)[i - 1];
    }
    (*ppaintValues)[0] = intValueToAdd;
    (*pintArraySize)++;
}



// --------------------------------------------------------------------------------
// Name: Insert Value
// Abstract: 
// --------------------------------------------------------------------------------
void InsertValueAt(int** ppaintValues, int* pintArraySize, int intValueToInsert, int intInsertAtIndex) {
    if (intInsertAtIndex < 0 || intInsertAtIndex > *pintArraySize) {
        printf("Index out of bounds\n");
        return;
    }
    *ppaintValues = realloc(*ppaintValues, (*pintArraySize + 1) * sizeof(int));
    for (int i = *pintArraySize; i > intInsertAtIndex; i--) {
        (*ppaintValues)[i] = (*ppaintValues)[i - 1];
    }
    (*ppaintValues)[intInsertAtIndex] = intValueToInsert;
    (*pintArraySize)++;
}



// --------------------------------------------------------------------------------
// Name: Remove value from list
// Abstract: 
// --------------------------------------------------------------------------------
void RemoveAt(int** ppaintValues, int* pintArraySize, int intRemoveAtIndex) {
    if (intRemoveAtIndex < 0 || intRemoveAtIndex >= *pintArraySize) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = intRemoveAtIndex; i < *pintArraySize - 1; i++) {
        (*ppaintValues)[i] = (*ppaintValues)[i + 1];
    }
    *ppaintValues = realloc(*ppaintValues, (*pintArraySize - 1) * sizeof(int));
    (*pintArraySize)--;
}