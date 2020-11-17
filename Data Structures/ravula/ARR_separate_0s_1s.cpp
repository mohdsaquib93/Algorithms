#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, i = 0, j;
    cout << "Enter number of elements: ";
    cin >> num;
    vector<int> vec(num);
    j = num - 1;
    cout << "Enter elements: ";
    for(int i = 0; i < num; ++i)
        cin >> vec.at(i);

    while(true) {
        while(i < j && !vec.at(i))
            ++i;
        while(j > i && vec.at(j))
            j--;
        if(i < j)
            swap(vec.at(i), vec.at(j));
        else break;
    }

    cout << "Final array: ";
    for(int x: vec)
        cout << x << " ";
    cout << endl;
    return 0;
}
