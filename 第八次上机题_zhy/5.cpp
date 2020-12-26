#include <iostream>
#include<algorithm>
using namespace std;
struct Trash {//结构体Trash用于存储垃圾的位置
	int x;
	int y;
};
Trash trash[1000];//由子任务说明可知，最多有1000处垃圾
int n;
bool FindXY(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (trash[i].x == x && trash[i].y == y)
			return true;
	}
	return false;
}
//判断给定的位置是否是垃圾回收站
bool IsStation(Trash t) {
	if (FindXY(t.x - 1, t.y) && FindXY(t.x + 1, t.y)
		&& FindXY(t.x, t.y - 1) && FindXY(t.x, t.y + 1))
		return true;
	else
		return false;
}
int main()
{
	int score[5] = { 0 };//记录不同得分的回收站的数目
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> trash[i].x >> trash[i].y;
	}
	int count = 0;
	//对每一个垃圾的位置进行遍历
	for (int i = 0; i < n; i++) {
		if (IsStation(trash[i])) {
			if (FindXY(trash[i].x - 1, trash[i].y - 1))
				count++;
			if (FindXY(trash[i].x - 1, trash[i].y + 1))
				count++;
			if (FindXY(trash[i].x + 1, trash[i].y - 1))
				count++;
			if (FindXY(trash[i].x + 1, trash[i].y + 1))
				count++;
			score[count]++;
			count = 0;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << score[i] << endl;
}

