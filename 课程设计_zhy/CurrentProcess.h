#pragma once
#include <iostream>
using namespace std;

struct CurrentProcess {  //��ǰ���̽ڵ�
	string name;  //������
	string duration;  //����ʱ��
	long memory;  //ʹ���ڴ�
	CurrentProcess* pre = nullptr;
	CurrentProcess* next = nullptr;

	CurrentProcess(string name, string duration, long memory) {
		this->name = name;
		this->duration = duration;
		this->memory = memory;
	}
};

class TwoLinkList {  //˫��������
public:
	CurrentProcess* head;  //ͷָ��
	CurrentProcess* tail;  //βָ��
	int length;  //������

	TwoLinkList();  //���캯��
	~TwoLinkList();  //��������
	void clone(const TwoLinkList& l);  //��������
	void downSort();  //��������
	void addNode(string name, string duration, long memory);  //��β����ӽڵ�
	bool findNode(string name);  //���ҽ��
	void deleteNode();  //ɾ���ڵ�
	void showNode();  //����ڵ�
};
