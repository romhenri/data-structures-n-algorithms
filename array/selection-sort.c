#include <stdio.h>

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int i_min = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[i_min]) {
                i_min = j;
            }
        }

        if (A[i] != A[i_min]) {
            int temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
    }
}

int main() {
    int A[] = {11, 5, 9, 2, 25};
    int n = sizeof(A) / sizeof(A[0]);

    SelectionSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}