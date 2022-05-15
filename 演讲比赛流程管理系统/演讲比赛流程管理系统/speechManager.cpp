#include "speechManager.h"
//构造函数
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}
//析构函数
SpeechManager::~SpeechManager() {

}
//菜单功能
void SpeechManager::showMenu() {
	cout << "**************************************"<<endl;
	cout << "*************欢迎参加演讲比赛***********"<<endl;
	cout << "************* 1.开始演讲比赛 **********"<<endl;
	cout << "************* 2.查看往届记录 **********"<<endl;
	cout << "************* 3.清空比赛记录 **********"<<endl;
	cout << "************* 4.退出比赛程序 **********"<<endl;
	cout << "**************************************"<<endl;
	cout << endl;
}
//退出系统
void SpeechManager::exitSystem() {
	cout << "   感谢您的使用  " << endl;
	system("pause");
	exit(0);
}
//初始化属性
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->v_victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_record.clear();
}
//创建12名选手
void SpeechManager::createSpeaker(){
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//创建选手编号并放入v1 
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));

	}
}
//比赛流程控制
void SpeechManager::startSpeech() {
	//第一轮
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示结果
	this->showScore();
	
	//第二轮
	this->m_index++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示结果
	this->showScore();
	
	//保存记录
	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "本届比赛完毕" << endl;
	cout << "========================================" << endl;
	system("pause");
}
//抽签
void SpeechManager::speechDraw() {
	cout << "第《《" << this->m_index << "》》轮比赛选手正在抽签" << endl;
	cout << "======================" << endl;
	cout << "抽签后演讲顺序如下： " << endl;
	if (this->m_index == 1) {
		//第一轮
		random_shuffle(this->v1.begin(), this->v1.end());
		for (auto it:this->v1)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	else {
		//第二轮
		random_shuffle(this->v2.begin(), this->v2.end());
		for (auto it:this->v2)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	cout << "======================" << endl;
	system("pause");
}
//开始比赛
void SpeechManager::speechContest() {
	cout << "第《《" << this->m_index << "》》轮比赛开始" << endl;
	cout << "======================" << endl;
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	vector<int>v_src;
	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.0f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();//平均分
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		//每6个人取前三名
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "组比赛名次如下： " << endl;
			for (multimap<double, int, greater<double>>::iterator it
				= groupScore.begin(); it != groupScore.end(); it++) {
				cout << " 编号：" << it->second << " 姓名：" << this->m_speaker[it->second].m_name
					<< " 成绩：" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it
				= groupScore.begin(); it != groupScore.end()&&count<3; it++,count++) {
				if (this->m_index == 1) {
					v2.push_back(it->second);
				}
				else {
					v_victory.push_back(it->second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "第《《" << this->m_index << "》》轮比赛完成" << endl;
	cout << "===================================" << endl;
	cout << endl;
	system("pause");
}
//显示成绩
void SpeechManager::showScore() {
	cout << "第《《" << this->m_index << "》》轮比赛晋级选手信息如下" << endl;
	cout << "==========================================" << endl;
	vector<int>v;
	if (this->m_index == 1)
		v = v2;
	else
		v = v_victory;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号：" << *it << " 姓名：" << this->m_speaker[*it].m_name
			<< " 得分：" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
}
//保存记录
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加方式ios::app
	for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++) {
		ofs << *it << ","
			<< this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	this->fileIsEmpty = false;
	cout << "记录已保存" << endl;
	cout << "==========================" << endl;

}
//加载记录
void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data) {
		//cout << data << endl;
		vector<string>v;//存放字符串信息
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1){
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}
//展示记录
void SpeechManager::showRecord()
{
	//for (map<int, vector<string>>::iterator it = this->m_record.begin(); it != this->m_record.end(); it++) {
	//	cout << it->first << "冠军编号：" << it->second[0] << "冠军成绩：" << it->second[1] << endl;
	//}
	if (this->fileIsEmpty) {
		cout << "文件为空或不存在该文件" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "第" << i + 1 << "届比赛" << endl
				<< "冠军编号：" << this->m_record[i][0] << " 得分：" << this->m_record[i][1] << endl
				<< "亚军编号：" << this->m_record[i][2] << " 得分：" << this->m_record[i][3] << endl
				<< "季军编号：" << this->m_record[i][4] << " 得分：" << this->m_record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");

}
//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空吗？" << endl;
	cout << "1.确认 2.返回" << endl;
	int select = -1;
	cin >> select;
	if (select == 1) {
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
}
