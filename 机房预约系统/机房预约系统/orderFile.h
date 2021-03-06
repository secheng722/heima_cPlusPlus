#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>

class OrderFile {
public:
	//构造函数
	OrderFile();
	//更新预约记录
	void updateOrder();
	//预约条数
	int m_size;
	//记录所有预约信息的容器
	map<int, map<string, string>>m_orderData;
};

