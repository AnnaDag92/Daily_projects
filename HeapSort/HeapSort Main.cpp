#include <iostream>
#include "HeapSort header.h"

int main()
{
    HeapTree tree;
    std::vector<int> vec{ 5,8,1,3,-5, 15,-6,6,4,7,9,0 };
    HeapSort(vec, tree);
    print(vec);
}