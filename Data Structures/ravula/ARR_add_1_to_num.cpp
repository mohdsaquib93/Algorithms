#include <bits/stdc++.h>

using namespace std;

void add_one(vector<int> &vec)
{
    int flag = 1;
    for(int i = vec.size() - 1; i >= 0; --i) {
        if (flag) {
            int x = vec.at(i) + 1;
            vec.at(i) = x % 10;
            flag = 0;
            if (x > 9)
                flag = 1;
        }
    }
    if (flag)
        vec.insert(vec.begin(), 1);
    vec.erase(vec.begin());
}

int main()
{
    vector<int> vec{9,9,9};
    add_one(vec);
    for(int i: vec)
        cout << i;
    return 0;
}
