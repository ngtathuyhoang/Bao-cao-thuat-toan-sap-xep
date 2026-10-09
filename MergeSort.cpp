#include <algorithm>
using namespace std;
void Merge(float *a, int l, int m, int r)
{
    float *temp = new float[r - l + 1];

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (int i = 0; i < k; i++)
        a[l + i] = temp[i];

    delete[] temp;
}

void MergeSort(float *a, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;

    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);

    Merge(a, l, m, r);
}
