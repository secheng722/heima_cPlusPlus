#pragma once
#include<iostream>
using namespace std;
//身份抽象基类
class Identity {
public:
	//操作菜单
	virtual void openMenu()=0;

	//用户名
	string m_userName;
	//密码
	string m_passWord;
};
