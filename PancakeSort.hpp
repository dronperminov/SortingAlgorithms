#pragma once

// Блинная сортировка
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

void PancakeSort(int *array, int n) {
	for (int curr = n; curr > 1; curr--) {
		int imax = 0;

		// ищем индекс максимального элемента
		for (int i = 1; i < curr; i++)
			if (array[i] > array[imax])
				imax = i;

		// если он не равен текущему элементу, выполняем перевороты
		if (imax != curr - 1) {
			int up = imax;

			for (int i = 0; i < up; i++) {
				int tmp = array[i];
				array[i] = array[up];
				array[up] = tmp;
				up--;
			}

			up = curr - 1;

			for (int i = 0; i < up; i++) {
				int tmp = array[i];
				array[i] = array[up];
				array[up] = tmp;
				up--;
			}
		}
	}
}