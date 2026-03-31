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
		std::cout << "default constructor\n";
		//std::cout << "Simple Vector created.\n";
		s_vector = new T[iSize]{};
	}

	SimpleVector(std::initializer_list<T> elements) : SimpleVector<T>()
	{
		std::cout << "constructor\n";
		//std::cout << "Simple Vector with arguments created.\n";
		for (int element : elements) {
			//std::cout << element << std::endl;
			this->push_back(element);
			//lastElement++;
		}
	}

	~SimpleVector() {
		std::cout << "destructor\n";
		delete[] s_vector;
	}

	// Итерация
	//  begin(), end()
	//  rbegin(), rend()

	T* begin() {
		return s_vector;
	}

	T* end() {
		return s_vector + lastElement;
	}

	T* rbegin() {
		return s_vector + lastElement;
	}

	T* rend() {
		return s_vector;
	}

	// Основни операции
	//  push_back() – добавя елемент в края
	//  pop_back() – премахва последния елемент
	//  insert() – вмъква елемент на дадена позиция
	//  erase() – изтрива елемент
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


	// what is better:
	// to use this->s_vector or to use begin() and end() iterators?
	T* insert(int pos, T value) {
		if (pos < 0 || pos > lastElement) {
			std::cout << "Invalid range.\n";
			return this->s_vector;
		}

		if (lastElement == iSize) {
			iSize *= 2;
			T* newArr = new T[iSize] {};
			std::move(begin(), begin() + lastElement, newArr);
			lastElement++;
			s_vector = newArr;
		}

		std::copy_backward(begin() + pos, begin() + lastElement, begin() + lastElement + 1);
		this->s_vector[pos] = value;
		lastElement++;

		return this->s_vector;
	}

	T* erase(int pos) {
		if (pos < 0 || pos > lastElement) {
			std::cout << "Invalid range.\n";
			return this->s_vector;
		}

		for (T* it = this->s_vector + pos; it != this->s_vector + lastElement - 1; ++it) {
			*it = *(it + 1);
		}

		lastElement--;

		return this->s_vector;
	}

	T* erase(int start, int end) {
		if (start < 0 || end > lastElement || start >= end) {
			std::cout << "Invalid range.\n";
			return this->s_vector;
		}

		for (T* it = this->s_vector + start; it != this->s_vector + end - 1; ++it) {
			*it = *(it + 1);
		}
		return this.s_vector;
	}

	// Достъп до елементи
	//  operator[] – достъп без проверка
	//  at() – достъп с проверка
	//  front() – първи елемент
	//  back() – последен елемент
	//  data() – pointer към първия елемент
	SimpleVector& operator=(const SimpleVector& s_vector) {
		return *this;
	}

	T& at(int position) {
		if (position < 0 || position >= lastElement) {
			throw std::out_of_range("No element on this position.");
		}

		return this->s_vector[position];
	}

	T& front() {
		return at(0);
	}

	T& back() {
		return at(lastElement - 1);
	}

	T* data() {
		return begin();
	}

	// Размер и капацитет
	//  size() – брой елементи
	//  capacity() – заделена памет
	//  resize() – променя броя елементи
	//  reserve() – заделя памет предварително
	//  empty() – дали е празен
	int size() {
		return lastElement;
	}

	bool empty() {
		return lastElement == 0;
	}

	int capacity() {
		return iSize;
	}

	void resize(int size) {
		if(size < 0) {
			std::cout << "Invalid size.\n";
			return;
		}	

		T* newArr = new T[size]{};
		newArr = std::move(begin(), begin() + lastElement, newArr);
		s_vector = newArr;
	}

	void resize(int size, T value) {
		if (size < 0) {
			std::cout << "Invalid size.\n";
			return;
		}

		iSize = size;
		T* newArr = new T[iSize]{};
		std::move(begin(), end(), newArr);
		for (T* it = newArr + lastElement - 1; it != newArr + size; ++it) {
			*it = value;			
		}
		lastElement = size;

		delete[] s_vector;
		s_vector = newArr;
	}

	void reserve(int size) {
		iSize = size;
	}

	// Модификация
	//  clear() – изтрива всички елементи
	//  assign() – заменя съдържанието
	//  swap() – разменя съдържание с друг vector

};
#endif