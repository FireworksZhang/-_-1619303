#include <iostream>
#include <cstdlib>
#include <cstring>
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100   //栈初始化值
#define STACKINCREMENT 10     //栈容量每次增加的值
typedef bool Boolean;
typedef int Status;

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {       //定义链队列
	QueuePtr front;   //队头指针
	QueuePtr rear;	  //队尾指针
}LinkQueue;

Status InitQueue(LinkQueue& Q);
Status EnQueue(LinkQueue& Q, QElemType e);
Status DeQueue(LinkQueue& Q, QElemType& e);
Status QueueEmpty(LinkQueue Q);

/**
 * 构造一个空队列Q
 */
Status InitQueue(LinkQueue& Q)
{
	Q.front = (QNode*)malloc(sizeof(QNode));
	if (!Q.front)
		return ERROR;
	Q.front->next = NULL;
	Q.rear = Q.front;
	return OK;
}

/**
 * 判断Q是否为空, 是返回TRUE，否则返回FALSE
 */
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

Status EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p;
	p = (QNode*)malloc(sizeof(QNode));   //生成新的结点
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

/**
 * 若队列不空，删除队列Q的队头元素，用e返回其值，返回OK，否则返回ERROR
 */
Status DeQueue(LinkQueue& Q, QElemType& e)
{
	QueuePtr p;
	p = Q.front->next;
	if (Q.front == Q.rear)
		return ERROR;
	e = p->data;
	if (Q.front->next == Q.rear)	//队列中只有一个元素时，还要修改尾指针
		Q.rear = Q.front;
	Q.front->next = p->next;
	free(p);
	p = NULL;
	return OK;
}

#define MAX_VERTEX_NUM 20			//图最大顶点个数
typedef enum { DG, DN, UDG, UDN } GraphKind;	//有向图，有向网，无向图，无向网
typedef char InfoType;				//弧相关信息的指针
typedef char VertexType;			//顶点类型


/* 图的数组(邻接矩阵)存储表示 */
#define INFINITY INT_MAX			//最大值
typedef int VRType;				//顶点关系类型，对无权图，用0，1表示相邻否，对带权图，表示权值类型
typedef struct ArcCell {
	VRType	adj;				//权值
	InfoType* info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];	//顶点向量
	AdjMatrix arcs;				//邻接矩阵
	int vexnum, arcnum;			//图的当前顶点数和弧数
	GraphKind kind;				//图的种类标志
}MGraph;

/* 图的邻接表(Adjacency List)存储表示 */
typedef struct ArcNode {
	int adjvex;				//该弧所指向的顶点的位置
	struct ArcNode* nextarc;		//指向下一条弧的指针
	InfoType* info;				//该弧相关信息的指针
}ArcNode;
typedef struct VNode {				//头结点
	VertexType data;			//顶点信息
	ArcNode* firstarc;			//指向依附该顶点的第一条弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;			//存放头结点的数组
	int vexnum, arcnum;			//图的顶点数和弧数
	GraphKind kind;				//图的种类
}ALGraph;

/* 有向图的十字链表(Orthogonal List)表示 */
typedef struct ArcBox {
	int tailvex, headvex;			//该弧的尾和头顶点的位置
	struct ArcBox* hlink, * tlink;		//分别为弧头相同和弧尾相同的弧的链域
	InfoType* info;				//该弧的相关信息指针
}ArcBox;
typedef struct VexNode {			//头结点
	VertexType data;			//顶点信息
	ArcBox* firstin, * firstout;		//分别指向该顶点的第一条入弧和出弧
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];		//表头向量
	int vexnum, arcnum;			//有向图的顶点数和弧数
}OLGraph;

/* 无向图的邻接多重表存储表示形式 */
typedef enum { unvisited, visited } VisitIf;
typedef struct EBox {
	VisitIf mark;				//访问标记
	int ivex, jvex;				//该边依附的两个顶点的位置
	struct EBox* ilink, * jlink;		//分别指向依附这两个顶点的下一条边
	InfoType* info;				//该边信息指针
}EBox;
typedef struct VexBox {
	VertexType data;
	EBox* firstedge;			//指向第一条依附该顶点的边
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];	//无向图顶点向量
	int vexnum, edgenum;			//无向图的当前顶点数和边数
}AMLGraph;

