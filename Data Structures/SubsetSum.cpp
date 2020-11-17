#include <iostream>
#include <vector>

using namespace std;

int subsetSum(vector<vector<int>> &table, vector<int> &vec, int i, int s)
{
	if (table[i][s] != -1)
		return table[i][s];
	
	int result;

	if (i == 0 && s != 0)
		result = 0;
	
	else if (s == 0)
		result = 1;
	
	else if (vec.at(i - 1) <= s)
		result = subsetSum(table, vec, i - 1, s - vec.at(i - 1)) || subsetSum(table, vec, i - 1, s);
	
	else 
		result = subsetSum(table, vec, i -1, s);
	
	table[i][s] = result;
	return result;
}

int main()
{
	vector<int> vec = {6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1,
						6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1,
						6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1,
						6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1,
						6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1,
						6, 3, 2, 1, 5, 7, 4, 6, 7, 3, 1, 1};
	int sum = 277;
	vector<vector<int>> table(vec.size() + 1);
	for (int i = 0; i <= vec.size(); ++i)
		table.at(i) = vector<int>(sum + 1);
	
	for (int i = 0; i <= vec.size(); ++i)
		for (int j = 0; j <= sum; ++j)
			table[i][j] = -1;

	subsetSum(table, vec, vec.size(), sum);
	cout << table[vec.size()][sum] << endl;
	return 0;
}
