#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int a[100], size;

    printf("Enter the number of elements required: ");
    scanf("%d", &size);
    printf("Enter the total integers: ");

    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    // Calling the quicksort function
    quickSort(a, 0, size - 1);

    // Printing the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
