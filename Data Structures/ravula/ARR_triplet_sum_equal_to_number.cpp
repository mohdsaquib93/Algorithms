#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, num, target, l, r;
    cout << "Enter the target: ";
    cin >> target;
    cout << "Enter number of elements: ";
    cin >> num;
    vector<int> vec(num);

    cout << "Enter array elements: ";
    for (i = 0; i < num; ++i)
        cin >> vec.at(i);

    sort(vec.begin(), vec.end());
    for(i = 0; i < num - 2; ++i) {
        l = i + 1, r = num - 1;
        while(l < r) {
            int sum = vec.at(i) + vec.at(l) + vec.at(r);
            if(sum == target)
                goto end;
            if(sum < target)
                ++l;
            else
                --r;
        }
    }

    if(i == num - 2)
        cout << "No triplet possible" << endl;
    else
        end:
        cout << "Triplet(a,b,c): (" << vec.at(i) << ","
            << vec.at(l) << "," << vec.at(r) << ")" << endl;
    return 0;
}
