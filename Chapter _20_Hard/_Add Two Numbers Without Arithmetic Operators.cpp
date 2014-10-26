/* Write a function that adds two numbers. 
   You should not use + or any arithmetic operators. */

// bit 
// add all bits and use carry ? -> need a loop
// separate carry and addition

#include<iostream>
using namespace std;

class solution_20_1 {

public:
	int add(int a, int b){
		if(b == 0) return a;
		int sum = a ^ b;
		int carry = (a & b) << 1;
		return add(sum, carry);
	}
};

int main(){
	solution_20_1 *obj = new solution_20_1();
	cout << obj->add(10, 20) << endl;
	cout << obj->add(-10, -20) << endl;
	return 0;
}