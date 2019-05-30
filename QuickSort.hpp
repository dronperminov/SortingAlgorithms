#pragma once

// Сортировка выбором
// Временная сложность: O(n log n), в худшем случае O(n^2)
// Пространственная сложность: O(n)

void QuickSort(int *array, int first, int last) {
	if (last <= first) // если интервал сортировки стал некорректным
		return; // то выходим

	int left = first; // запоминаем левую границу
	int right = last; // запоминаем правую границу
	int middle = array[(last + first) / 2]; // запоминаем центральный элемент

	// пока интервал не сомкнётся
	while (left <= right) {
		while (array[left] < middle)
			left++;

		while (middle < array[right])
			right--;

		if (left <= right) {
			int tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
		}
	}

	QuickSort(array, first, right);	// рекурсивно сортируем левую часть
	QuickSort(array, left, last); // рекурсивно сортируем правую часть
}

// Обёртка для вызова рекурсивной функции
void QuickSort(int *array, int n) {
	QuickSort(array, 0, n - 1);
}