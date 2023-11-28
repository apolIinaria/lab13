#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int>> createMatrix(int n) 
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << setw(4) << value;
        }
        cout << endl;
    }
}

vector<vector<int>> rotate(const vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    vector<vector<int>> rotatedMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotatedMatrix[i][j] = matrix[n - j - 1][i];
        }
    }
    return rotatedMatrix;
}

int main() 
{
    srand(time(nullptr));

    int n;
    cout << "Введіть розмірність матриці n: ";
    cin >> n;

    vector<vector<int>> matrix = createMatrix(n);

    cout << "Початкова матриця:" << endl;
    printMatrix(matrix);

    vector<vector<int>> rotatedMatrix = rotate(matrix);

    cout << "Матриця після розвертання на 90 градусів за часовою стрілкою:" << endl;
    printMatrix(rotatedMatrix);

    return 0;
}
