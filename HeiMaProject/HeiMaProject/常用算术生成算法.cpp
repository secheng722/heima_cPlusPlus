#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
void testAccumulate() {
	vector<int>v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
	int total=accumulate(v.begin(), v.end(), 0);
	cout << "total= " << total << endl;
}
void testFill() {
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
}