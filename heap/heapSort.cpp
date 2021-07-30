#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void percolateDown(vector<int> &ivec, int i, int heapSize)
{
    int lc = 1 + (i << 1), rc = (1 + i) << 1;
    int largest = i;
    if (rc < heapSize && ivec[rc] > ivec[largest])
    {
        largest = rc;
    }
    if (lc < heapSize && ivec[lc] > ivec[largest])
    {
        largest = lc;
    }
    if (i != largest)
    {
        swap(ivec[i], ivec[largest]);
        //        i = largest;
        percolateDown(ivec, largest, heapSize);
    }
}

void heapify(vector<int> &ivec)
{
    int n = ivec.size();
    int lastInternal = (n >> 1) - 1;
    for (int i = lastInternal; i >= 0; i--)
    {
        percolateDown(ivec, i, n);
    }
}
void heapSort(vector<int> &ivec)
{
    heapify(ivec);
    int heapSize = ivec.size();
    for (int i = ivec.size() - 1; i > 0; i--)
    {
        swap(ivec[0], ivec[i]);
        --heapSize;
        percolateDown(ivec, 0, heapSize);
    }
}
int main()
{
    vector<int> ivec = {4, 2, 5, 1, 3};
//    heapify(ivec);
    heapSort(ivec); 
    return 0;
}