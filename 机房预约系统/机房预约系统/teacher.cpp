#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empId, string userName, string passWord)
{
	this->m_empId = empId;
	this->m_userName = userName;
	this->m_passWord = passWord;
}

void Teacher::openMenu()
{
	cout << "1.查找所有预约" << endl
		 << "2.审核所有预约" << endl
		 << "0.注销教师登录" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << "预约日期：周" << of.m_orderData[i]["date"]
			<< "\t时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
			<< "\t学号：" <<of.m_orderData[i]["stuId"]
			<< "\t姓名：" <<of.m_orderData[i]["stuName"]
			<< "\t机房编号为：" << of.m_orderData[i]["roomId"]
			<< "\t预约状态为：";
		string status;
		string* st = &of.m_orderData[i]["status"];
		if (*st == "1") {
			status = "审核中";
		}
		else if (*st == "2") {
			status = "预约成功";
		}
		else if (*st == "-1") {
			status = "预约失败";
		}
		else {
			status = "预约取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");

}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int>v;
	for (int i = 0; i < of.m_size; i++) {
		if (of.m_orderData[i]["status"]=="1") {
			cout << index << ".";
			index++;
			v.push_back(i);
			cout << "预约日期：周" << of.m_orderData[i]["date"]
				<< " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< " 机房编号为：" << of.m_orderData[i]["roomId"]
				<< " 预约状态为：";
			string status;
			string* st = &of.m_orderData[i]["status"];
			if (*st == "1") {
				status = "审核中";
			}
			else if (*st == "2") {
				status = "预约成功";
			}
			else if (*st == "-1") {
				status = "预约失败";
			}
			else {
				status = "预约取消";
			}
			cout << status << endl;
		}
	}
	int select = 0;
	cout << "请输入要审核的记录 0:退出取消" << endl;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				cout << "退出成功" << endl;
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "2";
				cout << "审核成功" << endl;
				break;
			}
		}
		else {
			cout << "输入编号错误" << endl;
		}
	}
	of.updateOrder();
	system("pause");
	system("cls");
}
