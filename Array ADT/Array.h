#pragma once
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
	void del(int index);
	int search(int x);
	int binary_search(int x);
	void rotation();
	void reverse();
	int max();
	void merge(int* p1, int* p2, int m, int n);
	bool is_sorted();
	void bubble_sort();
	void insertion_sort();
	void selection_sort();
	~Array();
};
