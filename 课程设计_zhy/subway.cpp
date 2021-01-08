#include"subway.h"
#define _CRT_SECURE_NO_WARNINGS

subway::subway()
{
    cin >> n >> m;
    init();
    priority_queue <edge> pq;
    int rest = n - 1;
    int src, dest, dis;
    int ans = 0;
    for (int i = 0; i < m; i++) 
    {
        cin >> src >> dest >> dis;
        pq.push(edge(src, dest, dis));
    }
    while (rest && !pq.empty() && find(1) != find(n)) {
        edge cur = pq.top();
        pq.pop();
        if (find(cur.src) != find(cur.dest)) {
            rest--;
            father[find(cur.src)] = find(cur.dest);
            ans = max(ans, cur.dis);
        }
    }
    printf("%d\n", ans);
}

void subway::init()
{
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int subway::find(int index)
{
    if (father[index] == index) {
        return index;
    }
    return (father[index] = find(father[index]));
}