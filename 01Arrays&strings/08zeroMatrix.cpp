// https://godbolt.org/z/5navPs8Pj
#include <bits/stdc++.h>

using namespace std;

vector<std::vector<int>> setZeroes(vector<std::vector<int>> &v){

    int m = v.size();
    int n = v[0].size();
    // which row and col sould be reset to 0
    std::vector<bool> row_zero(m, false);
    std::vector<bool> col_zero(n, false);


    for(int i = 0; i< m ;i++){
        for(int j = 0; j<n; j++){
            if(v[i][j] == 0){
                row_zero[i] = true;
                col_zero[j] = true;
            }
        }
    }

    //set to 0

    for(int i = 0; i< m ;i++){
        for(int j = 0; j<n; j++){
            if(row_zero[i] || col_zero[j]){
                v[i][j] = 0;
            }
        }
    }

    return v;


}



void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 0, 9, 10},
        {11, 0, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    setZeroes(matrix);

    std::cout << "Matrix after setting zeroes:" << std::endl;
    printMatrix(matrix);

    return 0;
}
