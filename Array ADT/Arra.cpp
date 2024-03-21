#include "Array.h"
#include <iostream>
using namespace std;

Array::Array(int n) : size(n), length(0) {
	arr = new int[size];
}
void Array::add() {
	if (length == size) {
		cout << "Array is full" << endl;
		return;
	}
	while (true) {
		cout << "How many number you wants to add: ";
		cin >> length;
		if (length <= size) {
			break;
		}
		cout << "Please provide length within the bound" << endl;
	}
	cout << "Enter data: ";
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

}

void Array::display() {
	cout << "Data: ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}
void Array::append(int x) {
	if (length == size) {
		cout << "Array is full" << endl;
		return;
	}
	arr[length] = x;
	length++;
}
void Array::insert(int index, int x) {
	if (index < 0 && length == size) {
		cout << "invalid index" << endl;
		return;
	}
	for (int i = length; i > index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = x;
	length++;
}
void Array::del(int index) {
	if (index < 0 && index >= length) {
		cout << "Invalid index" << endl;
		return;
	}
	for (int i = index; i < length - 1; i++) {
		arr[i] = arr[i + 1];
	}
	length--;
}
int Array::search(int x) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == x)
			return i;
	}
	return -1;
}
int Array::binary_search(int x) {
	int low = 0, high = length - 1, mid = 0;
	while (true) {
		mid = int((low + high) / 2);
		if (x == arr[mid])
			return mid;
		else if (x > arr[mid])
			low = mid + 1;
		else
			high = high - 1;
		if (low > high)
			return -1;
	}
}
void Array::reverse() {
	int temp{};
	for (int i = 0, j = length - 1; i <= j; i++, j--) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j]= temp;
	}
}
void Array::rotation() {
	int temp{};
	temp = arr[0];
	for (int i = 0; i < length - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[length - 1] = temp;
}
int Array::max() {
	int temp{};
	temp = arr[0];
	for (int i = 0; i < length; i++) {
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}
bool Array::is_sorted() {
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
void Array::merge(int* p1, int* p2, int m, int n) {
	length = m + n;
	if (length == size) {
		cout << "size is larger" << endl;
		return;
	}
	int i = 0, j = 0, k = 0;
	while (j < m && k < n) {
		if (p1[j] <= p2[k])
			arr[i++] = p1[j++];
		else
			arr[i++] = p2[k++];
	}
	for (; k < n; k++)
		arr[i++] = p2[k];
	for (; j < m; j++)
		arr[i++] = p1[j];
}
void Array::bubble_sort() {
	int count{ 0 };
	for (int j = length - 1; j > 0; j--) {
		count = 0;
		for (int i = 0; i < j; i++) {
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
			else
				count++;
		}
		if (count == j)
			break;
	}
}
void Array::insertion_sort() {
	int key;
	for (int i = 0; i < length - 1; i++) {
		key = arr[i + 1];
		int j = i;
		while (j >= 0 and arr[j] > key) {
			swap(arr[j], arr[j + 1]);
			j--;
		}
		arr[j + 1] = key;
	}
}
void Array::selection_sort() {
	int min_index;
	int c{};
	for (int i = 0; i < length - 1; i++) {
		min_index = i;
		c = -1;
		for (int j = i + 1; j < length; j++) {
			if (arr[min_index] > arr[j])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);
	}
}
void Array::quick_sort(int i,int j) {
	int pivot = i, size = j;
	i++;
	if (i > j or j == 0)
		return;
	while (i <= j) {
		if (arr[i] > arr[pivot] && arr[j] <= arr[pivot])
			swap(arr[i], arr[j]);
		else if (arr[i] <= arr[pivot])
			i++;
		else if (arr[j] > arr[pivot])
			j-- ;
	}
	swap(arr[j], arr[pivot]);
	quick_sort(0, j - 1);
	quick_sort(j + 1, size);
	
}
Array::~Array() {
	delete[] arr;
}