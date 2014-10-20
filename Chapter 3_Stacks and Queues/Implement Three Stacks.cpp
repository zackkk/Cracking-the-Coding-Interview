#include<iostream>
using namespace std;

class solution_3_1{

// solution 1: each stack has equal & fixed size
// solution 2: linked list with dynamic size -> maintain a free list

private:
	int *arr;
	int *offset;// points to the top element
	int size;

public:
	solution_3_1(int size){
		arr = new int[size * 3];
		offset = new int[3];
		memset(arr, 0, sizeof arr);
		memset(offset, -1, sizeof offset);
		this->size = size;
	}
	~solution_3_1(){
		delete(arr);
	}

	void push(int val, int stackNum){
		if(offset[stackNum] + 1 < size){
			offset[stackNum]++;
			arr[stackNum * size + offset[stackNum]] = val;
		}
	}

	int top(int stackNum){
		return arr[stackNum * size + offset[stackNum]];
	}

	void pop(int stackNum){
		if(offset[stackNum] >= 0){
			offset[stackNum]--;
		}
	}
};


