#include <iostream>
#include <vector>

using namespace std;

void subArraySum(vector<int> &vec, int sum)
{
	int i = 0, j = 1;
	int curr_sum = vec.at(0);
	while (j < vec.size() &
			j++;
		}

		if (curr_sum == sum) {
			cout << "Subarray found between " << i << " and " << j - 1 << endl;
			return;
		}
		curr_sum -= vec.at(i);
		i++;
	}

}

int main()
{
	vector<int> vec = {1,4,5,3,2,6,7};
	int sum = 31;
	subArraySum(vec, sum);
	return 0;
}
