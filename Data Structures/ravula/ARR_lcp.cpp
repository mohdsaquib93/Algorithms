#include <bits/stdc++.h>

using namespace std;

string find_lcp(string s1, string s2)
{
    int len = s1.size() > s2.size() ? s2.size() : s1.size();
    string res;
    res.reserve(len);
    int i;
    for (i = 0; i < len; ++i)
        if (s1.at(i) != s2.at(i))
            break;

    if (i)
        return res.assign(s1.begin(), s1.begin() + i);

    return "";
}

int main()
{
    string s[] = {"apple", "ape", "april"};
    string res = s[0];
    int len = sizeof(s)/sizeof(s[0]);

    for (int i = 1; i < len; ++i)
        res = find_lcp(res, s[i]);

    cout << "LCP: " << res;
    return 0;
}
