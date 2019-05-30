#pragma once

// Блуждающая сортировка
// Временная сложность: O(n^log(1.5, 3))
// Пространственная сложность: O(1)

void StoogeSort(int *array, int left, int right) {
	if (array[right] < array[left]) {
		int tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
	}

	if (right - left < 2)
		return;

	int k = (right - left + 1) / 3;

	StoogeSort(array, left, right - k);
	StoogeSort(array, left + k, right);
	StoogeSort(array, left, right - k);
}

// обёртка для сортировки
void StoogeSort(int *array, int n) {
	StoogeSort(array, 0, n - 1);
}