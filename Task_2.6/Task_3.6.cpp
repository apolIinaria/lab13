#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 

using namespace std;

int calculate_sum(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (const auto& row : matrix) {
        for (int element : row) {
            if (element > 0) {
                sum += element;
            }
        }
    }
    return sum;
}

void calculate_count(const vector<vector<int>>& matrix, int Z) {
    int columns = matrix[0].size();
    for (int col = 0; col < columns; ++col) {
        int count = 0;
        for (const auto& row : matrix) {
            if (row[col] <= Z) {
                count++;
            }
        }
        cout << "Стовпець " << col + 1 << ": " << count << " елементів не перевищують " << Z << endl;
    }
}

void fill_Matrix(vector<vector<int>>& matrix) {
    srand(time(0));
    int size = matrix.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100 + 1 ;
        }
    }
}

vector<vector<int>> transpose_Matrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<int>> result(columns, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int columns = matrix1[0].size();
    vector<vector<int>> result(rows, vector<int>(columns));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

void print_Matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }
}

int main() 
{
    const int size = 5;

    vector<vector<int>> matrix(size, vector<int>(size));
    vector<vector<int>> transposedMatrix(size, vector<int>(size));

    fill_Matrix(matrix);
    cout << "Вихідна матриця:" << endl;
    print_Matrix(matrix);

    int sum = calculate_sum(matrix);
    cout << "Сума додатних елементів: " << sum << endl;

    int Z;
    cout << "Введіть число Z: " << endl;
    cin >> Z;
    calculate_count(matrix, Z);

    transposedMatrix = transpose_Matrix(matrix);
    cout << "Транспонована матриця:" << endl;
    print_Matrix(transposedMatrix);

    vector<vector<int>> sumMatrix = addMatrices(matrix, transposedMatrix);
    cout << "Сума матриці та її транспонованої:" << endl;
    print_Matrix(sumMatrix);

    return 0;
}

