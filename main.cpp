#include <iostream>
#include <algorithm>
#include "SimpleVector.h"

int main()
{
    SimpleVector<int> sVector2 = { 1, 2, 3, 4, 5, 5 };
    std::cout << "SimpleVector elements:\n";
    for (int* i = sVector2.begin(); i != sVector2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";

	int index = sVector2.size();
    std::cout << "SimpleVector elements - change element at index " << index << ":\n";
    sVector2.at(index) = -1;
    for (int* i = sVector2.begin(); i != sVector2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";

    std::cout << "SimpleVector elements - remova last element:\n";
    sVector2.pop_back();
    for (int* i = sVector2.begin(); i != sVector2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";
}

