#include <bits/stdc++.h>

using namespace std;

float my_pow(float x, int y)
{
    float res = 1;
    while (y) {
        if (y & 1)
            res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int main()
{
    float x;
    int y;
    cin >> x >> y;
    cout << my_pow(x,y);
    return 0;
}