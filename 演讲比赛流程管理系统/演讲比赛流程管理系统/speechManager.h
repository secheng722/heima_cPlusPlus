#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
//演讲比赛管理类
class SpeechManager {
public:
	//构造函数
	SpeechManager();
	//析构函数
	~SpeechManager();
	//菜单功能
	void showMenu();
	//退出系统
	void exitSystem();
	//初始化属性
	void initSpeech();	
	//创建比赛选手
	void createSpeaker();
	//开始比赛
	void startSpeech();
	//抽签
	void speechDraw();
	//开始比赛
	void speechContest();
	//显示比赛结果
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord();
	//展示记录
	void showRecord();
	//清空记录
	void clearRecord();

	//存放往届记录
	map<int, vector<string>> m_record;
	//文件是否为空
	bool fileIsEmpty;
	//比赛选手第一轮 容器12人
	vector<int> v1;
	//比赛选手第二轮 容器6人
	vector<int> v2;
	//比赛选手获胜 3人
	vector<int> v_victory;
	//存在具体编号和选手的容器
	map<int, Speaker> m_speaker;
	//存放比赛轮数
	int m_index;
};
