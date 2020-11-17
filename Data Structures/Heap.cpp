#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &vec, int i, int j = 1)
{
	int l = (i << 1) + 1;
	int r = l + 1;
	int n = vec.size() - j;
	int largest = i;

	if (l <= n && vec.at(l) > vec.at(largest))
		largest = l;

	if (r <= n && vec.at(r) > vec.at(largest))
		largest = r;
	
	if (largest != i) {
		swap(vec.at(i), vec.at(largest));
		heapify(vec, largest, j);
	}
}

void buildHeap(vector<int> &vec)
{
	int i = vec.size() / 2 - 1;
	while (i >= 0) {
		heapify(vec, i);
		--i;
	}
}

int extractMax(vector<int> &vec, int i = 0)
{
	if (vec.size() < 1) {
		cout << "Heap Underflow\n";
		exit(1);
	}

	int max_el = vec.at(i);
	vec.at(i) = vec.at(vec.size() - 1);
	vec.pop_back();
	heapify(vec, i);
	return max_el;
}

void insert(vector<int> &vec, int item)
{
	vec.push_back(item);
	int child = vec.size() - 1;
	int parent = (child - 1) / 2;
	while (child != parent && vec.at(child) > vec.at(parent)) {
		swap(vec.at(child), vec.at(parent));
		child = parent;
		parent = (child - 1) / 2;
	}
}

void heapSort(vector<int> &vec)
{
	buildHeap(vec);

	int j = 1;
	while (j < vec.size()) {
		swap(vec.at(0), vec.at(vec.size() - j));
		++j;
		heapify(vec, 0, j);
	}
}

int main()
{
	vector<int> vec2 = {1, 14, 10, 8, 7, 9, 3, 2, 4, 6};
	vector<int> vec;

	buildHeap(vec2);
	//heapSort(vec2);
	for (int i: vec2)
		cout << i << " ";
	
	cout << endl;
	return 0;
}
