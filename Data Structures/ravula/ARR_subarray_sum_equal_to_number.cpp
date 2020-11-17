#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num, target, i, start = 0, end, total = 0;
	cout << "Enter target number: ";
	cin >> target;
	cout << "Enter number of elements: ";
	cin >> num;
	vector<int> vec(num);
	unordered_map<int, int> sum;
	end = num - 1;

	cout << "Enter elements: ";
	for(i = 0; i < num; ++i)
		cin >> vec.at(i);

	for(i = 0; i < num; ++i) {
		total += vec.at(i);
		if(total == target) {
			end = i;
			break;
		}
		int val = total - target;
		if(sum.find(val) != sum.end()) {
			start = sum[val] + 1;
			end = i;
			break;
		}
		sum[total] = i;
		cout << sum.bucket_count() << " ";
	}

	if(i == num)
		cout << "No subarray possible" << endl;
	else {
		cout << "Subarray is: ";
		for(i = start; i <= end; ++i)
			cout << vec.at(i) << " ";
		cout << endl;
	}
	return 0;
}


