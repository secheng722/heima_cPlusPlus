#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	bool operator==(const Person& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) 
			return true;
		return false;
	}
	string m_name;
	int m_age;
};
void testFind() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it=find(v.begin(), v.end(), 6);
	if (it != v.end())
		cout << "找到了" << endl;
	else 
		cout << "没找到" << endl;
	vector<Person>vPerson;
	string nameSeed = "ABCDEF";
	for (auto c : nameSeed) {
		Person p(""+c, (int)rand() % 100);
		vPerson.push_back(p);
	}
	auto itp = find(vPerson.begin(), vPerson.end(), Person("" + 'D', 10));
	if (itp != vPerson.end())
		cout << "找到了" << endl;
	else 
		cout << "没找到" << endl;
}
//相邻重复元素
void testAdjacent_find() {
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	vector<int>::iterator it=adjacent_find(v.begin(), v.end());
	if (it != v.end()) 
		cout << "找到了" << *it << endl;
	else
		cout << "没找到" << endl;
}
//二分查找
void testBinary_search() {
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	bool ret=binary_search(v.begin(),v.end(),58888);
	if (ret)
		cout << "find it" << endl;
	else
		cout << "can not find it" << endl;
}
void testCount() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int res=count(v.begin(), v.end(), 9);
	cout << "9的个数为：" << res << endl;
}
void testCount_if() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int num = count_if(v.begin(), v.end(), [](int& val) {
		return val > 5; });
	cout << num << endl;
	

}
