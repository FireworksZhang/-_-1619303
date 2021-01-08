#include"bus.h"



BUS::BUS()
{
    creatGragh(G);
    while (1)
    {
        menu(G, str1, str2, st_1, st_2); //两个字符串在此时被赋值
        short_change(G, st_1, st_2);     //最短转车
        short_way(G, st_1, st_2); //最短站台
    }
    system("pause");
}

void BUS::menu(BG& G, string str1, string str2, int& st_1, int& st_2)
{
    int choice;
    cout << "欢迎使用南京公交线路查询" << endl;
    cout << "请输入起点:";
    cin >> str1;
    st_1 = findSt(G, str1);
    while (st_1 == -1)
    {
        cout << "找不到起点，请重新输入:";
        cin >> str1;
        st_1 = findSt(G, str1);
    }
    cout << "请输入终点:";
    cin >> str2;
    st_2 = findSt(G, str2);
    while (st_2 == -1)
    {
        cout << "找不到终点，请重新输入:";
        cin >> str2;
        st_2 = findSt(G, str2);
    }
}

void BUS::creatGragh(BG& G)
{
    G.stations_number = 0;
    string temp_station_name;     //当前站台
    string temp_station_name_pre; //当前公交的前一个站台

    string temp_bus;              //记录某一行的公交号信息

    ST* t, * p;                    //申请空间
    vector<int> temp_v;

    char temp_sy;
    int bus_n;    //记录对应的公交车号
    int flag = 0; //记录是否未第一个公交站台

    fstream f;
    f.open("南京公交线路.txt", ios::in);
    if (f.fail())
    {
        cout << "公交信息文件打开失败" << endl;
        exit(0);
    }

    while (1)
    {
        flag = 0;
        temp_sy = ' ';
        f >> temp_bus;

        if (f.eof())
            break;

        bus_n = change(temp_bus); //转换为公交号
        t = new ST;
        t->bus_number = bus_n; //创建公交线路地链表头
        t->next = NULL;
        G.stations.push_back(*t);
        p = &G.stations.back();
        while (temp_sy == ' ') //跳过空格
            f.get(temp_sy);
        while (1) //处理后面一长段的公交信息
        {
            int ch_pos = 0;
            temp_station_name.clear();
            while (temp_sy != ',' && temp_sy != '\n') //到','为止
            {
                temp_station_name += temp_sy;
                f.get(temp_sy);
            }
            //cout << temp_station_name << endl;
            int pos = findSt(G, temp_station_name);
            if (pos == -1) //该站并未被创建
            {
                G.stations_number++;
                G.st_names.push_back(temp_station_name);
                t = new ST;
                t->next = NULL;
                t->index = G.stations_number - 1;
                G.N.push_back(*t);
                G.c_N.push_back(*t);
                G.bus_numbers.push_back(temp_v);                       //存储一个新的容器
                G.bus_numbers[G.stations_number - 1].push_back(bus_n); //公交号
            }
            else //该站已经被创建
            {
                G.bus_numbers[pos].push_back(bus_n);
            }
            t = new ST; //连接链表
            int i = findSt(G, temp_station_name);
            t->index = i;
            t->bus_number = bus_n;
            t->next = p->next;
            p->next = t;
            p = p->next;
            if (flag) //非第一个站点才需要进行连接
            {
                int i = findSt(G, temp_station_name_pre);
                int j = findSt(G, temp_station_name);
                if (!is_in(G, i, j))
                {
                    t = new ST;
                    t->bus_number = bus_n;
                    t->index = j;
                    t->next = G.N[i].next;
                    G.N[i].next = t;

                    t = new ST;
                    t->bus_number = bus_n;
                    t->index = i;
                    t->next = G.N[j].next;
                    G.N[j].next = t;
                }
            }
            flag = 1;                                  //之后为非第一个节点
            temp_station_name_pre = temp_station_name; //进行更替
            if (temp_sy == '\n')
                break;
            else
                f.get(temp_sy);
        }
    }
    f.close();

    //以下为根据链表创建直达图，一条路线上面的两个站台之间彼此相连
    for (int i = 0; i < G.stations.size(); i++)
    {
        p = G.stations[i].next; //将p和t连接在一起
        while (p->next)
        {
            t = p->next;
            while (t)
            {
                if (!is_in_c_N(G, p->index, t->index)) //创建直达图
                {
                    ST* temp;
                    temp = new ST;
                    temp->index = t->index;
                    temp->next = G.c_N[p->index].next;
                    G.c_N[p->index].next = temp;

                    temp = new ST;
                    temp->index = p->index;
                    temp->next = G.c_N[t->index].next;
                    G.c_N[t->index].next = temp;
                }
                t = t->next;
            }
            p = p->next;
        }
    }
}

