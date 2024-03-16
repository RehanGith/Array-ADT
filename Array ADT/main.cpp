#include <iostream>
using namespace std;


class Array {
	int* arr;
	int size;
	int length;
public:
	Array(int n);

	void add();
	void display();
	void append(int n);
	void insert(int index, int x);
	~Array();
};
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
	if (length == size) {
		cout << "Array is full" << endl;
		return;
	}
	for (int i = length; i > index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[index] = x;
	length++;
}

Array::~Array() {
	delete[] arr;
}
int main() {
	Array a1(15);
	a1.add();
	a1.display();
	a1.append(29);
	a1.insert(4, 9);
	a1.display();

	return 0;
}