#include <iostream>
#include <vector>

void Merge(std::vector<int>& vec, int p, int q, int r) {
	int size1 = q - p + 1;
	int size2 = r - q;
	std::vector<int> L(size1);
	std::vector<int> R(size2);
	int x = p;
	for (int i = 0; i < L.size(); ++i) {
		L[i] = vec[x++];
	}
	for (int i = 0; i < R.size(); ++i) {
		R[i] = vec[x++];
	}
	int i = 0; 
	int j = 0;
	int k = p;
	for ( ; i < L.size() && j < R.size(); ++k) {
		if ( L[i] <= R[j]) {
			vec[k] = L[i++];
		}
		else {
			vec[k] = R[j++];
		}
	}
	while (i < L.size()) {
		vec[k] = L[i];
		++i;
		++k;
	}
	while (j < R.size()) {
		vec[k] = R[j];
		++j;
		++k;
	}
}

void MergeSort(std::vector<int>& vec, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(vec, p, q);
		MergeSort(vec, q + 1, r);
		Merge(vec, p, q, r);
	}
}
void Print(std::vector<int>& vec) {
	for (auto i : vec) {
		std::cout << i;
	}
}

int main()
{
	std::vector<int> vec {2,5,9,4,3,6,7,8};
	MergeSort(vec, 0, vec.size() - 1);
	Print(vec);
}