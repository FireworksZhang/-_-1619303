#include<iomanip>
#include "FinishedProcess.h"

OneLinkList::OneLinkList() {
	head = nullptr;
	length = 0;
}

OneLinkList::~OneLinkList() {
	FinishedProcess* temp = head;
	if (head != nullptr) {
		head = head->next;
		delete temp;  //�ͷ��ڴ�
		temp = head;
	}
	length = 0;
	head = nullptr;
}

void OneLinkList::addNode(string name, string duration, string endTime) {
	if (head == nullptr) {
		head = new FinishedProcess(name, duration, endTime);
		length++;
	}
	else {
		FinishedProcess* p;
		p = head;
		head = new FinishedProcess(name, duration, endTime);
		head->next = p;
		length++;
	}
}

void OneLinkList::showNode() {
	FinishedProcess* p;
	p = head;
	if (p == nullptr) {
		cout << "****��ǰ���ѽ������̣�****" << endl;
	}
	else {
		cout << endl << "--------------------------��������--------------------------" << endl << endl;
		cout << setw(75) << left << "������+pid" << setw(20) << left << "����ʱ��" << "����ʱ��" << endl;
		while (p) {
			cout << setw(75) << left << p->name << setw(20) << left << p->duration << p->endTime;
			p = p->next;
		}
		cout << endl << "--------------------------��������--------------------------" << endl << endl;
	}
}
