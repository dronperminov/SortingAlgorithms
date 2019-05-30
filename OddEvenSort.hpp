#pragma once

// Чёт-нечёт сортировка
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

void OddEvenSort(int *array, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1 - i % 2; j < n - 1; j += 2) { // идём с шагом 2 по массиву, начиная то с нулевого, то с первого элемента
			if (array[j + 1] < array[j]) { // если элементы не в том порядке, то меняем их местами
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}