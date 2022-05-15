#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void testSet_intersection() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>res;
	res.resize(min(v1.size(), v2.size()));
	auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
	for_each(res.begin(), itEnd, [](int& v) {
		cout << v << " ";
		});

}
void testSet_union() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>res;
	res.resize(v1.size()+v2.size());
	auto itEnd=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
	for_each(res.begin(),itEnd, [](int& v) {
		cout << v << " ";
		});
}
void testSet_difference() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>res;
	res.resize(max(v1.size(),v2.size()));
	auto itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
	for_each(res.begin(),itEnd, [](int& v) {
		cout << v << " ";
		});
	cout << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), res.begin());
	for_each(res.begin(),itEnd, [](int& v) {
		cout << v << " ";
		});

	
}