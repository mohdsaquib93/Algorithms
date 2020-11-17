#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int partition(vector<int> &A, int l, int r)
{
	int i = l - 1, j = l;
	int pivot = A.at(r);

	while (j < r) {
		if (A.at(j) <= pivot)
			swap(A.at(++i), A.at(j));
		++j;
	}	

	swap(A.at(i + 1), A.at(r));
	return i + 1;
}

int randomizedPartition(vector<int> &A, int l, int r)
{
	srand(time(nullptr));
	int rnd = l + rand() % (r - l + 1);
	swap(A.at(rnd), A.at(r));
	return partition(A, l, r);
}

void randomizedQuickSort(vector<int> &A, int l, int r)
{
	if (l < r) {
		int p = randomizedPartition(A, l, r);
		randomizedQuickSort(A, l, p - 1);
		randomizedQuickSort(A, p + 1, r);
	}
}

void QuickSort(vector<int> &vec, int l, int r)
{
	stack<int> st;
	st.push(l);
	st.push(r);

	while (!st.empty()) {
		int r = st.top();
		st.pop();
		int l = st.top();
		st.pop();

		int pivot = partition(vec, l, r);

		if (pivot - 1 > l) {
			st.push(l);
			st.push(pivot - 1);
		}

		if (pivot + 1 < r) {
			st.push(pivot + 1);
			st.push(r);
		}
	}
}

int main()
{
	vector<int> vec = {9,6,5,0,8,2,3,1,4,7};
	QuickSort(vec, 0, vec.size() - 1);
	for (int i: vec)
		cout << i << " ";
	cout << endl;
	return 0;
}
