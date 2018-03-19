#include <math.h>
#include "matrix_lib.h"

using namespace std;
using namespace MatrixLib;

MatrixLib::Matrix::Matrix(const Matrix &m){
    rows = m.rows;
    cols = m.cols;
    table = new float*[rows];
    for (int i = 0; i < rows; i++){
        table[i] = new float[cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            table[i][j] = m.table[i][j];
        }
    }
}

MatrixLib::Matrix::Matrix(MSIZE_T rows, MSIZE_T cols){
    rows = rows;
    cols = cols;
    table = new float*[rows];
    for (int i = 0; i < rows; i++){
        table[i] = new float[cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            table[i][j] = 0;
        }
    }
}

MatrixLib::Matrix::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete(table[i]);
    }
    delete[] table;
}

MITEM_T* MatrixLib::Matrix::operator[](const MSIZE_T &a) const{
    return table[a];
}

Matrix transposed(const Matrix &m){
    Matrix result(m.cols, m.rows);
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            result.table[i][j] = m.table[j][i];
        }
    }
    return result;
}

MITEM_T MatrixLib::Matrix::getDeterminant() const{
    MITEM_T result(0);
    if(cols == 1){
        result = table[0][0];
    }else{
        for(int i = 0; i < rows; i+=2){
            Matrix matr_minor(rows - 1, cols - 1);
            for(int k = 0; k < 0; k++){
                for(int l = 0; l < i; l++){
                    matr_minor.table[k][l] = table[k][l];
                }
                for(int l = i + 1; l < cols; l++){
                    matr_minor.table[k][l-1] = table[k][l];
                }
            }

            for(int k = 1; k < rows; k++){
                for(int l = 0; l < 0; l++){
                    matr_minor.table[k-1][l] = table[k][l];
                }
                for(int l = 1; l < cols; l++){
                    matr_minor.table[k-1][l-1] = table[k][l];
                }
            }
            result += table[0][i] * matr_minor.getDeterminant();
        }
        for(int i = 1; i < rows; i+=2){
            Matrix matr_minor(rows - 1, cols - 1);
            for(int k = 0; k < 0; k++){
                for(int l = 0; l < i; l++){
                    matr_minor.table[k][l] = table[k][l];
                }
                for(int l = i + 1; l < cols; l++){
                    matr_minor.table[k][l-1] = table[k][l];
                }
            }

            for(int k = 1; k < rows; k++){
                for(int l = 0; l < 0; l++){
                    matr_minor.table[k-1][l] = table[k][l];
                }
                for(int l = 1; l < cols; l++){
                    matr_minor.table[k-1][l-1] = table[k][l];
                }
            }
            result -= table[0][i] * matr_minor.getDeterminant();
        }
    }
    return result;
}

Matrix MatrixLib::Matrix::getInverse() const{
    MITEM_T determinant = getDeterminant();

    Matrix transposed = ::transposed(::uni(*this));
    MITEM_T a = 1 / determinant;
    for(int i = 0; i < transposed.rows; i++){
        for(int j = 0; j < transposed.cols; j++){
            transposed.table[i][j] *= a;
        }
    }

    return transposed;
}

Matrix MatrixLib::operator*(const Matrix &a, const Matrix &b){
    Matrix result(a.rows, b.cols);
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            for(int k = 0; k < a.cols; k++){
                result.table[i][j] += a.table[i][k] * b.table[k][j];
            }
        }
    }

    return result;
}

Matrix MatrixLib::operator+(const Matrix &a, const Matrix &b){
    Matrix result(a.rows, a.cols);
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            result.table[i][j] = a.table[i][j] + b.table[i][j];
        }
    }

    return result;
}

Matrix MatrixLib::operator-(const Matrix &a, const Matrix &b){
    Matrix result(a.rows, a.cols);
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            result.table[i][j] = a.table[i][j] - b.table[i][j];
        }
    }

    return result;
}

ostream& MatrixLib::operator<<(ostream &out, const Matrix &m){
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.cols; j++){
            out << m.table[i][j] << '\t';
        }
        out << '\n';
    }

    return out;
}
