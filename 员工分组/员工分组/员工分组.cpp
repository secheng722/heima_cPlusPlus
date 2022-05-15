#include <iostream>
#include <map>
#include <vector>
#include "员工分组.h"
using namespace std;
#define CEHUA 0
#define YANFA 1
#define MEISHU 2
class worker {
public:
    string m_name;
    int m_salary;
};
void createWorker(vector<worker>&v) {
    string nameSeed = "ABCDEFGHIJ";
    for(char c : nameSeed)
    {
        worker n_worker;
        n_worker.m_name = "员工";
        n_worker.m_name += c;
        n_worker.m_salary = rand() % 10000 + 10000;//10000~19999
        v.push_back(n_worker);
    }
}
void setGroup(const vector<worker>&v, multimap<int, worker>&m) {
    for (auto it = v.begin(); it != v.end(); it++) {
        int depId = rand() % 3;
        m.insert(make_pair(depId, *it));
    }
}
void showWorkByGroup(const multimap<int, worker>& m) {
    cout << "策划部门：" << endl;
    auto it=m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; it != m.end() && index < count; it++, index++) {
        cout << " 姓名：" << it->second.m_name << " 薪资： " << it->second.m_salary << endl;
    } 
    cout << "研发部门：" << endl;
    it=m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; it != m.end() && index < count; it++, index++) {
        cout << " 姓名：" << it->second.m_name << " 薪资： " << it->second.m_salary << endl;
    } 
    cout << "美术部门：" << endl;
    it=m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; it != m.end() && index < count; it++, index++) {
        cout << " 姓名：" << it->second.m_name << " 薪资： " << it->second.m_salary << endl;
    }


}
int main()
{
	vector<worker>vWorker;
    createWorker(vWorker);
    multimap<int, worker>mWorker;
    setGroup(vWorker, mWorker);
    showWorkByGroup(mWorker);
    //for (auto it = vWorker.begin(); it != vWorker.end(); it++) {
    //    cout << " 姓名：" << it->m_name << " 工资：" << it->m_salary << endl;
    //}
    cout << "Hello World!\n";
}
