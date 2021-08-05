#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &ivec, int lo, int mi, int hi)
{
    int size = hi - lo + 1;
    vector<int> temp(size);
    int i = lo, j = mi + 1, k = 0;
    while (i <= mi && j <= hi)
    {
        if (ivec[i] <= ivec[j])
            temp[k++] = ivec[i++];
        else
            temp[k++] = ivec[j++];
    }

    while (i <= mi)
    {
        temp[k++] = ivec[i++];
    }
    while (j <= hi)
    {
        temp[k++] = ivec[j++];
    }
    for (i = lo, k = 0; k < size;++i,++k)
    {
        ivec[i] = temp[k];
    }
        
}

void mergeSort(vector<int> &ivec, int lo, int hi)
{
    if (hi <= lo)
        return;
    int mi = (hi + lo) >> 1;
    mergeSort(ivec, lo, mi);
    mergeSort(ivec, mi + 1, hi);
    merge(ivec, lo, mi, hi);
}
int main()
{
    vector<int> ivec = {6, 3, 2, 7, 1, 5, 8, 4};
    int n = ivec.size() - 1;
    mergeSort(ivec, 0, n);
    return 0;
}