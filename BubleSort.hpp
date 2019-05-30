#pragma once

// Пузырьковая сортировка
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

void BubleSort(int *array, int n) {
	// делаем n проходов
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			// если соседние элементы стоят не в том порядке, то меняем их местами
			if (array[j + 1] < array[j]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

// оптимизированная пузырьковая сортировка
void BubleSortOpt(int *array, int n) {
	bool isSorted = false; // флаг отсортированности массива

	while (!isSorted) {
		isSorted = true; // считае, что массив уже отсортирован

		for (int i = 0; i < n - 1; i++) {
			// если соседние элементы стоят не в том порядке, то меняем их местами
			if (array[i + 1] < array[i]) {
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				isSorted = false; // опускаем флаг отсортированности
			}
		}
	}
}