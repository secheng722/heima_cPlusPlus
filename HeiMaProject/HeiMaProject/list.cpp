#include<list>
#include <iostream>
using namespace std;
class Person {
public :
	Person(string name, int age,int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
bool comparePerson(Person& p1, Person& p2) {
	if (p1.m_age == p2.m_age) {
		return p1.m_height < p2.m_height;
	}
	else {
		return p1.m_age < p2.m_age;
	}
}
void testList() {
	list<Person> L;
	Person p1("张三", 19,166);
	Person p2("里斯", 22,178);
	Person p3("万物", 22,189);
	Person p4("关于", 22,160);
	Person p5("刘备", 26,144);
	Person p6("张思", 66,199);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << " 姓名： " << it->m_name << " 年龄：" << it->m_age <<" 身高： "<<it->m_height<< endl;
	}
	L.sort(comparePerson);
	cout << "========================= " << endl;
	cout << "排序后" << endl;
	
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << " 姓名： " << it->m_name << " 年龄：" << it->m_age <<" 身高： "<<it->m_height<< endl;
	}


}
