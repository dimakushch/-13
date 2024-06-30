#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

//void Block(vector<int>& arr, int index, const vector<int>& block) {
//    
//    if (index < 0 || index > arr.size()) {
//        cout << "Неправильний індекс для вставки!" << endl;
//        return;
//    }
//    arr.insert(arr.begin() + index, block.begin(), block.end());
//}

vector<int> UValues(int** arr, int rows, int cols) {
    vector<int> Values;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = arr[i][j];
            if (find(Values.begin(), Values.end(), value) == Values.end()) {
                Values.push_back(value);
            }
        }
    }

    return Values;
}

vector<int> Common(int** arr1, int rows1, int cols1, int** arr2, int rows2, int cols2) {
    vector<int> common;

    for (int i1 = 0; i1 < rows1; ++i1) {
        for (int j1 = 0; j1 < cols1; ++j1) {
            int value1 = arr1[i1][j1];

            for (int i2 = 0; i2 < rows2; ++i2) {
                for (int j2 = 0; j2 < cols2; ++j2) {
                    int value2 = arr2[i2][j2];
                    if (value1 == value2 && find(common.begin(), common.end(), value1) == common.end()) {
                        common.push_back(value1);
                    }
                }
            }
        }
    }

    return common;
}

vector<int> Negative(int** arr, int rows, int cols) {
    vector<int> nega;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = arr[i][j];
            if (value < 0 && find(nega.begin(), nega.end(), value) == nega.end()) {
                nega.push_back(value);
            }
        }
    }

    return nega;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //1
    /*vector<int> array = { 1, 2, 3, 4, 5 };
    vector<int> blockToInsert = { 10, 11, 12 };

    int index;
    cout << "Введіть індекс для вставки: ";
    cin >> index;

    Block(array, index, blockToInsert);

    cout << "Результат після вставки: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;*/

    //2

    int rowsA, colsA, rowsB, colsB, rowsC, colsC;

    cout << "Введіть кількість рядків і стовпців для масиву A: ";
    cin >> rowsA >> colsA;
    cout << "Введіть кількість рядків і стовпців для масиву B: ";
    cin >> rowsB >> colsB;
    cout << "Введіть кількість рядків і стовпців для масиву C: ";
    cin >> rowsC >> colsC;

    int** A = new int* [rowsA];
    int** B = new int* [rowsB];
    int** C = new int* [rowsC];

    cout << "Введіть значення для масиву A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        A[i] = new int[colsA];
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Введіть значення для масиву B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        B[i] = new int[colsB];
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    cout << "Введіть значення для масиву C:" << endl;
    for (int i = 0; i < rowsC; ++i) {
        C[i] = new int[colsC];
        for (int j = 0; j < colsC; ++j) {
            cin >> C[i][j];
        }
    }

    vector<int> commonA = UValues(A, rowsA, colsA);
    vector<int> commonB = UValues(B, rowsB, colsB);
    vector<int> commonC = UValues(C, rowsC, colsC);

    vector<int> uniqueA = UValues(A, rowsA, colsA);
    vector<int> uniqueB = UValues(B, rowsB, colsB);
    vector<int> uniqueC = UValues(C, rowsC, colsC);

    vector<int> commonAC = Common(A, rowsA, colsA, C, rowsC, colsC);

    vector<int> NegativeA = Negative(A, rowsA, colsA);
    vector<int> NegativeB = Negative(B, rowsB, colsB);
    vector<int> NegativeC = Negative(C, rowsC, colsC);

    cout << "Загальні значення для A, B, C:" << endl;
    for (int num : commonA) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Унікальні значення для A, B, C:" << endl;
    for (int num : uniqueA) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Спільні значення для A і C:" << endl;
    for (int num : commonAC) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Від'ємні значення для A, B, C без повторень:" << endl;
    for (int num : NegativeA) {
        cout << num << " ";
    }
    for (int num : NegativeB) {
        if (find(NegativeA.begin(), NegativeA.end(), num) == NegativeA.end()) {
            cout << num << " ";
        }
    }
    for (int num : NegativeC) {
        if (find(NegativeA.begin(), NegativeA.end(), num) == NegativeA.end() &&
            find(NegativeB.begin(), NegativeB.end(), num) == NegativeB.end()) {
            cout << num << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < rowsB; ++i) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < rowsC; ++i) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}