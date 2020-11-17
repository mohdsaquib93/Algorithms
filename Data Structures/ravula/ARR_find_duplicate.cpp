#include <bits/stdc++.h>

using namespace std;

void findDuplicates(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); ++i) {
        vec.at(vec.at(i) % vec.size()) += vec.size();
        int num = vec.at(vec.at(i) % vec.size());
        if (num >= 2 * vec.size() && num < 3 * vec.size())
            cout << vec.at(i) % vec.size()  << " ";
    }

//    for(int i = 0; i < vec.size(); ++i)
//        if(vec.at(i) / vec.size() > 1)
//            cout << i << " ";
}

int main()
{
    vector<int> vec{8, 1, 6, 3, 8, 3, 6, 6, 2, 5, 1, 3, 6, 6, 8, 8};
    findDuplicates(vec);
    return 0;
}
