#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs(ORDER_FILE,ios::in);
	string date,interval,stuId,stuName,roomId,status;
	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && 
		ifs >> stuName && ifs >> roomId && ifs >> status) {
		//cout << date << " " << interval << " " << stuId << " "
		//<< stuName << " " << roomId << " " << status << " " << endl;
		map<string, string>m;
		auto function = [&m](const string& aim) {
			string key, value;
			int pos = aim.find(":");
			if (pos != -1) {
				key = aim.substr(0, pos);
				value = aim.substr(pos + 1);
			}
			m.insert(make_pair(key, value));
		};
		function(date);
		function(interval);
		function(stuId);
		function(stuName);
		function(roomId);
		function(status);
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
		//cout << "key=" << key << " value=" << value << endl;
	}
	ifs.close();
	/*for (auto it : this->m_orderData) {
		cout << "´ÎÐò£º"<<it.first << endl;
		for (auto it2 : it.second) {
			cout << " key="<<it2.first <<" value="<< it2.second;
		}
	}*/
}

void OrderFile::updateOrder()
{
	if (this->m_size == 0)
		return;
	ofstream ofs(ORDER_FILE, ios::out || ios::trunc);
	for (int i = 0; i < this->m_size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " "
			<< "interval:" << this->m_orderData[i]["interval"] << " "
			<< "stuId:" << this->m_orderData[i]["stuId"] << " "
			<< "stuName:" << this->m_orderData[i]["stuName"] << " "
			<< "roomId:" << this->m_orderData[i]["roomId"] << " "
			<< "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
