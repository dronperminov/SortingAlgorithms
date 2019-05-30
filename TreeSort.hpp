#pragma once

// Сортировка деревом
// Временная сложность: O(n log n)
// Пространственная сложность: O(n)

// элемент дерева
struct Node {
	int value; // значение элемента
	Node *left; // укащатель на левое поддерево
	Node *right; // указатель на правое поддерево
};

// вставка в дерево
Node* Insert(Node *node, int value) {
	if (node == NULL) {
		node = new Node; // выделяем память под элемент

		node->value = value; // сохраняем значение
		node->left = NULL; // слева нет поддерева
		node->right = NULL; // справа нет поддерева
	}
	else if (value < node->value) { // если элемент меньше корня
		node->left = Insert(node->left, value); // вставляем в левое поддерево
	}
	else {
		node->right = Insert(node->right, value); // иначе вставляем в правое поддерево
	}

	return node; // возвращаем элемент
}

// обход дерева в прямом порядке с записью в массив
void InOrder(Node *node, int *array, int &index) {
	if (node == NULL)
		return;

	InOrder(node->left, array, index); // обходим левое поддерево
	array[index++] = node->value; // записываем элемент
	InOrder(node->right, array, index); // обходим правое поддерево

	delete node; // освобождаем память от элемента
}

void TreeSort(int *array, int n) {
	Node *root = NULL;

	// формируем дерево
	for (int i = 0; i < n; i++)
		root = Insert(root, array[i]);

	int index = 0;
	InOrder(root, array, index); // записываем в массив сформированное дерево
}