int BUS::findSt(BG& G, string name)
{
    for (int i = 0; i < G.stations_number; i++)
    {
        if (G.st_names[i] == name)
            return i;
    }
    return -1;
}

int BUS::change(string bus_name)
{
    int sum = 0;
    for (int i = 0; bus_name[i] <= '9' && bus_name[i] >= '0' && i < bus_name.size(); i++)
    {
        sum += bus_name[i] - '0';
        sum *= 10;
    }
    sum /= 10;
    return sum;
}

int BUS::is_in(BG& G, int i, int j)
{
    ST* p;
    p = G.N[i].next;
    while (p)
    {
        if (p->index == j)
            return 1;
        p = p->next;
    }
    return 0;
}

int BUS::is_in_c_N(BG& G, int i, int j)
{
    ST* p;
    p = G.c_N[i].next;
    while (p)
    {
        if (p->index == j)
            return 1;
        p = p->next;
    }
    return 0;
}

void BUS::short_change(BG& G, int st_1, int st_2)
{
    if (st_1 == st_2)
    {
        cout << "跳一下，你就到了!" << endl;
        return;
    }
    vector<no> q;
    no t, k;
    ST* p;
    int base = 0, flag = 0;
    //同样是采用BFS遍历即可，但是在输出的时候必须将所有的中间站点输出，即给定一条路线的起点以及
    //终点，必须输出所有的中间站点，这一个功能会单独写出一个函数进行输出2
    int visit[10007] = { 0 };
    no head;
    head.before = -1;
    head.index = st_1;
    q.push_back(head); //将根节点入队
    while (base != q.size() && !flag)
    {
        t = q[base];
        base++;
        p = G.c_N[t.index].next;
        flag = 0;
        while (p && !flag)
        {
            if (!visit[p->index])
            {
                k.before = base - 1;
                k.index = p->index;
                if (p->index == st_2)
                    flag = 1;
                q.push_back(k);
            }
            p = p->next;
        }
    }
    if (base == q.size())
    {
        cout << "未找到路径" << endl;
        return;
    }
    else //找到路径
    {
        vector<int> pr; //用于输出的数组，倒序输出
        vector<int>::iterator i;
        while (k.before != -1)
        {
            pr.push_back(k.index);
            k = q[k.before];
        }
        pr.push_back(k.index);
        i = pr.end() - 1;
        cout << "起点：" << G.st_names[pr.back()];
        for (int j = 1; j < pr.size(); j++)
        {
            cout << " --- " << G.st_names[*(i - j)];
            if ((j - 1) % 8 == 0 && j != 1)
                cout << "\n";
        }
        cout << "\n";
    }
}

void BUS::short_way(BG& G, int st_1, int st_2)
{
    if (st_1 == st_2)
    {
        cout << "跳一下，你就到了!" << endl;
        return;
    }
    vector<no> q;
    no t, k;
    ST* p;
    int base = 0, flag = 0;
    //采用BFS遍历即可
    int visit[10007] = { 0 };
    no head;
    head.before = -1;
    head.index = st_1;
    q.push_back(head); //将根节点入队
    while (base != q.size() && !flag)
    {
        t = q[base];
        base++;
        p = G.N[t.index].next;
        flag = 0;
        while (p && !flag)
        {
            if (!visit[p->index])
            {
                k.before = base - 1;
                k.index = p->index;
                if (p->index == st_2)
                    flag = 1;
                q.push_back(k);
            }
            p = p->next;
        }
    }
    if (base == q.size())
    {
        cout << "未找到路径" << endl;
        return;
    }
    else //找到路径
    {
        vector<int> pr; //用于输出的数组，倒序输出
        vector<int>::iterator i;
        while (k.before != -1)
        {
            pr.push_back(k.index);
            k = q[k.before];
        }
        pr.push_back(k.index);
        i = pr.end() - 1;
        cout << "起点：" << G.st_names[pr.back()];
        for (int j = 1; j < pr.size(); j++)
        {
            cout << " --- " << G.st_names[*(i - j)];
            if ((j - 1) % 8 == 0 && j != 1)
                cout << "\n";
        }
        cout << "\n";
    }
}