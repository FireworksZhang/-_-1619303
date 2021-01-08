#pragma once
#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef struct station
{
    int bus_number;       //公交车号
    int index;            //在邻接表中的编号
    struct station* next; //下一站
} ST;

typedef struct BusGraghN
{
    int stations_number;             //公交站台的数量
    vector<ST> stations;             //链表连接的一条公交路线
    vector<ST> N;                    //邻接表存储
    vector<ST> c_N;                  //邻接表存彼此之间可以直达的路线
    vector<string> st_names;         //存储对应的站台名字
    vector<vector<int> > bus_numbers; //存储可以经过的公交线路号码
} BG;

typedef struct node
{
    int before;
    int index;
} no; //BFS遍历的时候便于输出路径

class BUS {
public:
    BUS();
    void menu(BG& G, string str1, string str2, int& st_1, int& st_2);
    void creatGragh(BG& G);                       //创建公交线路图
    int findSt(BG& G, string name);             //寻找该车站是否存在于图中
    int change(string bus_name);                //将字符串转换为int型
    int is_in(BG& G, int i, int j);               //判断两个站点是否之前已经相连
    int is_in_c_N(BG& G, int i, int j);           //判断两个图站点之间是否相连（直达图）
    void short_change(BG& G, int st_1, int st_2); //最短转车的乘车路线
    void short_way(BG& G, int st_1, int st_2);    //寻找两个站台之间的最短乘车路线（经过站点最少）
private:
    BG G;
    int st_1, st_2;
    string str1, str2;
    ST* p;
};

