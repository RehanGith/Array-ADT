#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	Array a1(15);
	a1.add();
	a1.display();
	a1.quick_sort(0, a1.length -1);
	cout << endl;
	a1.display(); 
	return 0;
}