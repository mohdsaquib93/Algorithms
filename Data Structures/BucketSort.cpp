#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<double> &vec)
{
    int j;
    for (int i = 1; i < vec.size(); ++i) {
        j = i - 1;
        double key = vec.at(i);
        while (j >= 0 && vec.at(j) > key) {
            vec.at(j + 1) = vec.at(j);
            j--;
        }

        vec.at(j + 1) = key;
    }
}

void bucketSort(vector<double> &vec)
{
	vector<vector<double>> bucket(vec.size());
	for (double &d: vec)
		bucket.at((int)(vec.size() * d)).push_back(d);
	
	for (vector<double> &vecd: bucket)
		insertionSort(vecd);
	
	for (int i = 0, k = 0; i < vec.size(); ++i) {
		if (!bucket.at(i).empty()) {
			int n = bucket.at(i).size();
			for (int j = 0; j < n; ++j)
				vec.at(k++) = bucket.at(i).at(j);
		}
	}
}


int main()
{
	vector<double> vec = {0.1, 0.23, 0.45, 0.79, 0.124, 0.792, 0.86, 0.97, 0.534};
	bucketSort(vec);

	for (double &d: vec)
		cout << d << " ";

	cout << endl;
	return 0;
}
