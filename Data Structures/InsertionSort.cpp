#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vec)
{
	int j;
	for (int i = 1; i < vec.size(); ++i) {
		j = i - 1;
		int key = vec.at(i);
		while (j >= 0 && vec.at(j) > key) {
			vec.at(j + 1) = vec.at(j);
			j--;
		}

		vec.at(j + 1) = key;
	}
}

int main()
{
	vector<int> vec = {9,6,5,0,8,1,7,3,2,4};
	insertionSort(vec);
	for (int i: vec)
		cout << i << " ";
	cout << endl;
	return 0;
}
