#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int r,int c) {
    this->cols = c;
    this->rows = r;
    this->m = std::vector<std::vector<float>>(r, std::vector<float>(c, 0.f));
}

Matrix Matrix::identity(int dim) {
    Matrix mat(dim, dim);
    for(int i = 0; i<dim; i++){
        for(int j = 0;j<dim; j++){
            if(i==j)
                mat.m[i][j] = 1;
            else
                mat.m[i][j] = 0;
        }
    }
    return mat;
}

Matrix Matrix::operator*(const Matrix& a) {
    Matrix result(rows, a.cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<a.cols; j++) {
            result.m[i][j] = 0.f;
            for (int k=0; k<cols; k++) {
                result.m[i][j] += m[i][k]*a.m[k][j];
            }
        }
    }
    return result;
}