#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void print(int& val) {
	cout << val << " ";
}
class myPrint {
public:
	void operator()(int &val) {
		cout << val << " ";
	}
};
void testForEach() {
	vector<int>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print);
	cout << endl;
}
class TransForm {
public:
	int operator()(int& v) {
		return v;
	}
};
void testTransForm() {
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget;
	vTarget.resize(v.size());//需要重新设置空间
	transform(v.begin(), v.end(), vTarget.begin(),TransForm());
	for_each(vTarget.begin(), vTarget.end(), myPrint());


}