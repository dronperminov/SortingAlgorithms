#pragma once

// Сортировка вставками
// Временная сложность: O(n^2), в лучшем случае O(n)
// Пространственная сложность: O(1)

void InsertionSort(int *array, int n) {
	for (int i = 1; i < n; i++) {
		int tmp = array[i]; // запоминаем текущий элемент
		int j = i;
		
		// сдвигаем элементы, для освобождения места под вставляемый элемент
		while (j > 0 && tmp < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}

		array[j] = tmp; // вставляем элемент в найденное место
	}
}

// сортировка вставками с бинарным поиском
void InsertionSortBinary(int *array, int n) {
	for (int i = 1; i < n; i++) {
		int left = 0;
		int right = i;
		int key = array[i];

		// повторяем, пока границы не сомкнутся
		while (left < right) {
			int mid = (left + right) / 2; // рассчитываем середину интервала

			// если искомый элемент больше центрального
			if (array[mid] < key) {
				left = mid + 1; // сдвигаем левую границу
			}
			else {
				right = mid; // сдвигаем правую границу
			}
		}

		int tmp = array[i]; // запоминаем элемент

		// сдвигаем элементы для вставляемого элемента
		for (int j = i - 1; j >= right; j--)
			array[j + 1] = array[j];
		
		array[right] = tmp; // вставляем элемент
	}
}
