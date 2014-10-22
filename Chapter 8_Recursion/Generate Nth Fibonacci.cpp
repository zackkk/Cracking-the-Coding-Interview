#include<iostream>
using namespace std;

class solution_8_1 {

public:
	// 0,1,1,2,3,5,8,13,21,34,55,...
	int generateNthFibonacci(int n){
		if(n <= 2) return n-1;
		int a = 0;
		int b = 1;
		for(int i = 3; i <= n; i++){
			int tmp = b;
			b = a + b;
			a = tmp;
			cout << i << " " << b << endl;
		}
		return b;
	}
};

int main(){
	solution_8_1 *obj = new solution_8_1();
	cout << obj->generateNthFibonacci(10) << endl;
	return 0;
}