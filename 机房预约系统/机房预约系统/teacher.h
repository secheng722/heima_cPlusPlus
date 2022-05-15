#pragma once
#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include<vector>
using namespace std;
class Teacher :public Identity {
public:
	//无参构造
	Teacher();
	//有参构造
	Teacher(int empId, string userName, string passWord);

	//显示菜单
	virtual void openMenu();
	//查看所有预约
	void showAllOrder();
	//审核所有预约
	void validOrder();

	//教师编号
	int m_empId;
};
