#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

LL fib(vector<LL> &vec, int n)
{
	LL result;
	if (vec[n] != -1)
		return vec[n];

	if (n == 0)
		result = 0;
	
	else if (n == 1)
		result = 1;
	
	else
		result = fib(vec, n - 1) + fib(vec, n - 2);
	
	vec[n] = result;
	return result;
}

int main(int argc, char **argv)
{
	int x = atoi(argv[1]);
	vector<LL> vec(x + 1, -1);
	fib(vec, x);
	cout << vec.at(x) << endl;
	return 0;
}
