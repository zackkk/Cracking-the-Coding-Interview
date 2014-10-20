#include<string.h>
#include<iostream>
using namespace std;

class solution_1_5{

public:

	// can we use string? then this question will be pointless
	char* replaceAllSpaces(char *str){
		int space_count = 0;
		for(int i = 0; i < strlen(str); ++i){
			if(str[i] == ' ') space_count++;
		}

		char *ret = str + strlen(str) + space_count * 2 - 1;
		char *ptr = str + strlen(str) - 1;
		while(ptr > str){
			if(*ptr != ' '){
				*ret-- = *ptr--;
			}
			else{
				*ret-- = '0';
				*ret-- = '2';
				*ret-- = '%';
				ptr--;
			}
		}
		return ret;
	}

	// first try: malloc
	// assume we have enough space left, do it in place
	// strlen doesn't include terminate char, diff from sizeof
};

int main(){
	solution_1_5 *obj = new solution_1_5();
	char str[40] = "hello ni hao";
	char *output = obj->replaceAllSpaces(str);
	cout << strlen(output) << endl;
	cout << output << endl;
}
