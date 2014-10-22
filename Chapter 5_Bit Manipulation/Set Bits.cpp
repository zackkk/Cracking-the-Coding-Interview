#include<iostream>
using namespace std;

class solution_5_1{

public:
	// set all bits between i and j in N equal to M
	// M: 1000 0000 000
	// N: 10101
	int setBits(int N, int M, int i, int j){

		unsigned mask = ~0; // 1111 1111 111

		//mask -= (1 << (j+1)) - 1; // 1111 0000 000
		mask = (mask << (j+1));
		mask |= (1 << i) - 1; // 1111 0000 011

		//clear up bits in M between i and j
		M &= mask;

		// set up bits
		M |= (N << i);

		return M;
	}
};

int main(){
	solution_5_1 *obj = new solution_5_1();
	cout << obj->setBits(21, 1024, 2, 6) << endl;
}