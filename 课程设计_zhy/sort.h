#pragma once
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<queue>
#include <sys/timeb.h>
#include<fstream>
using namespace std;

const int CountNumber = 50000;
class SortSolution
{
protected:
	vector<int> data[10];
	struct timeb startTime, endTime;
public:
	SortSolution();
	bool check();//��������Ƿ�ɹ�
	void Insert_Sort();	//1.��������
	void insertsort(vector<int>& a);//��������������
	void Shell_Sort();	//2.ϣ������ 
	void ShellSort(vector<int>& a);//ϣ������������
	void Bubble_Sort();	//3.ð������ 
	void bubblesort(vector<int>& a);//ð������������
	void Quick_Sort();//4.���� 
	void quicksort(vector<int>& a, int l, int r);//���Ÿ�������
	void Select_Sort();//5.ѡ������ 
	void selectSort(vector<int>& v);//ѡ������������
	void Heap();//6.������ 
	void adjust(vector<int>& arr, int len, int index);
	void heapSort(vector<int>& arr);
	void Merge_Sort();//7.�鲢���� 
	void merge(vector<int>& v, int left, int mid, int right);
	void merge_Sort(vector<int>& v, int left, int right);
	void mergeSort(vector<int>& v);
	void Radix_Sort();//8.�������� 
	int getMax(vector<int>& v);
	void countSort(vector<int>& v, int exp);
	void radixsort(vector<int>& v);

};