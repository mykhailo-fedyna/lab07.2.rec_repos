// Lab_7_2_1.cpp
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int K, const int N, int rowNo);
int SearchMaxInRowRecursive(int* row, const int N, int colNo, int maxIndex);
int SearchMinInRowRecursive(int* row, const int N, int colNo, int minIndex);
void SwapMaxMinRows(int** a, const int K, const int N, int rowNo);
int main() {
    srand((unsigned)time(NULL));
    int Low, High, N, K;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;
    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];
    CreateRows(a, K, N, Low, High, 0);
    PrintRows(a, K, N, 0);
    SwapMaxMinRows(a, K, N, 1);
    cout << "Modified Matrix:" << endl;
    PrintRows(a, K, N, 0);
    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}
void PrintRows(int** a, const int K, const int N, int rowNo) {
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}
int SearchMaxInRowRecursive(int* row, const int N, int colNo, int maxIndex) {
    if (row[colNo] > row[maxIndex])
        maxIndex = colNo;
    if (colNo < N - 1)
        return SearchMaxInRowRecursive(row, N, colNo + 1, maxIndex);
    else
        return maxIndex;
}
int SearchMinInRowRecursive(int* row, const int N, int colNo, int minIndex) {
    if (row[colNo] < row[minIndex])
        minIndex = colNo;
    if (colNo < N - 1)
        return SearchMinInRowRecursive(row, N, colNo + 1, minIndex);
    else
        return minIndex;
}
void SwapMaxMinRows(int** a, const int K, const int N, int rowNo) {
    int maxIndex = SearchMaxInRowRecursive(a[rowNo], N, 0, 0);
    int minIndex = SearchMinInRowRecursive(a[rowNo - 1], N, 0, 0);
    int temp = a[rowNo][maxIndex];
    a[rowNo][maxIndex] = a[rowNo - 1][minIndex];
    a[rowNo - 1][minIndex] = temp;
    cout << "Swapped elements from row " << rowNo << " and row " << rowNo - 1 << endl << endl;
    if (rowNo < K - 1)
        SwapMaxMinRows(a, K, N, rowNo + 2);
}
