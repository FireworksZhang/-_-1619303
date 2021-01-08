#include"bus.h"



BUS::BUS()
{
    creatGragh(G);
    while (1)
    {
        menu(G, str1, str2, st_1, st_2); //�����ַ����ڴ�ʱ����ֵ
        short_change(G, st_1, st_2);     //���ת��
        short_way(G, st_1, st_2); //���վ̨
    }
    system("pause");
}

void BUS::menu(BG& G, string str1, string str2, int& st_1, int& st_2)
{
    int choice;
    cout << "��ӭʹ���Ͼ�������·��ѯ" << endl;
    cout << "���������:";
    cin >> str1;
    st_1 = findSt(G, str1);
    while (st_1 == -1)
    {
        cout << "�Ҳ�����㣬����������:";
        cin >> str1;
        st_1 = findSt(G, str1);
    }
    cout << "�������յ�:";
    cin >> str2;
    st_2 = findSt(G, str2);
    while (st_2 == -1)
    {
        cout << "�Ҳ����յ㣬����������:";
        cin >> str2;
        st_2 = findSt(G, str2);
    }
}

void BUS::creatGragh(BG& G)
{
    G.stations_number = 0;
    string temp_station_name;     //��ǰվ̨
    string temp_station_name_pre; //��ǰ������ǰһ��վ̨

    string temp_bus;              //��¼ĳһ�еĹ�������Ϣ

    ST* t, * p;                    //����ռ�
    vector<int> temp_v;

    char temp_sy;
    int bus_n;    //��¼��Ӧ�Ĺ�������
    int flag = 0; //��¼�Ƿ�δ��һ������վ̨

    fstream f;
    f.open("�Ͼ�������·.txt", ios::in);
    if (f.fail())
    {
        cout << "������Ϣ�ļ���ʧ��" << endl;
        exit(0);
    }

    while (1)
    {
        flag = 0;
        temp_sy = ' ';
        f >> temp_bus;

        if (f.eof())
            break;

        bus_n = change(temp_bus); //ת��Ϊ������
        t = new ST;
        t->bus_number = bus_n; //����������·������ͷ
        t->next = NULL;
        G.stations.push_back(*t);
        p = &G.stations.back();
        while (temp_sy == ' ') //�����ո�
            f.get(temp_sy);
        while (1) //�������һ���εĹ�����Ϣ
        {
            int ch_pos = 0;
            temp_station_name.clear();
            while (temp_sy != ',' && temp_sy != '\n') //��','Ϊֹ
            {
                temp_station_name += temp_sy;
                f.get(temp_sy);
            }
            //cout << temp_station_name << endl;
            int pos = findSt(G, temp_station_name);
            if (pos == -1) //��վ��δ������
            {
                G.stations_number++;
                G.st_names.push_back(temp_station_name);
                t = new ST;
                t->next = NULL;
                t->index = G.stations_number - 1;
                G.N.push_back(*t);
                G.c_N.push_back(*t);
                G.bus_numbers.push_back(temp_v);                       //�洢һ���µ�����
                G.bus_numbers[G.stations_number - 1].push_back(bus_n); //������
            }
            else //��վ�Ѿ�������
            {
                G.bus_numbers[pos].push_back(bus_n);
            }
            t = new ST; //��������
            int i = findSt(G, temp_station_name);
            t->index = i;
            t->bus_number = bus_n;
            t->next = p->next;
            p->next = t;
            p = p->next;
            if (flag) //�ǵ�һ��վ�����Ҫ��������
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
            flag = 1;                                  //֮��Ϊ�ǵ�һ���ڵ�
            temp_station_name_pre = temp_station_name; //���и���
            if (temp_sy == '\n')
                break;
            else
                f.get(temp_sy);
        }
    }
    f.close();

    //����Ϊ����������ֱ��ͼ��һ��·�����������վ̨֮��˴�����
    for (int i = 0; i < G.stations.size(); i++)
    {
        p = G.stations[i].next; //��p��t������һ��
        while (p->next)
        {
            t = p->next;
            while (t)
            {
                if (!is_in_c_N(G, p->index, t->index)) //����ֱ��ͼ
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
        cout << "��һ�£���͵���!" << endl;
        return;
    }
    vector<no> q;
    no t, k;
    ST* p;
    int base = 0, flag = 0;
    //ͬ���ǲ���BFS�������ɣ������������ʱ����뽫���е��м�վ�������������һ��·�ߵ�����Լ�
    //�յ㣬����������е��м�վ�㣬��һ�����ܻᵥ��д��һ�������������2
    int visit[10007] = { 0 };
    no head;
    head.before = -1;
    head.index = st_1;
    q.push_back(head); //�����ڵ����
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
        cout << "δ�ҵ�·��" << endl;
        return;
    }
    else //�ҵ�·��
    {
        vector<int> pr; //������������飬�������
        vector<int>::iterator i;
        while (k.before != -1)
        {
            pr.push_back(k.index);
            k = q[k.before];
        }
        pr.push_back(k.index);
        i = pr.end() - 1;
        cout << "��㣺" << G.st_names[pr.back()];
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
        cout << "��һ�£���͵���!" << endl;
        return;
    }
    vector<no> q;
    no t, k;
    ST* p;
    int base = 0, flag = 0;
    //����BFS��������
    int visit[10007] = { 0 };
    no head;
    head.before = -1;
    head.index = st_1;
    q.push_back(head); //�����ڵ����
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
        cout << "δ�ҵ�·��" << endl;
        return;
    }
    else //�ҵ�·��
    {
        vector<int> pr; //������������飬�������
        vector<int>::iterator i;
        while (k.before != -1)
        {
            pr.push_back(k.index);
            k = q[k.before];
        }
        pr.push_back(k.index);
        i = pr.end() - 1;
        cout << "��㣺" << G.st_names[pr.back()];
        for (int j = 1; j < pr.size(); j++)
        {
            cout << " --- " << G.st_names[*(i - j)];
            if ((j - 1) % 8 == 0 && j != 1)
                cout << "\n";
        }
        cout << "\n";
    }
}