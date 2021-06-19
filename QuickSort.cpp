#include <iostream>
#include <vector>

int  Partition(std::vector<int>& vec, int p, int r) {
	int pivot = r;
	int i = p;
	int j = r - 1;
	while (i <= j) {
		if (vec[j] > vec[pivot]) {
			std::swap(vec[j], vec[i]);
			++i;
		}
		else {
			--j;
		}
	}
	std::swap(vec[i], vec[pivot]);
	return i;
}
void QuickSort(std::vector<int>& vec, int p, int r) {
	if (p < r) {
		int q = Partition(vec, p, r);
		QuickSort(vec, p, q - 1);
		QuickSort(vec, q + 1, r);
	}
}
void Print(std::vector<int>& vec) {
	for (auto i : vec) {
		std::cout << i;
	}
}

int main()
{
	std::vector<int> vec {2,5,9,4,3,8,0,-4,6,8};
	QuickSort(vec, 0, vec.size() - 1);
	Print(vec);
}