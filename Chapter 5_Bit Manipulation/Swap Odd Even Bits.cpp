#include<iostream>
using namespace std;

class solution_5_6 {

public:
	
	int swapOddAndEvenBits(int A){
		int maskEven = 0x55555555; // 0,2,4,...
		int maskOdd = 0xAAAAAAAA; // 1,3,5,...

		int evenBits = A & maskEven;	
		int oddBits = A & maskOdd;
			
		return (oddBits >> 1) + (evenBits << 1);
	}
};

int main(){
	solution_5_6 *obj = new solution_5_6();
	cout << obj->swapOddAndEvenBits(7) << endl;
	return 0;
}