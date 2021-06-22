#include <iostream>
#include "HeapSort header.h"

int HeapTree::Left(std::vector<int>& vec, int i) {
    return (2 * i + 1);
}
int HeapTree::Right(std::vector<int>& vec, int i) {
    return (2 * i + 2);
}
void HeapTree::MaxHeapify(std::vector<int>& vec, int i) {
    if (i < 0) return;
    int l = Left(vec, i);
    int r = Right(vec, i);
    int largest;
    if (l <= heapsize && vec[l] > vec[i])
        largest = l;
    else
        largest = i;
    if (r <= heapsize && vec[r] > vec[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(vec[largest], vec[i]);
    }
    MaxHeapify(vec, i - 1);
}
void HeapTree::BuildMaxHeap(std::vector<int>& vec) {
    heapsize = vec.size() - 1;
    for (int i = vec.size()/2 - 1; i > 0; --i) {
        MaxHeapify(vec, i);
    }
}
void HeapSort(std::vector<int>& vec, HeapTree& tree) {
    tree.heapsize = vec.size() - 1;
    tree.BuildMaxHeap(vec);
    for (int i = tree.heapsize; i >= 1; --i) {
        std::swap(vec[0], vec[i]);
        --tree.heapsize;
        tree.MaxHeapify(vec, vec.size()/2 - 1);
    }
}
void print(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
