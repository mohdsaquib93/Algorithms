#include "bits/stdc++.h"

using namespace std;

int rodCut(vector<int> &price, int n)
{
    vector<int> opt(n + 1);
    opt.at(0) = 0;
    for (int i = 1; i <= n; ++i) {
        int maxm = INT_MIN;
        for (int k = 1; k <= i; ++k)
            maxm = max(maxm, price.at(k - 1) + opt.at(i - k));
        opt.at(i) = maxm;
    }

    return opt.at(n);
}

int main()
{
    vector<int> price{3, 5, 8, 9, 10, 17, 17, 20};
    cout << rodCut(price, price.size());
    return 0;
}
