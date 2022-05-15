#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include "student.h"
#include<vector>
#include "teacher.h"
#include<algorithm>
#include "computerRoom.h"
class Manager :public Identity {
public:
	Manager();

	Manager(string userName,string passWord);

	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约信息
	void cleanFile();
	//初始化容器
	void initVector();
	//检测重复
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student>vStu;
	//教师容器
	vector<Teacher>vTea;
	//机房容器
	vector<ComputerRoom>vCom;

};
