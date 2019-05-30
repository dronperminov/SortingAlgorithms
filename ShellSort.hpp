#pragma once

// Сортировка выбором
// Временная сложность: O(n log n)
// Пространственная сложность: O(1)

void ShellSort(int *array, int n) {
	// начинаем с расстояния в половину длины массива, а затем уменьешаем его в два раза
	for (int k = n / 2; k > 0; k /= 2) {
		for (int i = k; i < n; i++) {
			int tmp = array[i]; // запоминаем текущий элемент
			int j = i;

			// ищем место для вставки
			while (j >= k && tmp < array[j - k]) {
				array[j] = array[j - k];
				j -= k;
			}

			array[j] = tmp; // вставляем элемент в найденное место
		}
	}
}

// сортировка Шелла с последовательностью Хиббарда
void ShellSortHibbard(int *array, int n) {
	for (int k = 1; k < n; k = k * 2 + 1) {
		for (int i = k; i < n; i++) {
			int tmp = array[i];
			int j = i;

			// ищем место для вставки
			while (j >= k && tmp < array[j - k]) {
				array[j] = array[j - k];
				j -= k;
			}

			array[j] = tmp; // вставляем элемент в найденное место
		}
	}
}

// сортировка Шелла с последовательностью Сейджвика
void ShellSortSedgewick(int *array, int n) {
	int iteration = 1;
	int k = 1;

	while (k < n) {
		for (int i = k; i < n; i++) {
			int tmp = array[i];
			int j = i;

			// ищем место для вставки
			while (j >= k && tmp < array[j - k]) {
				array[j] = array[j - k];
				j -= k;
			}

			array[j] = tmp; // вставляем элемент в найденное место
		}

		iteration++;

		if (iteration % 2 == 0) {
			k = 9 * (1 << iteration) - 9 * (1 << (iteration / 2)) + 1;
		}
		else {
			k = 8 * (1 << iteration) - 6 * (1 << ((iteration + 1) / 2)) + 1;
		}
	}
}