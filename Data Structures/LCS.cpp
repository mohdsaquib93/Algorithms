#include <iostream>
#include <vector>

using namespace std;

int LCS(string x, string y, int lenx, int leny)
{
	if (lenx == -1 || leny == -1)
		return 0;
	
	if (x.at(lenx) == y.at(leny))
		return (1 + LCS(x, y, lenx - 1, leny - 1));

	return max(LCS(x, y, lenx, leny - 1), LCS(x, y, lenx - 1, leny));
}	


int LCS_DP(vector<vector<int>> &vec, string x, string y, int lenx, int leny)
{
	int result;
	if (vec[lenx][leny] != -1)
		return vec[lenx][leny];
	
	if (lenx == 0 || leny == 0)
		result = 0;
	
	else if (x.at(lenx - 1) == y.at(leny - 1))
		result = (1 + LCS_DP(vec, x, y, lenx - 1, leny - 1));

	else
		result = max(LCS_DP(vec, x, y, lenx, leny - 1), LCS_DP(vec, x, y, lenx - 1, leny));
	
	vec[lenx][leny] = result;
	return result;
}	

int main()
{
	string x = "ab";
	string y = "cd";
	vector<vector<int>> vec(x.length() + 1);
	for (int i = 0; i <= x.length(); ++i)
		vec.at(i) = vector<int>(y.length() + 1);

	for (int i = 0; i <= x.length(); ++i)
		for (int j = 0; j <= y.length(); ++j)
			vec.at(i).at(j) = -1;

	LCS_DP(vec, x, y, x.length(), y.length());
	cout << vec[x.length()][y.length()] << endl;
	return 0;
}


