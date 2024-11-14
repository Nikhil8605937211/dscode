    #include <stdio.h>
    #include <stdlib.h>


    void bubbleSort();
    void mergeSortDriver();
    void mergeSort(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);
    void binarySearch();
    void insertionSort();
    void quickSort();
    void fibonacciSearch();

    int main() {
        int choice;

        while(1) {
            printf("\nMenu:\n");
            printf("1. Bubble Sort\n");
            printf("2. Merge Sort\n");
            printf("3. Quick Sort\n"); 
            printf("4. Insertion Sort\n");
            printf("5. Binary Search\n");
            printf("6. Fibonacci Search\n");
            printf("7. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    bubbleSort();
                    break;
                case 2:
                    mergeSortDriver();
                    break;
                case 3:
                quickSort(); 
                    break;
                case 4:
                    insertionSort();
                    break;
                case 5:
                    binarySearch();
                    break;
                case 6:
                    fibonacciSearch();
                    break;
                case 7:
                    exit(0);
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
        return 0;
    }

    void bubbleSort() {
        int a[100], size, temp;

        printf("Enter the number of elements required: ");
        scanf("%d", &size);
        printf("Enter the total integers:\n");

        for(int i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }
    
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        printf("Sorted array using Bubble Sort:\n");
        for(int i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    void mergeSortDriver() {
        int arr[100];
        int n;

        printf("Enter the number of elements: ");
        scanf("%d", &n);
        printf("Enter the array elements:\n");

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        mergeSort(arr, 0, n - 1);

        printf("Sorted array using Merge Sort:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    void merge(int arr[], int left, int mid, int right) {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];

        for (i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void binarySearch() {
        int size, a[100], mid, high, low, i, ele;
        printf("Enter the size of array: ");
        scanf("%d", &size);
        printf("Enter the sorted array elements:\n");
        for(i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }

        printf("Enter the number you want to search: ");
        scanf("%d", &ele);

        low = 0;
        high = size - 1;

        while(low <= high) {
            mid = (low + high) / 2;
            if(a[mid] == ele) {
                printf("The element %d was found at position %d\n", ele, mid + 1);
                return;
            }
            if(a[mid] < ele) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        printf("Element not found in the array.\n");
    }

    void insertionSort() {
        int a[100], size, temp, i, j;

        printf("Enter the number of elements required: ");
        scanf("%d", &size);
        printf("Enter the integers:\n");

        for(i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }

        for(i = 1; i < size; i++) {
            temp = a[i];
            j = i - 1;

            while(j >= 0 && a[j] > temp) {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = temp;
        }

        printf("Sorted array using Insertion Sort:\n");
        for(i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    void quickSort() {
        int a[100], size, i, j, pivot, temp;

        printf("Enter the number of elements: ");
        scanf("%d", &size);
        printf("Enter the elements: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }


        int low = 0, high = size - 1;
        int stack[100];
        int top = -1;

        stack[++top] = low;
        stack[++top] = high;

        while (top >= 0) {
            high = stack[top--];
            low = stack[top--];

            pivot = a[high];
            i = low - 1;

            for (j = low; j <= high - 1; j++) {
                if (a[j] <= pivot) {
                    i++;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            temp = a[i + 1];
            a[i + 1] = a[high];
            a[high] = temp;

            int p = i + 1;

            if (p - 1 > low) {
                stack[++top] = low;
                stack[++top] = p - 1;
            }

            if (p + 1 < high) {
                stack[++top] = p + 1;
                stack[++top] = high;
            }
        }

        printf("Sorted array using Quick Sort:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    void fibonacciSearch() {
        int size, i, x, offset, fibMMm2, fibMMm1, fibM, index;
        int a[100];

        printf("Enter the number of elements: ");
        scanf("%d", &size);
        printf("Enter the sorted array elements: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }

        printf("Enter the element to search: ");
        scanf("%d", &x);


        fibMMm2 = 0;
        fibMMm1 = 1;  
        fibM = fibMMm2 + fibMMm1;  

    
        while (fibM < size) {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM  = fibMMm2 + fibMMm1;
        }

        offset = -1;

    
        while (fibM > 1) {

            index = offset + fibMMm2 < size ? offset + fibMMm2 : size - 1;

        
            if (a[index] < x) {
                fibM  = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = index;
            }

        
            else if (a[index] > x) {
                fibM  = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            }


            else {
                printf("Element found at index %d\n", index);
                return;
            }
        }

        if(fibMMm1 && a[offset + 1] == x) {
            printf("Element found at index %d\n", offset + 1);
        } else {
            printf("Element not found in the array.\n");
        }
    }
