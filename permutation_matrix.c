#include <stdio.h>

int isPermutationMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        int rowCount = 0;
        int colCount = 0;
        for (int j = 0; j < n; j++) {
            rowCount += matrix[i][j];
            colCount += matrix[j][i];
        }
        if (rowCount != 1 || colCount != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 3;
    int matrix[3][3] = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1}
    };

    if (isPermutationMatrix(n, matrix)) {
        printf("It is a permutation matrix.\n");
    } else {
        printf("It is NOT a permutation matrix.\n");
    }

    return 0;
}

