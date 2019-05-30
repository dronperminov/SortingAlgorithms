#pragma once

// Цикличная сортировка
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

void CycleSort(int *array, int n) {
	for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
		int item = array[cycleStart];
		int pos = cycleStart;

		for (int i = cycleStart + 1; i < n; i++)
			if (array[i] < item)
				pos++;

		if (pos == cycleStart)
			continue;

		while (item == array[pos])
			pos++;

		int tmp = array[pos];
		array[pos] = item;
		item = tmp;

		while (pos != cycleStart) {
			pos = cycleStart;

			for (int i =  cycleStart + 1; i < n; i++)
				if (array[i] < item)
					pos++;

			while (item == array[pos])
				pos++;

			tmp = array[pos];
			array[pos] = item;
			item = tmp;
		}	
	}
}