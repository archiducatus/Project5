#include <iostream>
using namespace std;

class Test {
	int x;

public:
	Test(int x) : x(x) {}
	Test(const Test& t) : x(t.x) {}
	Test& operator++() {
		x++;
		cout << " 전위 증감 연산자 " << endl;
		return *this;
	}

	Test operator++(int) {
		Test temp(*this);
		x++;
		cout << " 후위 증감 연산자 " << endl;
		return temp;
	}

	int get_x() const { return x; }
};

void func(const Test& t) {
	cout << "x : " << t.get_x() << endl;
}

int main() {
	Test t(3);

	func(++t);
	func(t++);
	cout << "x : " << t.get_x() << endl;
}