#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int l, int mid, int r)
{
	vector<int> lmid(mid - l + 1);
	vector<int> midr(r - mid);

	lmid.assign(vec.begin() + l, vec.begin() + mid + 1);
	midr.assign(vec.begin() + mid + 1, vec.begin() + r + 1);

	int k = l;
	vector<int>::iterator itr_l = lmid.begin();
	vector<int>::iterator itr_r = midr.begin();
	
	while( itr_l != lmid.end() && itr_r != midr.end()) {
		if (*itr_l < *itr_r)
			vec.at(k++) = *itr_l++;
		else
			vec.at(k++) = *itr_r++;
	}

	while (itr_l != lmid.end())
		vec.at(k++) = *itr_l++;
	
	while (itr_r != midr.end())
		vec.at(k++) = *itr_r++;
	
	vector<int>().swap(lmid);
	vector<int>().swap(midr);
}

void mergeSort(vector<int> &vec, int l, int r)
{
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(vec, l, mid);
		mergeSort(vec, mid + 1, r);
		merge(vec, l, mid, r);
	}
}

void mergeSortIter(vector<int> &vec)
{
	int size = vec.size();
	for (int mergeSize = 1; mergeSize < size; mergeSize *= 2) {
		for (int l = 0; l < size - 1; l += 2 * mergeSize) {
			int mid = min(l + mergeSize - 1, size - 1);
			int r = min(l + 2 * mergeSize - 1, size - 1);
			merge(vec, l, mid, r);
		}
	}
}

int main()
{
    vector<int> vec = {9,6,5,0,8,1,7,3,2,4};
    mergeSortIter(vec);
    for (int i: vec)
        cout << i << " ";
    cout << endl;
    return 0;
}

