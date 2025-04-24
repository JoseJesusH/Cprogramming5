#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix Matrix;

Matrix* create_matrix(int rows, int cols);
void destroy_matrix(Matrix* m);
double get(Matrix* m, int row, int col);
void set(Matrix* m, int row, int col, double value);

Matrix* add_matrix(const Matrix* a, const Matrix* b);
Matrix* multiply_matrix(const Matrix* a, const Matrix* b);
void print_matrix(const Matrix* m);

#endif

