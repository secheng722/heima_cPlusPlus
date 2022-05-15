#include <iostream>
using namespace std;
class myAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
class myPrint {
public:
	myPrint() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		count += 1;
	}
	int count;
};

void testMyAdd() {
	myAdd myadd;
	cout << myadd(10, 20) << endl;
}
void doPrint(myPrint& mp, string test) {
	mp(test);
}
void testMyPrint() {
	myPrint myprint;
	myprint("---hello world---");
	myprint("---hello world---");
	myprint("---hello world---");
	myprint("---hello world---");
	myprint("---hello world---");
	cout << myprint.count << endl;
	
	doPrint(myprint, "cccccc");
}
