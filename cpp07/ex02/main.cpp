#include <iostream>
#include "Array.hpp"

int main(void) {
	Array<int> arr_empty;

	std::cout << "Array size: " << arr_empty.size() << std::endl;

	try {
		std::cout << "Arr empty: " << arr_empty[0] << std::endl;
	} catch (const Array<int>::IndexOutOfBoundsException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<int> arr(3);

	std::cout << "Array size: " << arr.size() << std::endl;

	arr[0] = -1;
	arr[2] = 9;

	for (int i = 0; i < 3; i++)
		std::cout << i << ": " << arr[i] << std::endl;

	std::cout << std::endl;

	try {
		arr[3] = 1;
	} catch (const Array<int>::IndexOutOfBoundsException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<int> arr_cpy(arr);
	Array<int> arr_cpy1(1);
	arr_cpy1 = arr;
	arr[0] = -2;
	std::cout << "Changed value in arr: " << arr[0] << std::endl;
	std::cout << "Unhanged value in arr_cpy: " << arr_cpy[0] << std::endl;
	std::cout << "Unchanged value in arr_cpy1: " << arr_cpy1[0] << std::endl;

	std::cout << std::endl;

	Array<std::string> strarr(3);
	Array<std::string> strarr_cpy(1);
	strarr[0] = "Hello";
	strarr[1] = "World!";
	strarr_cpy = strarr;

	std::cout << std::endl;

	strarr_cpy[0] = "Goodbye cruel";
	std::cout << strarr[0] << " " << strarr[1] << strarr[2] << std::endl;

	std::cout << std::endl;

	Array<Array<int> > objarr(2);
	objarr[0] = arr;
	objarr[1] = arr_cpy;
	for (int i = 0; i < 3; i++)
		std::cout << i << ": " << objarr[0][i] << std::endl;
}
