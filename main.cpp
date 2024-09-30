#include <iostream>
#include "DynamicArr.h"

int main() {
	DynamicArr arr1, arr2(3);
	DynamicArr arr3(arr1);
	
	for (size_t i = 0; i < 3; ++i) {
		arr3.push_back(i);
	}

	arr1 = arr3;
	for (size_t i = 0; i < 3; ++i) {
		std::cout << arr1[i] << std::endl;
	}

	std::cout << std::endl;

	DynamicArr arr4;
	arr4 = arr3 = arr2;

	for (size_t i = 0; i < 3; ++i) {
		std::cout << arr4[i] << std::endl;
	}
	
	return 0;
}