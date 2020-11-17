#include <bits/stdc++.h>

using namespace std;

int maxprodsubarray(vector<int> &arr)
{
    int curr_prod = 1, max_so_far = 1;
    for(int i: arr) {
        curr_prod *= i;
        if(curr_prod == 0)
            curr_prod = 1;
        else if(max_so_far < curr_prod)
            max_so_far = curr_prod;
    }
    return max_so_far;
}

int main()
{
    vector<int> arr{-3, 8, -5, -5};
//    srand(time(NULL));
//    for(int i = 0; i < 10; ++i)
//        arr.push_back(rand() % 11 - 5);

    for(int i: arr)
        cout << i << " ";

    cout << "\n" << maxprodsubarray(arr);

    return 0;

}