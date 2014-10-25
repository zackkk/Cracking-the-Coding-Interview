#include<iostream>
using namespace std;

class Shape {
public:
	virtual void show(){
		cout << "This is a Shape" << endl;
	}
};

class Circle : public Shape {
public:
	virtual void show(){
		cout << "This is a Circle" << endl;
	}
};

int main(){
	// both base and derived are "Shape" type pointers
	Shape *base = new Shape();
	base->show();
	Shape *derived = new Circle();
	derived->show();
	return 0;
}