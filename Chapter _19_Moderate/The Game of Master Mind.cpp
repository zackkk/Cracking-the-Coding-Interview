/*
	The Game of Master Mind is played as follows:
	The computer has four slots containing balls that are red (R), yellow (Y), green (G) or blue (B). 
	For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).
	You, the user, are trying to guess the solution. You might, for example, guess YRGB.

	When you guess the correct color for the correct slot, you get a “hit”. 
	If you guess a color that exists but is in the wrong slot, you get a “pseudo-hit”. 
	For example, the guess YRGB has 2 hits and one pseudo hit.
	For each guess, you are told the number of hits and pseudo-hits.

	Write a method that, given a guess and a solution, returns the number of hits and pseudo hits.
*/

// straight-forward

#include<string>
#include<map>
#include<iostream>
using namespace std;

class solution_19_5 {

private:
	string *computerSlots;

public:
	solution_19_5(string &str){
		computerSlots = new string(str);
	}

	~solution_19_5(){
		delete(computerSlots);
	}

	int getNumberOfHits(string &str){
		int count = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == (*computerSlots)[i])
				count++;
		}
		return count;
	}

	int getNumberOfPseudoHit(string &str){
		map<char, int> m;
		for(int i = 0; i < (*computerSlots).size(); i++)
			m[(*computerSlots)[i]]++;
		
		int count = 0;
		for(int i = 0; i < str.size(); i++)
			if((str[i] != (*computerSlots)[i]) && (m[str[i]] > 0))
				count++;
		return count;
	}
};

int main(){
	string s1 = "RGGB";
	solution_19_5 *obj = new solution_19_5(s1);
	string s2 = "YRGB";
	cout << obj->getNumberOfHits(s2) << endl;
	cout << obj->getNumberOfPseudoHit(s2) << endl;
	return 0;
}