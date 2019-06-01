#pragma once

// Пирамидальная сортировка
// Временная сложность: O(n log n)
// Пространственная сложность: O(1)

void Heapify(int *array, int n, int i) {
	int largest = i;
	
	while (true) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && array[left] > array[largest])
			largest = left;

		if (right < n && array[right] > array[largest])
			largest = right;

		if (largest == i)
			return;

		int tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		i = largest;
	}
}

void HeapSort(int* array, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(array, n, i);

	for (int i = n - 1; i >= 0; i--) {
		int tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;

		Heapify(array, i, 0);
	}
}