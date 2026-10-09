#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace chrono;

void QuickSort(float a[], int left, int right);
void HeapSort(float a[], int n);
void MergeSort(float a[], int left, int right);

int main() {
    ofstream result("results.csv");

    result << "Dataset,QuickSort,HeapSort,MergeSort,STLSort\n";

    for (int k = 1; k <= 10; k++) {
        string filename = "data/data_";
        if (k < 10) filename += "0";
        filename += to_string(k) + ".txt";

        ifstream fin(filename);
        if (!fin) {
            cerr << "Khong mo duoc " << filename << '\n';
            return 1;
        }

        vector<float> original;
        float x;

        while (fin >> x)
            original.push_back(x);

        fin.close();

        if (original.empty()) {
            cerr << "Du lieu rong: " << filename << '\n';
            return 1;
        }

        cout << "Dang thu nghiem " << filename
             << " (" << original.size() << " phan tu)\n";

        vector<float> a;
        float t[4];

        a = original;
        auto start = steady_clock::now();
        QuickSort(a.data(), 0, (int)a.size() - 1);
        auto stop = steady_clock::now();
        t[0] = duration<float>(stop - start).count();

        a = original;
        start = steady_clock::now();
        HeapSort(a.data(), (int)a.size());
        stop = steady_clock::now();
        t[1] = duration<float>(stop - start).count();

        a = original;
        start = steady_clock::now();
        MergeSort(a.data(), 0, (int)a.size() - 1);
        stop = steady_clock::now();
        t[2] = duration<float>(stop - start).count();

        a = original;
        start = steady_clock::now();
        sort(a.begin(), a.end());
        stop = steady_clock::now();
        t[3] = duration<float>(stop - start).count();

        result << filename;
        for (float time : t)
            result << ',' << fixed << setprecision(6) << time;
        result << '\n';

        cout << fixed << setprecision(3)
             << "QuickSort: " << t[0] << " s\n"
             << "HeapSort:  " << t[1] << " s\n"
             << "MergeSort: " << t[2] << " s\n"
             << "STL sort:  " << t[3] << " s\n\n";
    }

    result.close();
    cout << "Da ghi ket qua vao results.csv\n";

    return 0;
}
