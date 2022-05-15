#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class myCompare {
public:
	bool operator()(int& v1, int& v2) {
		return v1 > v2;
	}
};
void testTwoWeiCi() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	sort(v.begin(), v.end(),myCompare());
	for (auto i : v) {
		cout << i << endl;
	}
}