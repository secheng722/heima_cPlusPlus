#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string userName, string passWord)
{
	this->m_userName = userName;
	this->m_passWord = passWord;
	this->initVector();
}

void Manager::openMenu()
{
	cout << "当前学生数量为：" << vStu.size() << endl;
	cout << "当前教师数量为：" << vTea.size() << endl;
	cout << "1.添加新的账号" << endl;
	cout << "2.显示所有账号" << endl;
	cout << "3.显示机房信息" << endl;
	cout << "4.清空所有信息" << endl;
	cout << "0.注销登录信息" << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生  2.添加教师" << endl;
	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		if (checkRepeat(id, select)) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	if (select == 1) {
		vStu.push_back(Student(id,name,pwd));
	}
	else {
		vTea.push_back(Teacher(id, name, pwd));
	}
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();

}

void Manager::showPerson()
{
	cout << "请选择需要查看的内容：" << endl;
	cout << "1.查看所有学生 2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), [](Student& s1) {
			cout << "学生编号：" << s1.m_Id << "\t学生姓名：" << s1.m_userName
				<< "\t学生密码：" << s1.m_passWord << endl;
			});
	}
	else {
		//查看老师
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), [](Teacher& t1) {
			cout << "职工编号：" << t1.m_empId<< "\t职工姓名：" << t1.m_userName
				<< "\t职工密码：" << t1.m_passWord << endl;
			});
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (auto it : this->vCom) {
		cout << "机房编号为：" << it.m_comId << "\t机房最大容量为：" << it.m_maxNum << endl;
	}
	system("pause");
	system("cls");

}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空完成！" << endl;
	system("pause");
	system("cls");

}

void Manager::initVector()
{
	this->vStu.clear();
	this->vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_userName && ifs >> s.m_passWord) {
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_userName && ifs >> t.m_passWord) {
		vTea.push_back(t);
	}
	ifs.close();
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_comId && ifs >> c.m_maxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) {
		for (auto it : this->vStu) {
			if (id == it.m_Id) {
				return true;
			}
		}
	}else{
		for (auto it : this->vTea) {
			if (id == it.m_empId) {
				return true;
			}
		}
	}
	return false;
}
