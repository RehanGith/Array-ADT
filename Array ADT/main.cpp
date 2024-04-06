#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	Array a1(15);
	a1.add();
	a1.display();
	cout << endl;
	a1.count_sort();
	a1.display(); 
	return 0;
}