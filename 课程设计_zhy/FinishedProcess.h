#pragma once
#include <iostream>
using namespace std;

struct FinishedProcess {  //已结束进程节点
	string name;  //进程名
	string duration;  //持续时间
	string endTime;  //结束时间
	FinishedProcess* next = nullptr;

	FinishedProcess(string name, string duration, string endTime) {
		this->name = name;
		this->duration = duration;
		this->endTime = endTime;
	}
};

class OneLinkList {  //单向链表类
public:
	FinishedProcess* head;  //头指针
	int length;  //链表长度

	OneLinkList();  //构造函数
	~OneLinkList();  //析构函数
	void addNode(string name, string duration, string endTime);  //向头部添加节点
	void showNode();  //输出节点
};
