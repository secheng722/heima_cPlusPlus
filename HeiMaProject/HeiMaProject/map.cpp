#include<iostream>
#include<map>
using namespace std;
void printMap(const map<int, string>& map) {
	for (auto it = map.begin(); it != map.end(); it++) {
		cout << " id: " << it->first << " name: " << it->second << endl;
	}
}
void testMap() {
	map<int, string> m1;
	m1.insert(pair<int, string>(1, "ton"));
	m1.insert(pair<int, string>(2, "jack"));
	m1.insert(pair<int, string>(3, "bilin"));
	m1.insert(pair<int, string>(4, "hillsong"));
	m1.insert(pair<int, string>(5, "faker"));
	m1.insert(pair<int, string>(6, "xiaohu"));
	printMap(m1);
	auto m2(m1);
	printMap(m2);
	auto m3 = m1;
	printMap(m3);
}
