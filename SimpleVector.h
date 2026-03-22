
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <initializer_list>
#include <iostream>

template<typename T>
class SimpleVector {
private: 
	T* s_vector;
    int iSize = 3;
    int lastElement = 0;

public:
    SimpleVector() {
		//std::cout << "Simple Vector created.\n";
		s_vector = new T[iSize]{};
	}

	SimpleVector(std::initializer_list<T> elements) : SimpleVector<T>()
	{
		//std::cout << "Simple Vector with arguments created.\n";
		for (int element : elements) {
			//std::cout << element << std::endl;
			this->push_back(element);
			//lastElement++;
		}
	}

	~SimpleVector() {
		delete[] s_vector;
	}

	T* begin() {
		return s_vector;
	}

	T* end() {
		return s_vector + lastElement;
	}

	int push_back(T newElement) {

		if (lastElement == iSize) {
			iSize *= 2;
			T* newArr = new T[iSize] {};

			if (!newArr) {
				std::cerr << "Allocation failed\n";
				return -1;
			}

			for (int i = 0; i < lastElement; ++i)
			{
				newArr[i] = this->s_vector[i];
			}

			newArr[lastElement++] = newElement;

			delete[] s_vector;
			s_vector = newArr;

			return 0;
		}

		if (lastElement >= 0 && lastElement < iSize) {
			//std::cout << "push_back - add last element\n";
			this->s_vector[lastElement] = newElement;
			lastElement++;
		}

		return 0;
	}

	T pop_back() {
		if (lastElement > 0) {
			T value = this->s_vector[lastElement - 1];
			//this->s_vector[lastElement - 1] = 0;
			lastElement--;

			return value;
		}

		throw std::out_of_range("No element to pop.");
		//return -1;
	}

	T& at(int position) {
		/*if(position < 0 || position >= lastElement){
			std::cout << "No element on this position.\n";
			return nullptr;
		}*/

		return this->s_vector[position];
	}

	SimpleVector& operator=(const SimpleVector& s_vector) {
		return *this;
	}

	int size() {
		return lastElement - 1;
	}

	bool empty() {
		return lastElement == 0;
	}
};
#endif