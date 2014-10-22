#include<iostream>
using namespace std;

class solution_5_3 {

public:
	// next largest: all 1's at left most
	int findNextLargest(int input){
		int ones = 0;
		for(int i = 0; i < 31; i++){ // exclude sign bit
			ones += ((input >> i) & 1);
		}
		int zeros = 31 - ones;
		
		return INT_MAX -  (1 << zeros - 1);
	}

	// next smallest
	// 011..1100..00 --> 1000..0011.11
	int findNextSmallest(int input){
		int i = 0;

		int zeros = 0;
		while(i < 31 && ((input >> i) & 1) == 0) { i++; zeros++; } // exclude sign bit
		if(i == 31) return -1;

		int ones = 0;
		while(i < 31 && ((input >> i) & 1) == 1) { i++; ones++; }
		if(i == 31) return -1;

		int leftMostOne = i;
		ones--;
		setBit(input, leftMostOne, 1);
		for(int i = 0; i < ones; i++) setBit(input, i, 1);
		// plus the leading 0 replaced by 1
		for(int i = ones; i < ones+zeros+1; i++) setBit(input, i, 0);	
		return input;
	}

	void setBit(int &input, int bit, int val){
		if(val == 1)
			input |= (1 << bit);
		else
			input &= ~(1 << bit);
	}

};

int main(){
	solution_5_3 *obj = new solution_5_3();
	int input = 25;
	cout << obj->findNextSmallest(input) << endl;
	cout << obj->findNextLargest(input) << endl;
	return 0;
}