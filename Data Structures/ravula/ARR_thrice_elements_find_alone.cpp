#include <bits/stdc++.h>

using namespace std;

long find_single(vector<int>& A)
{
    long sum = 0;
    long bin = 0;
    for (int i = sizeof(int) * 8 - 2; i >= 0; --i) {
        for (int j: A)
            sum += j >> i & 1;
        bin = 2 * bin + sum % 3;
        sum = 0;
    }
    return bin;
}

int main()
{
    vector<vector<int>> A {{1,2,3},{4,5,6}};

    auto it = search(A.begin(), A.end(), {1,2,3});
    return 0;
}

