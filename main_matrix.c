#include <stdio.h>
#include "matrix.h"

int main() {
    // Create two matrices of size 2x2
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);

    // Fill matrices with values
    set(A, 0, 0, 1.0); set(A, 0, 1, 2.0);
    set(A, 1, 0, 3.0); set(A, 1, 1, 4.0);

    set(B, 0, 0, 5.0); set(B, 0, 1, 6.0);
    set(B, 1, 0, 7.0); set(B, 1, 1, 8.0);

    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);

    // Matrix addition
    Matrix* C = add_matrix(A, B);
    printf("A + B:\n");
    print_matrix(C);

    // Matrix multiplication
    Matrix* D = multiply_matrix(A, B);
    printf("A * B:\n");
    print_matrix(D);

    // Cleanup
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);
    destroy_matrix(D);

    return 0;
}

