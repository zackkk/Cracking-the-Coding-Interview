#include<iostream>
using namespace std;

class solution_10_4 {

public:
	int multiplication(int a, int b){
		if(a == 0 || b == 0) return 0;

		int ret = 0;
		for(int i = 1; i <= abs(a); i++) ret += b;
		if(a < 0) ret = negative(ret);
		return ret;
	}

	int substraction(int a, int b){
		return a + negative(b);
	}

	int division(int a, int b){
		if(a == 0 || b == 0) return 0;
		
		int dividend = abs(a);
		int divisor = abs(b);
		int quotient = 1;
		while(divisor < dividend) { quotient++; divisor += abs(b); }
		if((a < 0 && b > 0) || (a > 0 && b < 0))
			quotient = negative(quotient);
		return quotient;
	}

	int negative(int a){
		int factor = a > 0 ? -1 : 1;
		int ret = 0;
		while(ret + a != 0){
			ret += factor;
		}
		return ret;
	}

};

int main(){
	solution_10_4 *obj = new solution_10_4();
	cout << obj->negative(10) << endl;
	cout << obj->negative(-10) << endl;
	cout << obj->substraction(10, 2) << endl;
	cout << obj->substraction(-10, - 2) << endl;
	cout << obj->multiplication(10, 2) << endl;
	cout << obj->multiplication(10, -2) << endl;
	cout << obj->division(10, 2) << endl;
	cout << obj->division(10, -2) << endl;
	return 0;
}
