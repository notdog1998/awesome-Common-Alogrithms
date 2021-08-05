#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int partition(vector<int> &ivec, int lo, int hi)
{
    int pivot = ivec[lo];
    while (lo < hi)
    {
        while ((lo < hi) && (pivot <= ivec[hi]))
            --hi;
        ivec[lo] = ivec[hi];
        while ((lo < hi) && (pivot >= ivec[lo]))
            ++lo;
        ivec[hi] = ivec[lo];
    }
    ivec[lo] = pivot;
    return lo;
}

void quickSort(vector<int> &ivec, int lo, int hi)
{
    if (hi <= lo)
        return;
    int mi = partition(ivec, lo, hi);
    quickSort(ivec, lo, mi - 1);
    quickSort(ivec, mi + 1, hi);
}
int main()
{
    vector<int> ivec = {6, 3, 8, 2, 5, 9, 4, 5, 1, 7};
    quickSort(ivec, 0, ivec.size() - 1);
    return 0;
}