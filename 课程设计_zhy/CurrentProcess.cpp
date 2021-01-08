#include<iomanip>
#include "CurrentProcess.h"

TwoLinkList::TwoLinkList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

TwoLinkList::~TwoLinkList() {
	CurrentProcess* temp = head;
	while (head != nullptr) {
		head = head->next;
		delete temp;  //释放内存
		temp = head;
	}
	length = 0;
	head = tail = nullptr;
}

void TwoLinkList::clone(const TwoLinkList& backup) {
	head = tail = nullptr;
	length = 0;
	if (backup.head != nullptr) {
		CurrentProcess* p = backup.head;
		head = new CurrentProcess(p->name, p->duration, p->memory);
		length++;
		p = p->next;
		CurrentProcess* q = head;
		while (p != nullptr)
		{
			q->next = new CurrentProcess(p->name, p->duration, p->memory);
			q = q->next;
			length++;
			tail = p;
			p = p->next;
		}

		int abc = 0;
	}
}

void TwoLinkList::downSort() {
	CurrentProcess* p, * q;
	CurrentProcess temp("", "", 0);
	for (p = head; p->next != nullptr; p = p->next) {
		for (q = p->next; q != nullptr; q = q->next) {
			if (p->memory < q->memory) {
				temp.memory = p->memory;
				temp.duration = p->duration;
				temp.name = p->name;
				p->memory = q->memory;
				p->duration = q->duration;
				p->name = q->name;
				q->memory = temp.memory;
				q->duration = temp.duration;
				q->name = temp.name;
			}
		}
	}
}

void TwoLinkList::addNode(string name, string duration, long memory) {
	if (head == nullptr) {
		head = new CurrentProcess(name, duration, memory);
		length++;
		tail = head;
	}
	else {
		tail->next = new CurrentProcess(name, duration, memory);
		length++;
		tail->next->pre = tail;
		tail = tail->next;
	}
}

bool TwoLinkList::findNode(string name) {
	CurrentProcess* p;
	p = head;
	for (int i = 0; i < length; i++) {
		if (p->name != name) {
			p = p->next;
		}
		else {
			return true;
		}
	}
	return false;
}

void TwoLinkList::deleteNode() {
	CurrentProcess* p = head;
	CurrentProcess* q;
	while (p != nullptr) {
		q = p;
		p = p->next;
		delete q;  //释放内存
	}
	length = 0;
	head = nullptr;
	p = nullptr;
	q = nullptr;
}

void TwoLinkList::showNode() {
	CurrentProcess* p;
	p = head;
	if (p == nullptr) {
		cout << endl << "****当前无活动进程！****" << endl << endl;
	}
	else {
		cout << endl << "--------------------------活动进程--------------------------" << endl << endl;
		cout << setw(75) << left << "进程名+pid" << setw(20) << left << "持续时间" << "内存使用情况(KB)" << endl;
		while (p != tail->next) {
			cout << setw(75) << left << p->name << setw(20) << left << p->duration << p->memory << endl;
			p = p->next;
		}
		cout << endl << "--------------------------活动进程--------------------------" << endl << endl;
	}
}
