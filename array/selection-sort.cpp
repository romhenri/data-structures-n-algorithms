#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    SelectionSort(A);

    cout << "Done: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
