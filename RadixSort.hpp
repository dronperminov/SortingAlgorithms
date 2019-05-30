#pragma once

// Поразрядная сортировка
// Временная сложность: O(nk)
// Пространственная сложность: O(n+k)

void RadixSort(int *array, int n) {
	int base = 2; // основание системы счисления
	int *tmp = new int[n]; // временый массив
	int *bucket = new int[base];
	int significant_digit = 1; // текущее число
	int maxValue = array[0]; // максимальное число массива

	// ищем максимальное значение в массиве
	for (int i = 1; i < n; i++)
		if (array[i] > maxValue) 
			maxValue = array[i];

	while (maxValue / significant_digit > 0) {
		for (int i = 0; i < base; i++)
			bucket[i] = 0;

		for (int i = 0; i < n; i++) 
			bucket[(array[i] / significant_digit) % base]++;

		for (int i = 1; i < base; i++)
			bucket[i] += bucket[i - 1];

		for (int i = n - 1; i + 1 > 0; i--)
			tmp[--bucket[(array[i] / significant_digit) % base]] = array[i];

		for (int i = 0; i < n; i++) 
			array[i] = tmp[i];

		significant_digit *= base;
	}

	// освобождаем динамическую память
	delete[] tmp;
	delete[] bucket;
}