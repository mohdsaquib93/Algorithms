#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, num, target, a, b;
    cout << "Enter the target: ";
    cin >> target;
    cout << "Enter number of elements: ";
    cin >> num;
    vector<int> vec(num);
    unordered_multimap<int, int> hash;

    cout << "Enter array elements: ";
    for (i = 0; i < num; ++i)
        cin >> vec.at(i);

    for (i = 0; i < num; ++i) {
        a = vec.at(i);
        b = target - a;
        if (hash.find(b) != hash.end())
            break;
        hash.insert(pair<int, int>(vec.at(i), i));
    }

    if (i == num)
        cout << "No pair possible" << endl;
    else
        cout << "Pair (a,b): (" << a << "," << b << ")" << endl;
    return 0;
}
