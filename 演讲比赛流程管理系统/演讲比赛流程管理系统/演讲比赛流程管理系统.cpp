#include <iostream>
#include "speechManager.h"
int main()
{
    srand((unsigned int)time(0));
    SpeechManager sm;
    int choice = 0;
    //for (map<int, Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end();it++) {
    //    cout << "选手编号: " << it->first << " 姓名：" << it->second.m_name << " 分数：" << it->second.m_score[0] << endl;
    //}
    //
    while (true) {
        sm.showMenu();
        sm.loadRecord();
        cout << "  请输入您的选择： " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.clearRecord();
            break;
        case 4://退出系统
            sm.exitSystem();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}

