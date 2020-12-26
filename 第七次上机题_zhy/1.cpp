#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int GRASIZE;
struct GraphNode
{
 int label;
 vector<GraphNode*> neighbors;
 GraphNode(int x) :label(x) {};
};

class GraphOrder {
public:
    	//深度优先遍历
	static void DFS_gra(GraphNode* graph[])
  	{
     		int visit[GRASIZE] = { 0 };

     		for (int i = 0; i < GRASIZE; i++)
     		{
       			if (visit[i]==0)
       			{
            			DFS_i(graph[i],visit);
       			}
     		}
  	}
	//广度优先遍历
 	static void BFS_gra(GraphNode* graph[])
 	{
  		int visit[GRASIZE] = { 0 };
  		for (int i = 0; i < GRASIZE; i++)
  		{
   			if (visit[i] == 0)
   			{
    			BFS_i(graph[i], visit);
   			}
  		}
 	}
 private:
 	//递归
 	static void DFS_i(GraphNode* node,int visit[]) {
  		visit[node->label] = 1;
  		cout << node->label << " ";
  		for (int i = 0; i < node->neighbors.size(); i++)
  		{
   			if (visit[node->neighbors[i]->label]==0)
   			{
    				DFS_i(node->neighbors[i],visit);
   			}
  		}
 	}
 	//队列实现
 	static void BFS_i(GraphNode* node, int visit[]) {
  		queue<GraphNode*> Q;
  		Q.push(node);
  		visit[node->label] = 1;
  		while (!Q.empty()) {
   			GraphNode* node = Q.front();
   			Q.pop();
   			cout << node->label << " ";
   			for (int i = 0; i < node->neighbors.size(); i++)
   			{
    				if (visit[node->neighbors[i]->label]==0)
    				{
     					Q.push(node->neighbors[i]);
     					visit[node->neighbors[i]->label] = 1;
    				}
   			}
  		}
 	}
};

int main()
{
    cout << "请输入顶点个数：";
    cin >> GRASIZE;
    GraphNode* graph[GRASIZE];
	int EDGESIZE,FirstNode,LastNode;
	cout << "请输入边数：";
	cin >> EDGESIZE;
	for (int i = 0; i < GRASIZE; i++)
	{
		graph[i] = new GraphNode(i);
	}
	for (int i = 1; i <= EDGESIZE; i++)
	{
		cout << "请输入起点和终点：";
		cin >> FirstNode >> LastNode;
 		graph[FirstNode]->neighbors.push_back(graph[LastNode]);
	}
	/*
 	graph[0]->neighbors.push_back(graph[2]);
 	graph[0]->neighbors.push_back(graph[4]);
 	graph[1]->neighbors.push_back(graph[0]);
 	graph[1]->neighbors.push_back(graph[2]);
 	graph[2]->neighbors.push_back(graph[3]);
 	graph[3]->neighbors.push_back(graph[4]);
 	graph[4]->neighbors.push_back(graph[3]);
	*/
	cout << "深度优先遍历:";
	GraphOrder::DFS_gra(graph);
 	cout << endl;

 	cout << "广度优先遍历:";
 	GraphOrder::BFS_gra(graph);

	for (int i = 0; i < GRASIZE; i++)
 	{
  		delete graph[i];
 	}

 	return 0;
}