#include <stdio.h>

void InsertionSort(int A[], int n) {
    int pivo = 0;
    for (int i = 1; i < n; i++) {
        pivo = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > pivo) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = pivo;
    }
}

int main() {
    int A[] = {11, 5, 9, 2, 25};
    int n = sizeof(A) / sizeof(A[0]);

    InsertionSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
