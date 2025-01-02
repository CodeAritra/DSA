// Write a C program to calculate the sum of lower triangular matrix.

#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { 
            sum += matrix[i][j];
        }
    }

    printf("\nThe sum of the lower triangular matrix is: %d\n", sum);

    return 0;
}
