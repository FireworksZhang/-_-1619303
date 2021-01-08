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
	bool check();//¼ì²éÅÅĞòÊÇ·ñ³É¹¦
	void Insert_Sort();	//1.²åÈëÅÅĞò
	void insertsort(vector<int>& a);//²åÈëÅÅĞò¸¨Öúº¯Êı
	void Shell_Sort();	//2.Ï£¶ûÅÅĞò 
	void ShellSort(vector<int>& a);//Ï£¶ûÅÅĞò¸¨Öúº¯Êı
	void Bubble_Sort();	//3.Ã°ÅİÅÅĞò 
	void bubblesort(vector<int>& a);//Ã°ÅİÅÅĞò¸¨Öúº¯Êı
	void Quick_Sort();//4.¿ìÅÅ 
	void quicksort(vector<int>& a, int l, int r);//¿ìÅÅ¸¨Öúº¯Êı
	void Select_Sort();//5.Ñ¡ÔñÅÅĞò 
	void selectSort(vector<int>& v);//Ñ¡ÔñÅÅĞò¸¨Öúº¯Êı
	void Heap();//6.¶ÑÅÅĞò 
	void adjust(vector<int>& arr, int len, int index);
	void heapSort(vector<int>& arr);
	void Merge_Sort();//7.¹é²¢ÅÅĞò 
	void merge(vector<int>& v, int left, int mid, int right);
	void merge_Sort(vector<int>& v, int left, int right);
	void mergeSort(vector<int>& v);
	void Radix_Sort();//8.»ùÊıÅÅĞò 
	int getMax(vector<int>& v);
	void countSort(vector<int>& v, int exp);
	void radixsort(vector<int>& v);

};