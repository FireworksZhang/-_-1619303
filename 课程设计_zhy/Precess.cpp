#include"Process.h"

using namespace std;

time_t SwitchTime(string time) {  //��yyyymmddhhmmssתΪs
	struct tm toSecond;

	toSecond.tm_year = stoi(time.substr(0, 4)) - 1900;
	toSecond.tm_mon = stoi(time.substr(4, 2)) - 1;
	toSecond.tm_mday = stoi(time.substr(6, 2));
	toSecond.tm_hour = stoi(time.substr(8, 2));
	toSecond.tm_min = stoi(time.substr(10, 2));
	toSecond.tm_sec = stoi(time.substr(12, 2));
	return mktime(&toSecond);
}

string SwitchTime(time_t second) {  //��sתΪ����ʱ��
	struct tm todate;
	char time[32] = { 0 };

	localtime_s(&todate, &second);
	asctime_s(time, &todate);
	return time;
}

string FormatTime(long time) {  //��sתΪ����ʱ��
	int days = 0, hours = 0, minutes = 0, seconds = 0;

	days = time / (24 * 60 * 60);
	hours = (time - days * 24 * 60 * 60) / (60 * 60);
	minutes = (time - days * 24 * 60 * 60 - hours * 60 * 60) / 60;
	seconds = time - days * 24 * 60 * 60 - hours * 60 * 60 - minutes * 60;
	return to_string(days) + "��" + to_string(hours) + "Сʱ" + to_string(minutes) + "����"
		+ to_string(seconds) + "��";
}

Process:: Process() {
	FILE* file;  //�ļ���
	char* cmd = (char*)"wmic process get caption,processid,creationdate,workingsetsize";  //���������
	char result[128] = { 0 };  //��ȡ�������
	TwoLinkList oldCurrentProcess;  //�ɻ����
	TwoLinkList newCurrentProcess;  //�»����
	OneLinkList finishedProcess;  //��������

	while (true) {
		time_t begin = time(NULL), end;  //����ʼʱ��ͽ���ʱ�䣬����ÿ�������

		newCurrentProcess.deleteNode();  //����»��������
		if ((file = _popen(cmd, "r")) == NULL) {
			cout << "Popen Error!" << endl;
			exit(-1);
		}
		else {
			vector<char*>content;
			string name;
			string pid;
			string beginTime;
			string duration;
			long memory;
			time_t nowTime;
			char* temp;  //��ʱ����

			memset(result, 0, 128);  //��ʼ����0
			fgets(result, 128, file);  //��ȡ��һ��caption��processid��creationdate��workingsetsize���洢
			while (fgets(result, 128, file) != NULL) {  //��ȡÿ������
				if (result[0] == '\r') {  //�������س���
					continue;
				}
				content.clear();  //���vector
				temp = strtok(result, " ");
				do {
					content.push_back(temp);
					temp = strtok(NULL, " ");
				} while (temp != NULL);
				memory = stol(content.at(content.size() - 2));  //��ȡ�ڴ��С
				beginTime = content.at(content.size() - 4);  //��ȡ��ʼʱ��
				beginTime = beginTime.substr(0, 14);
				beginTime = to_string(SwitchTime(beginTime));
				nowTime = time(NULL);  //��ȡ��ǰʱ��
				duration = FormatTime((long)nowTime - stol(beginTime));  //�������ʱ��
				name = "";
				for (int i = 0; i < content.size() - 4; i++) {
					name = name + content.at(i) + " ";
				}  //ƴ�ӽ��������д��ո�Ľ�������
				pid = content.at(content.size() - 3);  //��ȡPID
				newCurrentProcess.addNode(name + pid, duration, memory);  //��ȡһ�����һ�νڵ�
			}
			newCurrentProcess.downSort();
			newCurrentProcess.showNode();  //��������
			if (oldCurrentProcess.length == 0) {  //��һ��ֱ�Ӹ��Ǿɻ����
				oldCurrentProcess.clone(newCurrentProcess);
			}
			else {  //֮���ȶԱȲ���ӽ��������ٸ��Ǿɻ����
				CurrentProcess* p = oldCurrentProcess.head;

				while (p != nullptr) {
					if (!newCurrentProcess.findNode(p->name)) {  //����ɽ��̲������½��������ӣ�������
						nowTime = time(NULL);  //��ȡ��ǰʱ��
						string endTime = SwitchTime(nowTime);
						finishedProcess.addNode(p->name, p->duration, endTime);
					}
					p = p->next;
				}
				oldCurrentProcess.deleteNode();  //��վɻ����
				oldCurrentProcess.clone(newCurrentProcess);
			}
			finishedProcess.showNode();  //�����������
			if ((_pclose(file)) == -1) {
				cout << "Pclose Error!" << endl;
				exit (-2);
			}
			end = time(NULL);
			while (end - begin < 1) {  //�������ʱ�䲻��1�룬�򲻽�������ѭ��
				end = time(NULL);
			}
		}
	}
	exit(0);
}
