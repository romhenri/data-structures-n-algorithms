#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

void InsertionSort(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        int pivo = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > pivo) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = pivo;
    }
}

int main() {
    string filename;
    cout << "Input File: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "ERR 404: " << filename << endl;
        return 1;
    }

    vector<int> A;
    int number;
    while (file >> number) {
        A.push_back(number);
    }
    file.close();

    if (A.empty()) {
        cerr << "ERR 400." << endl;
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();
    InsertionSort(A);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    double duration_s = chrono::duration<double>(end - start).count();

    cout << "InsertionSort Time: " << duration.count() << " ms, " << duration_s << " s" << endl;
    return 0;
}
