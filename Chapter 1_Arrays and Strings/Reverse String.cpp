#include<iostream>
using namespace std;
class solution_1_2{

public:
	void reverseString(char *str){
		char *ptr = str;
		while(*ptr){ // bug happened: while(ptr)...
			ptr++;
		}
		ptr--;
	
		while(str < ptr){
			char tmp = *str;
			*str = *ptr;
			*ptr = tmp;
			str++;
			ptr--;
		}
	}
};

int main(){
	solution_1_2 *obj = new solution_1_2();
	char str[12] = "hello world";
	obj->reverseString(str);
	cout << str << endl;
	return 0;
}