/* 函数声明 */
Status CreateUDN(MGraph& G);
Status CreateDN(MGraph& G);
int LocateVex(MGraph G, VertexType u);
int LocateVex(OLGraph G, VertexType u);
void Input(InfoType*& info);
Status CreateDG(OLGraph& G);
Status CreateDN(ALGraph& G);
Status CreateUDG(ALGraph& G);
Status CreateDG(ALGraph& G);
int FirstAdjVex(ALGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
VertexType GetVex(ALGraph G, int v);


typedef VertexType CSElemType;
typedef struct CSNode {
	CSElemType data;
	struct CSNode* lchild, * nextsibling;
}CSNode, * CSTree;

void DFSTraverse(ALGraph G, Boolean visited[], Status(*Visit)(ALGraph G, int v));
void BFSTraverse(ALGraph G, Boolean visited[], Status(*Visit)(ALGraph G, int v));
void DFS(ALGraph G, int v, Boolean visited[], Status(*Visit)(ALGraph G, int v));
/**
 * 算法7.4，对图G作深度优先遍历, 数组visited为访问标志数组，Visit为访问函数
 */
void DFSTraverse(ALGraph G, Boolean visited[], Status(*Visit)(ALGraph G, int v))
{
	int v;
	for (v = 0; v < G.vexnum; v++) {	//初始化标志数组
		visited[v] = false;
	}
	for (v = 0; v < G.vexnum; v++) {
		if (!visited[v])		//对尚未访问过的结点调用DFS
			DFS(G, v, visited, Visit);
	}
}
void DFS(ALGraph G, int v, Boolean visited[], Status(*Visit)(ALGraph G, int v))
{
	int w;
	visited[v] = true;
	Visit(G, v);		//访问第v个结点
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
		if (!visited[w])
			DFS(G, w, visited, Visit);
	}
}
/**
 * 算法7.6，按广度优先非递归遍历图G，使用辅助队列Q和访问标志数组visited
 */
void BFSTraverse(ALGraph G, Boolean visited[], Status(*Visit)(ALGraph G, int v))
{
	int u, v, w;
	LinkQueue Q;
	InitQueue(Q);

	for (v = 0; v < G.vexnum; v++) {
		visited[v] = false;
	}

	for (v = 0; v < G.vexnum; v++) {
		if (!visited[v]) {
			visited[v] = true;
			Visit(G, v);
			EnQueue(Q, v);
			while (!QueueEmpty(Q)) {
				DeQueue(Q, u);		//附着元素出列并置为u
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
					if (!visited[w]) {
						visited[w] = true;
						Visit(G, w);
						EnQueue(Q, w);
					}
				}
			}
		}
	}
}

/**
 * 算法7.2, 采用数组（邻接矩阵）表示法，构造无向网G
 */
Status CreateUDN(MGraph& G)
{
	int IncInfo;
	int i, j, k;
	VertexType v1, v2;
	VRType w;
	printf("输入顶点数、弧数、弧信息标志（空格分隔）: ");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);	//IncInfo为1表示弧有相关信息
	getchar();	//接收最后的换行符
	printf("输入%d个顶点向量：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {		//构造顶点向量
		scanf("%c", &G.vexs[i]);
		getchar();	//接收最后的换行符
	}
	for (i = 0; i < G.vexnum; i++) {		//初始化邻接矩阵
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	}
	printf("输入%d条边：\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {		//构造邻接矩阵
		printf("输入第%d条边依附的顶点及权值：", k + 1);
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();	//接收最后的换行符
		i = LocateVex(G, v1);			//确定v1,v2在G中的位置
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;			//弧<v1, v2>的权值
		if (IncInfo)				//如果弧有相关信息则输入
			Input(G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];		//置<v1, v2>的对称弧<v2, v1>
	}
	return OK;
}

/**
 * 采用数组（邻接矩阵）表示法，构造有向网G
 */
Status CreateDN(MGraph& G)
{
	int IncInfo;
	int i, j, k;
	VertexType v1, v2;
	VRType w;
	printf("输入顶点数、弧数、弧信息标志（空格分隔）: ");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);	//IncInfo为1表示弧有相关信息
	getchar();	//接收最后的换行符
	printf("输入%d个顶点向量：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {		//构造顶点向量
		scanf("%c", &G.vexs[i]);
		getchar();	//接收最后的换行符
	}
	for (i = 0; i < G.vexnum; i++) {		//初始化邻接矩阵
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j].adj = INFINITY;
			G.arcs[i][j].info = NULL;
		}
	}
	printf("输入%d条边：\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {		//构造邻接矩阵
		printf("输入第%d条边依附的顶点及权值：", k + 1);
		scanf("%c %c %d", &v1, &v2, &w);
		getchar();	//接收最后的换行符
		i = LocateVex(G, v1);			//确定v1,v2在G中的位置
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;			//弧<v1, v2>的权值
		if (IncInfo)				//如果弧有相关信息则输入
			Input(G.arcs[i][j].info);
	}
	return OK;
}

/**
 * 若G中顶点u存在，返回该顶点在图中的位置，否则返回ERROR
 * 即在G的顶点向量中查找u的位置
 */
int LocateVex(MGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vexs[i])
			return i;
	}
	return ERROR;
}

int LocateVex(OLGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.xlist[i].data)
			return i;
	}
	return ERROR;
}

int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data)
			return i;
	}
	return ERROR;
}

