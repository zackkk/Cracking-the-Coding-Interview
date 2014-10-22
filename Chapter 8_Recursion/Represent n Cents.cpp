#include<iostream>
using namespace std;

class solution_8_7 {

public:
	// quarter, dime, nickel, penny
	int numberOfWaysToRepresentNCents(int n, int value){
		if(value == 1) return 1; // all pennies

		int next_value = 0;
		switch (value){
			case(25):
				next_value = 10;
				break;
			case(10):
				next_value = 5;
				break;
			case(5):
				next_value = 1;
				break;
			default:
				break;
		}

		int ways = 0;
		// use zero quarter, one quarter, two quarters, etc.
		for(int i = 0; i * value <= n; i++){
			ways += numberOfWaysToRepresentNCents(n - i*value, next_value);
		}
		return ways;
	}
};

int main(){
	solution_8_7 *obj = new solution_8_7();
	cout << obj->numberOfWaysToRepresentNCents(100, 25) << endl;
	return 0;
}