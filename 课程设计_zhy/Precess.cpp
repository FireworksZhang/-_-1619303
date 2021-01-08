#include"Process.h"

using namespace std;

time_t SwitchTime(string time) {  //将yyyymmddhhmmss转为s
	struct tm toSecond;

	toSecond.tm_year = stoi(time.substr(0, 4)) - 1900;
	toSecond.tm_mon = stoi(time.substr(4, 2)) - 1;
	toSecond.tm_mday = stoi(time.substr(6, 2));
	toSecond.tm_hour = stoi(time.substr(8, 2));
	toSecond.tm_min = stoi(time.substr(10, 2));
	toSecond.tm_sec = stoi(time.substr(12, 2));
	return mktime(&toSecond);
}

string SwitchTime(time_t second) {  //将s转为结束时间
	struct tm todate;
	char time[32] = { 0 };

	localtime_s(&todate, &second);
	asctime_s(time, &todate);
	return time;
}

string FormatTime(long time) {  //将s转为持续时间
	int days = 0, hours = 0, minutes = 0, seconds = 0;

	days = time / (24 * 60 * 60);
	hours = (time - days * 24 * 60 * 60) / (60 * 60);
	minutes = (time - days * 24 * 60 * 60 - hours * 60 * 60) / 60;
	seconds = time - days * 24 * 60 * 60 - hours * 60 * 60 - minutes * 60;
	return to_string(days) + "天" + to_string(hours) + "小时" + to_string(minutes) + "分钟"
		+ to_string(seconds) + "秒";
}

Process:: Process() {
	FILE* file;  //文件流
	char* cmd = (char*)"wmic process get caption,processid,creationdate,workingsetsize";  //命令行语句
	char result[128] = { 0 };  //读取结果数组
	TwoLinkList oldCurrentProcess;  //旧活动进程
	TwoLinkList newCurrentProcess;  //新活动进程
	OneLinkList finishedProcess;  //死亡进程

	while (true) {
		time_t begin = time(NULL), end;  //程序开始时间和结束时间，用于每秒间隔输出

		newCurrentProcess.deleteNode();  //清空新活动进程链表
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
			char* temp;  //临时变量

			memset(result, 0, 128);  //初始化置0
			fgets(result, 128, file);  //读取第一行caption、processid、creationdate、workingsetsize不存储
			while (fgets(result, 128, file) != NULL) {  //读取每行数据
				if (result[0] == '\r') {  //跳过最后回车符
					continue;
				}
				content.clear();  //清空vector
				temp = strtok(result, " ");
				do {
					content.push_back(temp);
					temp = strtok(NULL, " ");
				} while (temp != NULL);
				memory = stol(content.at(content.size() - 2));  //读取内存大小
				beginTime = content.at(content.size() - 4);  //读取开始时间
				beginTime = beginTime.substr(0, 14);
				beginTime = to_string(SwitchTime(beginTime));
				nowTime = time(NULL);  //获取当前时间
				duration = FormatTime((long)nowTime - stol(beginTime));  //计算持续时间
				name = "";
				for (int i = 0; i < content.size() - 4; i++) {
					name = name + content.at(i) + " ";
				}  //拼接进程名（有带空格的进程名）
				pid = content.at(content.size() - 3);  //获取PID
				newCurrentProcess.addNode(name + pid, duration, memory);  //读取一行添加一次节点
			}
			newCurrentProcess.downSort();
			newCurrentProcess.showNode();  //输出活动进程
			if (oldCurrentProcess.length == 0) {  //第一次直接覆盖旧活动进程
				oldCurrentProcess.clone(newCurrentProcess);
			}
			else {  //之后先对比并添加结束进程再覆盖旧活动进程
				CurrentProcess* p = oldCurrentProcess.head;

				while (p != nullptr) {
					if (!newCurrentProcess.findNode(p->name)) {  //如果旧进程不存在新进程链表钟，则死亡
						nowTime = time(NULL);  //获取当前时间
						string endTime = SwitchTime(nowTime);
						finishedProcess.addNode(p->name, p->duration, endTime);
					}
					p = p->next;
				}
				oldCurrentProcess.deleteNode();  //清空旧活动进程
				oldCurrentProcess.clone(newCurrentProcess);
			}
			finishedProcess.showNode();  //输出死亡进程
			if ((_pclose(file)) == -1) {
				cout << "Pclose Error!" << endl;
				exit (-2);
			}
			end = time(NULL);
			while (end - begin < 1) {  //如果运行时间不足1秒，则不结束本次循环
				end = time(NULL);
			}
		}
	}
	exit(0);
}