/**
 * 输入弧的相关信息
 */
void Input(InfoType*& info)
{
	info = (InfoType*)malloc(50 * sizeof(InfoType));
	printf("输入弧的信息：");
	std::cin >> info;
}

/**
 * 算法7.3，创建十字链表存储表示的有向图
 */
Status CreateDG(OLGraph& G)
{
	int i, j, k, IncInfo;
	VertexType v1, v2;
	ArcBox* p;
	printf("输入有向图顶点数和弧数及弧是否含信息(0/1)：");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	getchar();					//去换行
	printf("输入%d个顶点(空格分隔)：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {			//构造表头向量
		scanf("%c", &G.xlist[i].data);
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
		getchar();
	}
	for (k = 0; k < G.arcnum; k++) {
		printf("输入一条弧的起点的终点：");
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcBox*)malloc(sizeof(ArcBox));
		if (!p)
			return ERROR;
		(*p).headvex = j;
		(*p).tailvex = i;
		(*p).hlink = G.xlist[j].firstin;
		(*p).tlink = G.xlist[i].firstout;
		(*p).info = NULL;
		G.xlist[i].firstout = G.xlist[j].firstin = p;
		if (IncInfo)
			Input((*p).info);
	}
	return OK;
}

/**
 * 创建邻接表存储的无向图
 */
Status CreateUDG(ALGraph& G)
{
	int i, j, k, IncInfo;
	ArcNode* p;
	VertexType v1, v2;
	G.kind = UDG;		//图的种类为无向图
	printf("请输入图的顶点数、弧数及弧信息标志：");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	printf("输入%d条弧\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧：", k + 1);
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		G.vertices[i].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[j].firstarc;
		p->adjvex = i;
		G.vertices[j].firstarc = p;
		if (IncInfo) {
			Input(p->info);
			G.vertices[i].firstarc->info = p->info;
		}
	}

	return OK;
}

/**
 * 创建邻接表存储的有向图
 */
Status CreateDG(ALGraph& G)
{
	int i, j, k, IncInfo;
	ArcNode* p;
	VertexType v1, v2;
	G.kind = DG;		//图的种类为有向图
	printf("请输入有向图的顶点数、弧数及弧信息标志：");
	scanf("%d %d %d", &G.vexnum, &G.arcnum, &IncInfo);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	printf("输入%d条弧（有向）\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧：", k + 1);
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		G.vertices[i].firstarc = p;
		if (IncInfo) {
			Input(p->info);
			G.vertices[i].firstarc->info = p->info;
		}
	}

	return OK;
}

/**
 * 创建邻接表存储的有向网，弧信息即为权值
 */
Status CreateDN(ALGraph& G)
{
	int i, j, k, IncInfo;
	ArcNode* p;
	char value[10];		//权值信息
	VertexType v1, v2;
	G.kind = DG;		//图的种类为有向图
	printf("请输入有向网的顶点数及弧数：");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	printf("输入%d个顶点：", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vertices[i].data);
		getchar();
		G.vertices[i].firstarc = NULL;
	}
	printf("输入%d条弧（有向）\n", G.arcnum);
	for (k = 0; k < G.arcnum; k++) {
		printf("输入第%d条弧及权值(空格分隔)：", k + 1);
		scanf("%c %c %s", &v1, &v2, value);
		getchar();
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			return ERROR;
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		G.vertices[i].firstarc = p;
		G.vertices[i].firstarc->info = (char*)malloc(50 * sizeof(char));
		strcpy(G.vertices[i].firstarc->info, value);
	}

	return OK;
}


/**
 * 邻接表存储表示的无向图G存在，v是G中的顶点
 * 返回指定第v个顶点的第一个邻接顶点的位置，若顶点在G中不存在邻接顶点，返回-1
 */
int FirstAdjVex(ALGraph G, int v)
{
	if (NULL != G.vertices[v].firstarc) {
		return G.vertices[v].firstarc->adjvex;
	}
	else {
		return -1;
	}
}

/**
 * 邻接表存储表示的无向图G存在，v是G中的顶点， w的v的邻接顶点
 * 返回v的下一个(相对于w)的邻接顶点的位置，若w是最后一个，则返回-1
 */
int NextAdjVex(ALGraph G, int v, int w)
{
	ArcNode* p;	//弧指针
	p = G.vertices[v].firstarc;
	while (p) {					//查找w在v的邻接表链表中的位置
		if (p->adjvex == w) {
			p = p->nextarc;
			if (NULL != p) {		//v的下一个（相对于w）邻接点存在
				return p->adjvex;
			}
			else {
				return -1;
			}
		}
		else {
			p = p->nextarc;
		}
	}
}
/**
 * 返回邻接表表示的第v个结点的信息
 */
VertexType GetVex(ALGraph G, int v)
{
	return G.vertices[v].data;
}