#include <algorithm>
using namespace std;
void QuickSort(float *a, int l, int r)
{
    if (l >= r) return;

    float x = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}
