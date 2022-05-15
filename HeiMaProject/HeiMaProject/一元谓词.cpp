#include<iostream>
#include <vector>
using namespace std;
class greateFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void testOneWeiCi() {
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it=find_if(v.begin(), v.end(), greateFive());
	if (it == v.end())
		cout << " " << endl;
	else
		cout << " " << *it << endl;
}
