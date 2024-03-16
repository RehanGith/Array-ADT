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

Array::~Array() {
	delete[] arr;
}
int main() {
	
}