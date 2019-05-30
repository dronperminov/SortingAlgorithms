#pragma once

// Битонная сортировка
// Временная сложность: O(log^2 n)
// Пространственная сложность: O(n)

void BitSeqSort(int *array, int left, int right, bool inv) {
	if (right - left < 2)
		return;

	int mid = left + (right - left) / 2;
	int i = left;
	int j = mid;

	while (i < mid && j < right) {
		if (inv ^ (array[j] < array[i])) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}

		i++;
		j++;
	}

	BitSeqSort(array, left, mid, inv);
	BitSeqSort(array, mid, right, inv);
}

void MakeBitonic(int *array, int left, int right) {
	if (right - left < 2)
		return;

	int mid = left + (right - left) / 2;

	MakeBitonic(array, left, mid);
	BitSeqSort(array, left, mid, 0);
	MakeBitonic(array, mid, right);
	BitSeqSort(array, mid, right, 1);
}

void BitonicSort(int *array, int size) {
	int inf = array[0];

	for (int i = 1; i < size; i++)
		if (array[i] > inf)
			inf = array[i];

	inf++;

	int n = 1;

	while (n < size)
		n *= 2;

	int* tmp = new int[n];
	int cur = 0;

	for (int i = 0; i < size; i++)
		tmp[cur++] = array[i];

	while (cur < n)
		tmp[cur++] = inf;

	MakeBitonic(tmp, 0, n);
	BitSeqSort(tmp, 0, n, 0);

	cur = 0;

	for (int i = 0; i < size; i++)
		array[i] = tmp[cur++];

	delete tmp;
}