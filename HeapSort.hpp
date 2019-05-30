#pragma once

// Пирамидальная сортировка
// Временная сложность: O(n log n)
// Пространственная сложность: O(1)

void DownHeap(int *array, int k, int n) {
	int maxN = k;
	int value = array[k];

	while (1) {
		int childN = 2 * k + 1;

		if (childN < n && array[childN] > value) 
			maxN = childN;

		childN++;

		if (childN < n && array[childN] > array[maxN])
            maxN = childN;

        if (maxN == k)
        	break;

        array[k] = array[maxN];
        array[maxN] = value; 
        k = maxN;
	}
}

void HeapSort(int* array, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		DownHeap(array, i, n);

	while (n > 1) {
		n--;

		int tmp = array[0];
		array[0] = array[n];
		array[n] = tmp;

		DownHeap(array, 0, n);
	}
}