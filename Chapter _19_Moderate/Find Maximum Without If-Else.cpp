/* Write a method which finds the maximum of two numbers. 
   You should not use if-else or any other comparison operator. */

// if a < b
// if a - b < 0
// let k be the sign of a - b
// k < 0 -> return a
// k > 0 -> return b
// return a - k * (a - b)

#include<iostream>
using namespace std;

class solution_19_4 {

public:
	int findMaximum(int a, int b){
		int c = a - b;
		int k = (c >> 31) & 1; // get the sign bit
		return a - k * (a - b);
	}
};

int main(){
	solution_19_4 *obj = new solution_19_4();
	cout << obj->findMaximum(-10, -5) << endl;
	cout << obj->findMaximum(10, 5) << endl;
	return 0;
}
