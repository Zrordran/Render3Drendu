#ifndef MOTEURRENDU3D_MATRIX_H
#define MOTEURRENDU3D_MATRIX_H


#include <vector>
#include "Vector.h"
#include "Point.h"

struct Matrix {
    std::vector<std::vector<float>> m;
    int rows, cols;
public:
    Matrix(int rows, int cols);
    static Matrix identity(int dim);
    Matrix operator*(const Matrix& a);
};

#endif //MOTEURRENDU3D_MATRIX_H
