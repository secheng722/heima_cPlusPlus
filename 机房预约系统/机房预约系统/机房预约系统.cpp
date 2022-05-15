#include <iostream>
#include"identity.h"
using namespace std;
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
//进入教师的子菜单界面
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
void studentMenu(Identity*& student) {
	while (true) {
		student->openMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showMyOrder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->calcelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员的子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		manager->openMenu();

		Manager* man = (Manager*)manager;
		
		int select = 0;
		cin >> select;
		if (select == 1) {
			man->addPerson();
		}
		else if (select == 2) {
			man->showPerson();
		}
		else if (select == 3) {
			man->showComputer();
		}
		else if (select == 4) {
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void loginIn(string fileName, int type) {
	//父类指针，指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1) {
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师身份验证	
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");


}

int main()
{
	while (true) {
		cout << "欢迎来到机房预约系统" << endl;
		cout << "\t1.学生代表" << endl;
		cout << "\t2.老****师" << endl;
		cout << "\t3.管*理*员" << endl;
		cout << "\t4.退出程序" << endl;
		cout << "请输入您的选择" << endl;
		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 4:
			cout << " 欢迎下一次的使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

