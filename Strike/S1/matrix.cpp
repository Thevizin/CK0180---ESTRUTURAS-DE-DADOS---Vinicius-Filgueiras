#include <iostream>
using namespace std;

struct Matrix {
    int rows;
    int cols;
    double **data;
};

void matrix_construct(Matrix &matrix, int m, int n){
    matrix.rows = m;
    matrix.cols = n;
    matrix.data = new double*[m];
    for (int i = 0; i < m; ++i){
        matrix.data[i] = new double[n];
    }
}

void matrix_destruct(Matrix &matrix){
    for (int i = 0; i < matrix.rows; ++i) {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
    matrix.data = nullptr;
}

void set_element(Matrix &matrix, int i, int j, double value){
    if(i >=0 && i < matrix.rows && j >= 0 && j < matrix.cols){
        matrix.data[i][j] = value;
    }
    else{
        cerr << "Index out of bounds" << endl;
    }
}

double get_element(const Matrix &matrix, int i, int j){
    if(i >=0 && i < matrix.rows && j >= 0 && j < matrix.cols){
        return matrix.data[i][j];
    }
    else{
        cerr << "Index out of bounds" << endl;
        return -1;
    }
}

void read_matrix(Matrix &matrix){
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix.data[i][j];
        }
    }
}

void print_matrix(const Matrix &matrix){
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix add_matrices(const Matrix &matrix1, const Matrix &matrix2){
    Matrix result;
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        cerr << "Matrices dimensions do not match" << endl;
        exit(EXIT_FAILURE);
    }
    matrix_construct(result, matrix1.rows, matrix1.cols);
    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    Matrix matrix1, matrix2, sum_matrix;

    matrix_construct(matrix1, m, n);
    matrix_construct(matrix2, m, n);

    cout << "Enter elements for the first matrix:" << endl;
    read_matrix(matrix1);

    cout << "Enter elements for the second matrix:" << endl;
    read_matrix(matrix2);

    sum_matrix = add_matrices(matrix1, matrix2);

    cout << "Sum of the matrices:" << endl;
    print_matrix(sum_matrix);

    matrix_destruct(matrix1);
    matrix_destruct(matrix2);
    matrix_destruct(sum_matrix);

    return 0;
}
