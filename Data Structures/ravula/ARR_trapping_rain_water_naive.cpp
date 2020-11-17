#include <bits/stdc++.h>

using namespace std;

int findMaxBoundary(vector<int> &vec, int begin, int end)
{
    return *max_element(vec.begin() + begin, vec.begin() + end);
}

int main()
{
    int num, volume = 0, maxl = 0, maxr = 0;
    cout << "Enter no of buildings: ";
    cin >> num;
    vector<int> bldg(num);

    cout << "Enter height of buildings: ";
    for(int i = 0; i < num; ++i)
        cin >> bldg.at(i);

    for(int i = 0; i < num; ++i) {
        int boundary = min(findMaxBoundary(bldg, 0, i + 1), findMaxBoundary(bldg, i, num));
        volume += (boundary - bldg.at(i));
    }

    cout << "Volume of wate stored: " << volume << endl;
    return 0;
}
