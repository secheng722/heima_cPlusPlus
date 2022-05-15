#include "student.h"

Student::Student()
{
}

Student::Student(int id, string userName, string passWord)
{
	this->m_Id = id;
	this->m_userName = userName;
	this->m_passWord = passWord;
	ifstream ifs(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum) {
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::openMenu()
{
	cout << "1.申请预约" << endl;
	cout << "2.查看自身预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销账号" << endl;
}

void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请选择日期：" << endl;
	cout << "1.周一，2.周二，3.周三，4.周四，5.周五" << endl;
	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "输入错误，请重新输入" << endl;
	}
	cout << "请输入申请预约时间段" << endl;
	cout << "1.上午，2.下午" << endl;
	while (true) {
		cin >> interval;
		if (interval == 1 || interval == 2)
			break;
		cout << "输入错误，请重新输入" << endl;
	}
	cout << "请选择机房：" << endl;
	for (auto it : this->vCom) {
		cout << it.m_comId << "号机房 容量为" << it.m_maxNum << endl;
	}
	while (true) {
		cin >> room;
		auto it=std::find_if(vCom.begin(), vCom.end(), [&room](ComputerRoom& com) {
			if (room==com.m_comId) {
				return true;
			}
			return false;
			});
		if (it != vCom.end())
			break;
		cout << "输入错误，请重新输入" << endl;
	}
	cout << "预约成功！ 审核中" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->m_Id << " "
		<< "stuName:"<<this->m_userName<<" "
		<< "roomId:" << room << " "
		<< "status:" << 1 <<endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
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
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::calcelOrder()
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
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())
			&&(of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2")) {
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
	cout << "请输入要取消的记录 0:退出取消" << endl;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				cout << "退出成功" << endl;
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				cout << "取消成功" << endl;
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
