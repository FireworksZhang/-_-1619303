#pragma once
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn(1e5 + 10);

struct edge {
    int src, dest;
    int dis;
    edge(int src, int dest, int dis) {
        this->src = src;
        this->dest = dest;
        this->dis = dis;
    }
    edge() {}
};
inline bool operator < (const edge& first, const edge& second) {
    return (first.dis > second.dis);
}



class subway {
private:
    int n, m;
    int father[maxn];
public:
    subway();
    void init();
    int find(int);
};