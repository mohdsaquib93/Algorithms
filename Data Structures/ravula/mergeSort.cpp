#include <bits/stdc++.h>

using namespace std;

void merge_procedure(vector<int> &arr, int l, int mid, int r)
{
    int i;
    vector<int> arr1, arr2;
    arr1.assign(arr.begin() + l, arr.begin() + mid + 1);
    arr2.assign(arr.begin() + mid + 1, arr.begin() + r + 1);

    vector<int>::iterator itra1 = arr1.begin();
    vector<int>::iterator itra2 = arr2.begin();

    while((itra1 != arr1.end()) && (itra2 != arr2.end()))
        (*itra1 <= *itra2) ? arr.at(i++) = *itra1++ : (arr.at(i++) = *itra2++);

    while(itra2 != arr2.end())
            arr.at(i++) = *itra2++;

    while(itra1 != arr1.end())
            arr.at(i++) = *itra1++;

    cout << endl;
    arr1.clear();
    arr2.clear();
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge_procedure(arr, l, mid, r);
    }
}

int main()
{
    int num, i = -1;
    cout << "Enter no of elements: ";
    cin >> num;
    vector<int> arr(num);
    cout << "Enter elements: ";
    while(++i < num)
        cin >> arr.at(i);

    mergeSort(arr, 0, num - 1);
    for(int i: arr)
        cout << i << " ";

    return 0;
}
