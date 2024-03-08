#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data;
    int swaps;
} Swaps;

void initializeSwap(Swaps array[], int src[], int size) {
    for (int i = 0; i < size; i++) {
        array[i].data = src[i];
        array[i].swaps = 0;
    }
}

//print the total number of swaps
void printSwap(Swaps array[], int size) {
    int totalSwaps = 0;
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array[i].data, array[i].swaps);
        totalSwaps += array[i].swaps;
    }
    printf("Total # of swaps: %d\n\n", totalSwaps/2);
}

//swaps the elements in the array
void bubbleSort(Swaps array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].data > array[j + 1].data) {
                Swaps temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                array[j].swaps++;
                array[j + 1].swaps++;
            }
        }
    }
}

//prints the array
void selectionSort(Swaps array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (array[j].data < array[min_idx].data)
                min_idx = j;

        if (min_idx != i) {
            Swaps temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            array[min_idx].swaps++;
            array[i].swaps++;
        }
    }
}

int main() {
    //arrays
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    
    Swaps swapArray1[n1];
    Swaps swapArray2[n2];

    // Bubble Sort on Array 1
    initializeSwap(swapArray1, array1, n1);
    bubbleSort(swapArray1, n1);
    printf("array1 bubble sort:\n");
    printSwap(swapArray1, n1);

    // Bubble Sort on Array 2
    initializeSwap(swapArray2, array2, n2);
    bubbleSort(swapArray2, n2);
    printf("array2 bubble sort:\n");
    printSwap(swapArray2, n2);

    // Selection Sort on Array 1
    initializeSwap(swapArray1, array1, n1);
    selectionSort(swapArray1, n1);
    printf("array1 selection sort:\n");
    printSwap(swapArray1, n1);

    // Selection Sort on Array 2
    initializeSwap(swapArray2, array2, n2);
    selectionSort(swapArray2, n2);
    printf("array2 selection sort:\n");
    printSwap(swapArray2, n2);

    return 0;
}
