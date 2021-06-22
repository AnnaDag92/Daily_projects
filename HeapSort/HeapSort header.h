#pragma once
#include <vector>

struct Tree {
    int data{ 0 };
    Tree* right{ NULL };
    Tree* left{ NULL };
};

class HeapTree {
private:
    Tree* root{ NULL };
    int heapsize{ 0 };
public:
    int Left(std::vector<int>&, int);
    int Right(std::vector<int>&, int);
    void MaxHeapify(std::vector<int>&, int);
    void BuildMaxHeap(std::vector<int>&);
    friend void HeapSort(std::vector<int>&, HeapTree&);
};
void print(std::vector<int>&);


