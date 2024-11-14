#include <stdio.h>

int main() {
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
            return 0;
        }
    }

    if(fibMMm1 && a[offset + 1] == x) {
        printf("Element found at index %d\n", offset + 1);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
