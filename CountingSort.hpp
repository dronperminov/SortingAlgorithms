#pragma once

// Сортировка подсчётом
// Временная сложность: O(n+k)
// Пространственная сложность: O(n+k)

void CountingSort(int *array, int n) {
	int minValue = array[0]; // минимальное значение
	int maxValue = array[0]; // максимальное значение

	// ищем минимальное и максимальное значения в массиве
	for (int i = 1; i < n; i++) {
		if (array[i] < minValue)
			minValue = array[i];

		if (array[i] > maxValue)
			maxValue = array[i];
	}

	int size = maxValue - minValue + 1; // считаем длину временного массива
	int *counts = new int[size]; // выделяем память под временный массив

	// обнуляем элементы массива
	for (int i = 0; i < size; i++)
		counts[i] = 0;

	// считаем количество каждого из элементов
	for (int i = 0; i < n; i++)
		counts[array[i] - minValue]++;

	// проходимся по временному массиву и восстанавливаем массив
	int index = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < counts[i]; j++) // записываем элемент столько раз, сколько он встречался
			array[index++] = i + minValue; // записываем значение в массив

	delete[] counts; // освобождаем динамическую память
}