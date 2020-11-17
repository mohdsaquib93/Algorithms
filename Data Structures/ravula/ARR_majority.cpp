#include <bits/stdc++.h>

using namespace std;

int find_majority(vector<int>& A)
{
    int maj = 0, count = 1;

    for (int i = 1; i < A.size(); ++i) {
        if (A.at(i) == A.at(maj))
            count++;
        else count--;

        if (!count) {
            maj = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A.at(maj) == A.at(i))
            count++;
        if (count > A.size() / 2)
            return A.at(maj);
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A.at(i);

    cout << "Majority element is: " << find_majority(A);
    return 0;
}