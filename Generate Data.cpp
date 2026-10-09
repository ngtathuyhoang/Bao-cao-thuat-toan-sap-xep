#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 1000000;

int main() {
    system("mkdir data");

    mt19937 rng(20261009);
    uniform_real_distribution<float> dist(-1000000.0f, 1000000.0f);

    for (int k = 1; k <= 10; k++) {
        vector<float> a(N);

        for (int i = 0; i < N; i++)
            a[i] = dist(rng);

        if (k == 1)
            sort(a.begin(), a.end());
        else if (k == 2)
            sort(a.begin(), a.end(), greater<float>());

        string filename = "data/data_";
        if (k < 10) filename += "0";
        filename += to_string(k) + ".txt";

        ofstream fout(filename);
        fout << fixed << setprecision(6);

        for (float x : a)
            fout << x << '\n';

        if (!fout) {
            cerr << "Loi ghi file: " << filename << '\n';
            return 1;
        }

        fout.close();
        cout << "Da tao: " << filename << '\n';
    }

    return 0;
}
