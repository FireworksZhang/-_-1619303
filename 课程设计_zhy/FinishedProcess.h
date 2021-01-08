#pragma once
#include <iostream>
using namespace std;

struct FinishedProcess {  //�ѽ������̽ڵ�
	string name;  //������
	string duration;  //����ʱ��
	string endTime;  //����ʱ��
	FinishedProcess* next = nullptr;

	FinishedProcess(string name, string duration, string endTime) {
		this->name = name;
		this->duration = duration;
		this->endTime = endTime;
	}
};

class OneLinkList {  //����������
public:
	FinishedProcess* head;  //ͷָ��
	int length;  //������

	OneLinkList();  //���캯��
	~OneLinkList();  //��������
	void addNode(string name, string duration, string endTime);  //��ͷ����ӽڵ�
	void showNode();  //����ڵ�
};
