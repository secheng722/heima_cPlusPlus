#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
void testSort() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), [](int& v1, int& v2) {
		return v1 > v2;
		});
	for_each(v.begin(), v.end(), [](int& val) {
		cout << val << endl;
		});
}
void testRandom_shuffle() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int& val) {
		cout << val << endl;
		});
}

void testMerge() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), [](int& val) {
		cout << val << " ";
		});
}
void testReverse() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int& val) {
		cout << val << " ";
		});
}
