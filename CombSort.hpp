#pragma once

// Сортировка расчёской
// Временная сложность: O(n^2 / 2^p), в лучшем случае O(n)
// Пространственная сложность: O(1)

void CombSort(int *array, int n) {
	int gap = n; // текущий шаг
	bool swapped = false; // флаг сравнений

	// пока шаг больше 1 или были сравнения
	while (gap > 1 || swapped) {
		if (gap > 1) // если шаг больше 1
			gap = gap / 1.247330950103979; // обновляем шаг

		swapped = false; // считаем, что обменов нет

		for (int i = 0; i < n - gap; i++) {
			if (array[i + gap] < array[i]) { // если элементы не в том порядке, то меняем их местами
				int tmp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = tmp;
				swapped = true; // поднимаем флаг обменов
			}
		}
	}
}