#include<iostream>
using namespace std;

class solution_19_1 {

public:
	void swap(int &a, int &b){
		a = a + b;
		b = a - b;
		a = a - b;
	}

	void swap2(int &a, int &b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
};

int main(){
	solution_19_1 *obj = new solution_19_1();
	int a = 1;
	int b = 2;
	obj->swap(a, b);
	cout << a << " " << b << endl;
	obj->swap2(a, b);
	cout << a << " " << b << endl;
}