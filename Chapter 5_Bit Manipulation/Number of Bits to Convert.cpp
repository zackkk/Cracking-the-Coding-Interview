#include<iostream>
using namespace std;

class solution_5_5 {

public:

	// check how many bits are different
	int numberOfBitsToConvert(int A, int B){
		int count = 0;
		for(int i = 0; i < 32; i++){
			if(((A >> i) & 1) ^ ((B >> i) & 1 ) == 1) count++;
		}
		return count;
	}

	// solution from the book
	int numberOfBitsToConvert2(int A, int B){
		int count = 0;
		for(int c = A ^ B; c != 0; c = c >> 1){
			count += c & 1;
		}
		return count;
	}

};

int main(){
	solution_5_5 *obj = new solution_5_5();
	cout << obj->numberOfBitsToConvert(31, 14) << endl;
	return 0;
}