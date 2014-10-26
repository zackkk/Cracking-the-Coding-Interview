/* Write an algorithm which computes the number of trailing zeros in n factorial. */

// 5 * 2 = 10
// the number of 2 is always greater than the number of 0
// the number of trailing zeros depends on the number of factor 5
// special cases: 25 = 5*5, 125 = 25*5, ...

#include<iostream>
#include<cmath>
using namespace std;

class solution_19_3 {

public:
	int trailingZeros(int n){
		if(n < 0) return 0;

		int count = 0;
		int five_power = 5;
		
		while(five_power < n){
			count += n / five_power; // number of 5, 5*5, 5*25, 5*125
			five_power *= 5;
		}

		return count;
	}
};

int main(){
	solution_19_3 *obj = new solution_19_3();
	cout << obj->trailingZeros(25) << endl;
	return 0;
}
