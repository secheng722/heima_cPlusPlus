#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void testCopy() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
}
void testReplace() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	replace(v1.begin(), v1.end(), 5, 200);
	for_each(v1.begin(), v1.end(), [](int& val) {
		cout << val << endl;
		});
}
void testReplace_if() {
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	replace_if(v1.begin(), v1.end(), [](int& val) {
		return val > 4;
		}, 200);
	for_each(v1.begin(), v1.end(), [](int& val) {
		cout << val << endl;
		});

}
