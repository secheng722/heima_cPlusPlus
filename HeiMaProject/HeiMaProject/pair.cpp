#include<iostream>
using namespace std;
void testPair() {
	pair<string, int>p("tom", 300);
	cout << " name: " << p.first << " age: " << p.second << endl;
	pair<string, int>p2 = make_pair("jack", 12);
	cout << " name: " << p2.first << " age: " << p2.second << endl;
}