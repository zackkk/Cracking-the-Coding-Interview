#include<iostream>
#include<stack>
using namespace std;

class Tower{

private:
	stack<int> *disks;
	char index;

public:
	Tower(int i){
		index = i;
		disks = new stack<int>();
	}

	int removeFromTop(){
		int ret = disks->top();
		disks->pop();
		return ret;
	}

	void addToTop(int val){
		disks->push(val);
	}

	char getIndex(){
		return this->index;
	}

	int getSize(){
		return this->disks->size();
	}
};


class solution_3_4{

public:
	void moveOneDisk(Tower *ori, Tower *dest){
		int tmp = ori->removeFromTop();
		dest->addToTop(tmp);
		cout << "move " << tmp << " from Tower " << ori->getIndex() << " to Tower " << dest->getIndex() << endl;
	}

	void moveDisks(int n, Tower *ori, Tower *dest, Tower *buf){
		if(n <= 0) return;

		// move top n-1 disks to the buffer
		moveDisks(n-1, ori, buf, dest);

		// move one disk
		moveOneDisk(ori, dest);

		// move from buffer to dest
		moveDisks(n-1, buf, dest, ori);
	}
};

int main(){
	solution_3_4 *obj = new solution_3_4();
	Tower *ori = new Tower('A');
	Tower *buf = new Tower('B');
	Tower *dest = new Tower('C');
	int n = 4;
	for(int i = 1; i <= n; i++) ori->addToTop(i);
	obj->moveDisks(n, ori, dest, buf);

	cout << ori->getSize() << endl;
	cout << buf->getSize() << endl;
	cout << dest->getSize() << endl;
	return 0;
}