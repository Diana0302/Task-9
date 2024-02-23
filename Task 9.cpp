#include <iostream>

enum Sorting {
	BUBBLE_SORT, 
	SELECTION_SORT
};

struct SortingOption {
	Sorting val;
	void (*foo)(int*, int);
};

void BubbleSorting(int* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void SelectionSorting(int* arr, int size) {
	int min;
	for (int i = 0; i < size - 1; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] > arr[min]) {
				min = j;
			}
			std::swap(arr[j], arr[min]);
		}
	}
}

int main() 
{
	const int size = 2;
	SortingOption arr[size];
	int a;
	std::cout << "if you want to see bubble sorting algorithm choose 1, else 2" << std::endl;
	std::cin >> a;
	std::cout << "Array" << std::endl;
	for (int i = 0; i < size; ++i) {
		if (a == 1) {
			arr[i].foo = BubbleSorting;
		}
		else {
			arr[i].foo = SelectionSorting;
		}
	}
	const int lenght = 5;
	int arr1[lenght];
	std::cout << "Enter the array: ";
	for (int i = 0; i < lenght; i++) {
		std::cin >> arr1[i];
	}

	for (int j = 0; j < size; ++j) {
		std::cout << "Enter the " << j << "Sorting Algorithm" << std::endl;
		arr[j].foo(arr1, lenght);
		for (int i = 0; i < lenght; ++i) {
			std::cout << arr1[i] << std::endl;
		}
	}
}

