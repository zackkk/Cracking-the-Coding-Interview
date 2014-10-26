/* Given an integer between 0 and 999,999, print an English phrase that describes the integer.
   eg, “One Thousand, Two Hundred and Thirty Four” */

// tedious

#include<map>
#include<string>
#include<iostream>
using namespace std;

class solution_19_6 {

private:
	// for 1, 2, ... 9, 10, 20, ... 90, and 11 - 19
	map<int, string> m;

public:
	solution_19_6(){
		m[1] = "one";
		m[2] = "two";
		m[3] = "three";
		m[4] = "four";
		m[5] = "five";
		m[6] = "six";
		m[7] = "seven";
		m[8] = "eight";
		m[9] = "nine";
		m[10] = "ten";
		m[20] = "twenty";
		m[30] = "thirty";
		m[40] = "forty";
		m[50] = "fifty";
		m[60] = "sixty";
		m[70] = "seventy";
		m[80] = "eighty";
		m[90] = "ninty";
		m[11] = "eleven";
		m[12] = "twelve";
		m[13] = "thirteen";
		m[14] = "fourteen";
		m[15] = "fifteen";
		m[16] = "sixteen";
		m[17] = "seventeen";
		m[18] = "eighteen";
		m[19] = "nineteen";
	}

	void describeAnInteger(int n){
		int left = n >= 1000 ? n / 1000 : 0; 
		int right = n % 1000;

		int left_hundred = left >= 100 ? left / 100 : 0;
		int right_hundred = right >= 100 ? right / 100 : 0;

		int left_ten = left >= 10 ? (left / 10) % 10 : 0;
		int right_ten = right >= 10 ? (right / 10) % 10 : 0;

		int left_one = left >= 0 ? left % 10 : 0;
		int right_one = right >= 0 ? right % 10 : 0;

		if(left > 0){
			if(left_hundred > 0)
				cout << m[left_hundred] << " hundred and ";

			if(left_ten == 1)
				cout << m[left_ten * 10 + left_one] << " thousand, ";
			else
				cout << m[left_ten * 10]  << " " << m[left_one] << " thousand, ";
		}
		if(right > 0){
			if(right_hundred > 0)
				cout << m[right_hundred] << " hundred and ";

			if(right_ten == 1)
				cout << m[right_ten * 10 + right_one] << endl;
			else
				cout << m[right_ten * 10]  << " " << m[right_one] << endl;
		}
	}
};

int main(){
	solution_19_6 *obj = new solution_19_6();
	obj->describeAnInteger(1234);
	return 0;
}