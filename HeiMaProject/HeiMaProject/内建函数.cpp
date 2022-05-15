#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
void testNegate() {
	negate<int> n;
	cout << n(50) << endl;
}
void testPlus() {
	plus<int>p;
	cout << p(10, 20) << endl;
}
void testGreater() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	for (auto i : v) {
		cout << i << endl;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (auto i : v) {
		cout << i << endl;
	}
}
void testLogical_not() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());
	for (auto i : v2) {
		cout << i << " ";
	}
}
