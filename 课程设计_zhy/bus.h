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
    int bus_number;       //��������
    int index;            //���ڽӱ��еı��
    struct station* next; //��һվ
} ST;

typedef struct BusGraghN
{
    int stations_number;             //����վ̨������
    vector<ST> stations;             //�������ӵ�һ������·��
    vector<ST> N;                    //�ڽӱ�洢
    vector<ST> c_N;                  //�ڽӱ��˴�֮�����ֱ���·��
    vector<string> st_names;         //�洢��Ӧ��վ̨����
    vector<vector<int> > bus_numbers; //�洢���Ծ����Ĺ�����·����
} BG;

typedef struct node
{
    int before;
    int index;
} no; //BFS������ʱ��������·��

class BUS {
public:
    BUS();
    void menu(BG& G, string str1, string str2, int& st_1, int& st_2);
    void creatGragh(BG& G);                       //����������·ͼ
    int findSt(BG& G, string name);             //Ѱ�Ҹó�վ�Ƿ������ͼ��
    int change(string bus_name);                //���ַ���ת��Ϊint��
    int is_in(BG& G, int i, int j);               //�ж�����վ���Ƿ�֮ǰ�Ѿ�����
    int is_in_c_N(BG& G, int i, int j);           //�ж�����ͼվ��֮���Ƿ�������ֱ��ͼ��
    void short_change(BG& G, int st_1, int st_2); //���ת���ĳ˳�·��
    void short_way(BG& G, int st_1, int st_2);    //Ѱ������վ̨֮�����̳˳�·�ߣ�����վ�����٣�
private:
    BG G;
    int st_1, st_2;
    string str1, str2;
    ST* p;
};

