#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Define internal Matrix structure
struct Matrix {
    int rows;
    int cols;
    double** data;
};

Matrix* create_matrix(int rows, int cols) {
   // Allocate space for the Matrix struct
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = calloc(cols, sizeof(double));
    }
    return m;
}

void destroy_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) free(m->data[i]);
     // Free internal data and struct itself
    free(m->data);
    free(m);
}

double get(Matrix* m, int row, int col) {
     // Get value at specified index
    return m->data[row][col];
}

void set(Matrix* m, int row, int col, double value) {
    // Set value at specified index (row-major order)
    m->data[row][col] = value;
}

Matrix* add_matrix(const Matrix* a, const Matrix* b) {
   // Check if dimensions match
    if (a->rows != b->rows || a->cols != b->cols) return NULL;
    Matrix* result = create_matrix(a->rows, a->cols);
     // Element-wise addition
    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < a->cols; j++)
            result->data[i][j] = a->data[i][j] + b->data[i][j];
    return result;
}

Matrix* multiply_matrix(const Matrix* a, const Matrix* b) {
    // Check if multiplication is possible
    if (a->cols != b->rows) return NULL;
    Matrix* result = create_matrix(a->rows, b->cols);
    // Standard matrix multiplication
    for (int i = 0; i < a->rows; i++)
        for (int j = 0; j < b->cols; j++)
            for (int k = 0; k < a->cols; k++)
                result->data[i][j] += a->data[i][k] * b->data[k][j];
    return result;
}

void print_matrix(const Matrix* m) {
    // Print each row
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%6.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

