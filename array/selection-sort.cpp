#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

void SelectionSort(vector<int>& A) {
    int n = A.size();

    for (int i = 0; i < n - 1; i++) {
        int i_min = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[i_min]) {
                i_min = j;
            }
        }

        if (A[i] != A[i_min]) {
            int temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
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
    SelectionSort(A);
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    double duration_s = chrono::duration<double>(end - start).count();
    
    cout << "SelectionSort Time: " << duration.count() << " ms, " << duration_s << " s" << endl;
    return 0;
}
