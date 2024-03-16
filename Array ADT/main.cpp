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
	~Array();
};
Array::Array(int n) : size(n), length(0) {
	arr = new int[size];
}
void Array::add() {
	if (length - 1 == size) {
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
Array::~Array() {
	delete[] arr;
}
int main() {
	Array a1(15);
	a1.add();
	a1.display();
}