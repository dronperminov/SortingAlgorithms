#include <iostream>
#include <iomanip>

#include "BitonicSort.hpp"
#include "CountingSort.hpp"
#include "RadixSort.hpp"
#include "QuickSort.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "ShellSort.hpp"
#include "TreeSort.hpp"

#include "BubleSort.hpp"
#include "SelectionSort.hpp"
#include "ShakerSort.hpp"
#include "GnomeSort.hpp"
#include "InsertionSort.hpp"
#include "OddEvenSort.hpp"
#include "CombSort.hpp"
#include "PancakeSort.hpp"
#include "StoogeSort.hpp"
#include "CycleSort.hpp"

using namespace std;

const int DIRECT = 0;
const int REVERSE = 1;
const int RANDOM = 2;

// функция тестирования сортировки
bool test(void (*sort)(int*, int), int n, int type) {
	int *array = new int[n]; // выделяем память под массив

	if (type == DIRECT || type == REVERSE) {
		for (int i = 0; i < n; i++) {
			if (type == DIRECT) {
				array[i] = i + 1; // заполняем массив в прямом порядке
			}
			else {
				array[i] = n - i; // заполняем массив в обратном порядке
			}
		}
	}
	else {
		int *numbers = new int[n];

		for (int i = 0; i < n; i++)
			numbers[i] = i + 1;

		for (int i = 0; i < n; i++) {
			int index = rand() % n;

			while (numbers[index] == 0)
				index = (index + 1) % n;

			array[i] = numbers[index];
			numbers[index] = 0;
		}
	}

	sort(array, n); // сортируем массив

	// проверяем массив на отсортированность
	for (int i = 0; i < n; i++)
		if (array[i] != i + 1)
			return false;
	
	delete[] array;

	return true;
}

void test(void (*sort)(int*, int), const char* name) {
	int N[] = { 1, 2, 5, 10, 100, 1000, 10000, 25000 };
	int k = sizeof(N) / sizeof(N[0]);

	cout << "Test '" << name << "':" << endl;

	for (int i = 0; i < k; i++) {
		cout << "N = " << setw(6) << left << N[i] << ": ";
		cout << (test(sort, N[i], DIRECT) ? "OK" : "FAILED") << "    ";
		cout << (test(sort, N[i], REVERSE) ? "OK" : "FAILED") << "    ";
		cout << (test(sort, N[i], RANDOM) ? "OK" : "FAILED") << endl;
	}

	cout << endl;
}

int main() {
	test(BitonicSort, "Bitonic sort");
	test(CountingSort, "Counting sort");
	test(RadixSort, "Radix sort");
	test(QuickSort, "Quick sort");
	test(MergeSort, "Merge sort");
	test(HeapSort, "Heap sort");
	test(ShellSort, "Shell sort");
	test(ShellSortHibbard, "Shell sort (Hibbard)");
	test(ShellSortSedgewick, "Shell sort (Sedgewick)");
	test(TreeSort, "Tree sort");
	
	test(BubleSort, "Buble sort");
	test(BubleSortOpt, "Buble sort opt");
	test(SelectionSortMin, "Selection sort (min)");
	test(SelectionSortMax, "Selection sort (max)");
	test(ShakerSort, "Shaker sort");
	test(GnomeSort, "Gnome sort");
	test(InsertionSort, "Insertion sort");
	test(InsertionSortBinary, "Insertion sort (with binary search)");
	test(OddEvenSort, "Odd-even sort");
	test(CombSort, "Comb sort");
	test(PancakeSort, "Pancake sort");
	test(CycleSort, "Cycle sort");
	test(StoogeSort, "Stooge sort");
}