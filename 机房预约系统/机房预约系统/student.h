#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include "computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include<algorithm>
#include"orderFile.h"
class Student :public Identity {
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string userName, string passWord);

	//菜单界面
	virtual void openMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void calcelOrder();


	//学生学号
	int m_Id;
	//机房容器
	vector<ComputerRoom>vCom;
};
