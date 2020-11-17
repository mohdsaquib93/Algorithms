#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &vec, int l, int r, int key)
{
    int fo = -1;
    while( l <= r) {
        int mid = (l + r) / 2;
        if (key == vec.at(mid)) {
            fo = mid;
            r = mid - 1;
        }
        else if (key < vec.at(mid))
            r = mid -1;
        else l = mid + 1;
    }
    return fo;
}

int main()
{
    vector<int> vec{1,3,4,4,4,4,4,4,5,6};
    cout << binarySearch(vec, 0, vec.size() - 1, 4) << endl;
    return  0;

}