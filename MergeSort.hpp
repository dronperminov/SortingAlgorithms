#pragma once

// Сортировка слияниями
// Временная сложность: O(n log n)
// Пространственная сложность: O(n)

void MergeSort(int *array, int n) {
	if (n < 2) // если массив пуст или всего из одного элемента, то выходим
		return;

	int leftSize = n / 2; // получаем количество элементов в левом подмассиве
	int rightSize = n - leftSize; // получаем количество элементов в правом подмассиве

	int *left = new int[leftSize];
	int *right = new int[rightSize];

	// формируем левый массив
	for (int i = 0; i < leftSize; i++)
		left[i] = array[i];

	// формируем правый масив
	for (int i = 0; i < rightSize; i++)
		right[i] = array[i + leftSize];

	MergeSort(left, leftSize); // рекурсивно сортируем левый подмассив
	MergeSort(right, rightSize); // рекурсивно сортируем правый подмассив

	int i = 0;
	int j = 0;
	int k = 0;

	// пока есть элементы в обоих массивах
	while (i < leftSize && j < rightSize) {
		if (left[i] < right[j]) { // если элемент в левом массиве меньше
			array[k++] = left[i++]; // записываем его
		}
		else {
			array[k++] = right[j++]; // иначе записываем элемент из правого массива
		}
	}

	// дозаписываем левый массив
	while (i < leftSize)
		array[k++] = left[i++];

	// дозаписываем правый массив
	while (j < rightSize) 
		array[k++] = right[j++];

	// освобождаем память от массивов
	delete[] left;
	delete[] right;
}