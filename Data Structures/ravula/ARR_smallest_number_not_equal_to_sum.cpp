#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	int min = 1;
	cout << "Enter no of elements: ";
	cin >> num;
	vector<int> vec(num);

	cout << "Enter array elements: ";
	for(int i = 0; i < num; ++i)
		cin >> vec.at(i);

	sort(vec.begin(), vec.end());

	for(int i = 0; i < num; ++i) {
		if (vec.at(i) > min)
			break;
		min += vec.at(i);
	}

	cout << "Minimum number is: " << min << endl;
	return 0;
}
