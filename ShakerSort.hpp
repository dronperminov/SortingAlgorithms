#pragma once

// Шейкерная сортировка
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

void ShakerSort(int *array, int n) {
	int left = 0; // левая граница массива
	int right = n - 1; // правая граница массива

	// повторяеМ, пока границы не сомкнутся
	while (left < right) {
		// проходим сортировкой вперёд
		for (int i = left; i < right; i++) {
			if (array[i + 1] < array[i]) { // если элементы не в том порядке, то меняем их местами
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}

		right--; // слвигаем правую границу

		// проходим сортировкой назад
		for (int i = right; i > left; i--) {
			if (array[i] < array[i - 1]) { // если элементы не в том порядке, то меняем их местами
				int tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
			}
		}

		left++; // сдвигаем левую границу
	}
}