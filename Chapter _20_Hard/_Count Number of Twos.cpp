/* Write a method to count the number of 2s between 0 and n. */

// f(513) = 5 * f(99) + f(13) + 100  (200 ~ 299)
// f(279) = 2 * f(99) + f(79) + 90   (200 ~ 279)

#include<iostream>
using namespace std;

class solution_20_4 {

public:
	int numberOfTwos(int n){
		if(n == 0) return 0;

		int power = 1;
		while(power * 10 < n) power *= 10;

		int firstDigit = n / power;
		int remainder = n % power;

		int ret = 0;
		if(firstDigit > 2)
			ret += power;
		else if(firstDigit == 2)
			ret += (remainder + 1);

		// numberOfTwos(power - 1): f(99)
		ret += (firstDigit * numberOfTwos(power - 1) + numberOfTwos(remainder));

		return ret;
	}
};

int main(){
	solution_20_4 *obj = new solution_20_4();
	cout << obj->numberOfTwos(99) << endl;
	cout << obj->numberOfTwos(513) << endl;
	cout << obj->numberOfTwos(279) << endl;
	return 0;
}