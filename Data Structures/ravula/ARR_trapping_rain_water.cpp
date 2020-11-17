#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, volume = 0, maxl = 0, maxr = 0;
    cout << "Enter no of buildings: ";
    cin >> num;
    vector<int> bldg(num);
    vector<int> left(num);
    vector<int> right(num);

    cout << "Enter height of buildings: ";
    for(int i = 0; i < num; ++i)
        cin >> bldg.at(i);

    for(int i = 0, j = num - 1; i < num; ++i, --j) {
        if(bldg.at(i) > maxl)
            maxl = bldg.at(i);
        left.at(i) = maxl;
        if(bldg.at(j) > maxr)
            maxr = bldg.at(j);
        right.at(j) = maxr;
    }

    for(int i = 0; i < num; ++i) {
        int boundary = min(left.at(i), right.at(i));
        volume += (boundary - bldg.at(i));
    }

    cout << "Volume of stored water: " << volume << endl;
    return 0;
}
