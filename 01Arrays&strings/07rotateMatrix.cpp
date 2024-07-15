//https://godbolt.org/z/TGnozjPT9

// inplace （N*N）

#include <iostream>
#include <vector>

void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: switch i row  
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: reverse
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            std::swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    std::cout << "Matrix after rotating 90 degrees clockwise (in place):" << std::endl;
    printMatrix(matrix);

    return 0;
}
