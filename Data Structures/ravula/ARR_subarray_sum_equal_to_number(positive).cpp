#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num, target, sum = 0, flag = 0, start, end;
	cout << "Enter target number: ";
	cin >> target;
	cout << "Enter number of elements: ";
	cin >> num;
	vector<int> vec(num);

	cout << "Enter array elements: ";
	for(int i = 0; i < num; ++i)
		cin >> vec.at(i);

	for(int i = 0, j = 0; j < num;) {
		sum += vec.at(j);
		if(target > sum) {
			j++;
			continue;
		}

		if(target < sum) {
			sum -= vec.at(i++);
			sum -= vec.at(j);
			continue;
		}

		flag = 1;
		start = i;
		end = j;
		break;
	}

	if(!flag)
		cout << "No subarray possible" << endl;
	else {
		cout << "Subarray is: ";
		for(int i = start; i <= end; ++i)
			cout << vec.at(i) << " ";
		cout << endl;
	}
	return 0;
}


