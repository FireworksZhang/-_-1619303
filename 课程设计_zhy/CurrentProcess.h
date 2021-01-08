#pragma once
#include <iostream>
using namespace std;

struct CurrentProcess {  //当前进程节点
	string name;  //进程名
	string duration;  //持续时间
	long memory;  //使用内存
	CurrentProcess* pre = nullptr;
	CurrentProcess* next = nullptr;

	CurrentProcess(string name, string duration, long memory) {
		this->name = name;
		this->duration = duration;
		this->memory = memory;
	}
};

class TwoLinkList {  //双向链表类
public:
	CurrentProcess* head;  //头指针
	CurrentProcess* tail;  //尾指针
	int length;  //链表长度

	TwoLinkList();  //构造函数
	~TwoLinkList();  //析构函数
	void clone(const TwoLinkList& l);  //拷贝函数
	void downSort();  //降序排列
	void addNode(string name, string duration, long memory);  //向尾部添加节点
	bool findNode(string name);  //查找结点
	void deleteNode();  //删除节点
	void showNode();  //输出节点
};
