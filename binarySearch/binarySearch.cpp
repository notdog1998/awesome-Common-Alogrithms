#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//返回<=e的第一个元素位置
int binarySearch (vector<int>& ivec, int e) {
    int lo = 0, hi = ivec.size() - 1;
    while (lo <= hi) {
        int mi = lo + ((hi - lo) >> 1);
        if (ivec[mi] <= e) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }
    return hi;
}
int main () {
    vector<int> ivec = {1 ,3 ,5 ,6, 7 ,8 , 9,10};
    int test01 = binarySearch(ivec, 5);
    int test02 = binarySearch(ivec, 4);
    cout << test01 << ' ' << test02 << endl;
    return 0;
}