#include<iostream>
#include<set>
#include<string>
using namespace std;
class myCompare{
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
class Person {
public:
	Person(const string name,const int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
class personCompare {
public :
	bool operator()(const Person& p1, const Person& p2) const {
		return p1.m_age < p2.m_age;
	}
};
void printSet(const set<int>& s1) {
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << endl;
	}
}
void testSet() {
	set<int> s1;
	s1.insert(60);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(70);
	printSet(s1);
	pair<set<int>::iterator, bool> ret = s1.insert(20);
	if (ret.second)
		cout << "插入成功" << endl;
	else
		cout << "插入失败" << endl;
	set<int, myCompare> s2;
	s2.insert(60);
	s2.insert(20);
	s2.insert(30);
	s2.insert(30);
	s2.insert(70);
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << endl;
	}
	set<Person,personCompare>s3;
	Person p1("张三", 19);
	Person p2("里斯", 22);
	Person p3("万物", 32);
	Person p4("关于", 42);
	Person p5("刘备", 26);
	Person p6("张思", 66);
	s3.insert(p1);
	s3.insert(p2);
	s3.insert(p3);
	s3.insert(p4);
	s3.insert(p5);
	s3.insert(p6);
	for (auto it = s3.begin(); it != s3.end(); it++) {
		cout << " 姓名："<<it->m_name << " 年龄：" << it->m_age << endl;
	}


}