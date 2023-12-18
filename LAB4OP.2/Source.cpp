#include <iostream>
#include <cstdlib>
using namespace std;
int calculateColumnCharacteristic(int** matrix, int rows, int column) {
    int characteristic = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][column] < 0 && (matrix[i][column]) % 2 != 0) {
            characteristic += abs(matrix[i][column]);
        }
    }
    return characteristic;
}
void swapColumns(int** matrix, int rows, int column1, int column2) {
    for (int i = 0; i < rows; ++i) {
        int temp = matrix[i][column1];
        matrix[i][column1] = matrix[i][column2];
        matrix[i][column2] = temp;
    }
}
void printMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < columns - 1; ++i) {
        for (int j = 0; j < columns - i - 1; ++j) {
            if (calculateColumnCharacteristic(matrix, rows, j) > calculateColumnCharacteristic(matrix, rows, j + 1)) {
                swapColumns(matrix, rows, j, j + 1);
            }
        }
    }
    cout << "Sorted matrix:" << endl;
    printMatrix(matrix, rows, columns);
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
