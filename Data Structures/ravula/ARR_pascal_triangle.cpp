#include <bits/stdc++.h>

using namespace std;

void createPascalTriangle(int n, int c)
{
    // Calculate n! / ((n - c)! * c!)
    int res = 1;
    if(c > n - c)
        c = n - c;
    for(int i = 0; i < c; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    cout << res << " ";
}

void printPascalTriangle2(int n)
{
    int p[n][n];
    p[0][0] = 1;
    for(int i = 2; i <= n; ++i) {
        p[i-1][0] = 1;
        for(int j = 1; j < i - 1; ++j)
            p[i-1][j] = p[i-2][j-1] + p[i-2][j];
        p[i-1][i-1] = 1;
    }

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << p[i][j] << " ";
        cout << "\n";
    }
}

void printPascalTriangle(int r)
{
    for(int n = 0; n < r; ++n) {
        for (int c = 0; c <= n; ++c)
            createPascalTriangle(n, c);
        cout << "\n";
    }
}

// Best so far
void printPascalTriangle3(int r)
{
    int res = 1;
    for(int n = 0; n < r; ++n) {
        cout << res;
        for(int k = 1; k <= n; ++k) {
            res = res * (n - k + 1) / k;
            cout << " " << res;
        }
        res = 1;
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter no of rows: ";
    cin >> n;
    printPascalTriangle3(n);
    return 0;
}
