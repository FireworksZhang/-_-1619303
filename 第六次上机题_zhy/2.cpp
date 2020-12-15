
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
 
//哈夫曼树节点类
class hfTNode {
public:
	int weight;//节点的权重
	int ch;//存储节点的下标
	hfTNode* leftchild, * rightchild;//创建该结点的左右孩子指针
	hfTNode() ://哈夫曼树节点类初始化
		leftchild(nullptr), rightchild(nullptr) {}
	hfTNode(int data) ://哈夫曼树节点类初始化
		leftchild(nullptr), rightchild(nullptr), weight(data) {}
	//拷贝构造函数,作为重载运算符“=”使用
	hfTNode(const hfTNode& N) {
		ch = N.ch;
		weight = N.weight;
		if (N.leftchild) {
			leftchild = new hfTNode();
			*leftchild = *(N.leftchild);
		}
		else
			leftchild = nullptr;
		if (N.rightchild) {
			rightchild = new hfTNode();
			*rightchild = *(N.rightchild);
		}
		else
			rightchild = nullptr;
	}
	// 重载"<"符号，令其为最小值优先
	bool operator < (const hfTNode& N) const{
		return weight > N.weight;
	}
};
 
//哈夫曼树类
class Huffman
{
public:
	Huffman(const string &sample);// 构造函数
	~Huffman();// 析构函数
 
	bool IsLeaf(hfTNode* Root);//判断节点是否为叶子结点
	void GetFreq(vector<int> &des);//获取当前的权重数组
	void BuildTree();//构建一颗哈夫曼树
	void BuildCode();//根据哈夫曼树构建编码表
	void GetCodeList();//遍历编码表和编码表对应的编码
 
	//前序遍历和中序遍历是为了确定哈夫曼树的形状是否正确
	void PreOrder();
	void InOrder();
 
	string Expend(const string &des);//解压缩
	string Compress(const string &des);//压缩
	
 
private:
	void _del(hfTNode* root);//删除哈夫曼树
	void _build(hfTNode* root, string str);//生成map的key与value值
	void _PreOrder(hfTNode* root);
	void _InOrder(hfTNode* root);
	unordered_map<char, string> map;//key为编码表的字符，value为编码表的字符对应的编码形式例如“101”，“111”
	vector<int> freq; // 权重数组
	vector<char> st; // 编码表
	
	hfTNode* Root; // 哈夫曼树根节点
};
 
//依据字符串生成编码表以及权重数组
Huffman::Huffman(const string &sample)
{
	int len = sample.length();
	if (len == 0) { cout << "请重新输入字符串" << endl; exit(-1); }
	unordered_map<char, int> mymap;
	for (int i = 0; i < len; ++i) {//依据输入字符串初始化哈希表
		if (mymap.find(sample[i]) == mymap.end())
			mymap[sample[i]] = 1;
		else
			mymap[sample[i]] += 1;
	}
	for (const auto& pair : mymap) {//遍历哈希表，并将key与value分别压入编码表与频率数组中
		//unordered_map<char, int>::const_iterator pair
		st.push_back(pair.first);
		freq.push_back(pair.second);
	}
}
 
//析构函数
Huffman::~Huffman()
{
	_del(Root);
}
//判断节点是否为叶子结点
bool Huffman::IsLeaf(hfTNode* Root)
{
	if(Root==nullptr) return false;
	if (Root->leftchild == nullptr && Root->rightchild == nullptr) 
		return true;
	else 
		return false;
}
 
//获取当前的权重数组
void Huffman::GetFreq(vector<int> &des)
{
	for (int i = 0; i < freq.size(); i++)
		des.push_back(freq[i]);
}
 
//构建一颗哈夫曼树
void Huffman::BuildTree()
{
	priority_queue<hfTNode> myqueue;//使用最小优先级队列存储节点
	for (int i = 0; i < freq.size(); i++){//节点初始化，并将节点压入最小优先级队列中
		hfTNode* temp = new hfTNode(freq[i]);
		temp->ch = i;
		myqueue.push(*temp);
	}
	//合并节点并生成树
	while (myqueue.size() > 1) {
		//从队列中取出两个最小元素作为新子树的左孩子和右孩子
		hfTNode left = myqueue.top();
		myqueue.pop();
		hfTNode right = myqueue.top();
		myqueue.pop();
		//创建新子树的根节点，并将其压入队列中
		hfTNode* parent = new hfTNode(left.weight + right.weight);
		parent->ch = -1;//设定子树生成的根结点下标值是-1，只做区分用
		parent->leftchild = &left;
		parent->rightchild = &right;
		myqueue.push(*parent);
	}
	//生成哈夫曼树的根结点
	Root = new hfTNode();
	*Root = myqueue.top();
	myqueue.pop();
}
 
//根据哈夫曼树构建编码表
void Huffman::BuildCode()
{
	if (Root == nullptr) return;
	//string temp('\0');
	string temp;
	temp.clear();//初始化为空字符串
	_build(Root, temp);
}
 
//遍历编码表和编码表对应的编码
void Huffman::GetCodeList()
{
	for (const auto& pair : map) 
		cout << pair.first << ": " << pair.second << endl;
}
 
void Huffman::PreOrder()
{
	if (Root == nullptr) return;
	_PreOrder(Root);
}
 
void Huffman::InOrder()
{
	if (Root == nullptr) return;
	_InOrder(Root);
}
 
//解压缩
string Huffman::Expend(const string& des)
{
	string res;
	int i(0), n(des.size());
	hfTNode* temp = new hfTNode();
	temp = Root;
	while (i < n) {	
		if (des[i]=='0')
		{
			temp = temp->leftchild;
			i++;
			if (IsLeaf(temp)) {
				res += st[temp->ch];
				temp = Root;
				continue;
			}
		}
		if (des[i] == '1')
		{
			temp = temp->rightchild;
			i++;
			if (IsLeaf(temp)) {
				res += st[temp->ch];
				temp = Root;
				continue;
			}
		}
	}
	return res;
}
 
//压缩
string Huffman::Compress(const string& des)
{
	string res;
	for (int i = 0; i < des.length(); ++i) {
		if (des[i] == '\n'||des[i]==' ')
			continue;
		res += map[des[i]];
	}	
	return res;
}
 
void Huffman::_PreOrder(hfTNode* root)
{
	if (root == nullptr) return;
	cout << root->ch << " :" << root->weight << endl;
	_PreOrder(root->leftchild);
	_PreOrder(root->rightchild);
}
 
 
void Huffman::_InOrder(hfTNode* root)
{
	if (root == nullptr) return;
	_InOrder(root->leftchild);
	cout << root->ch << " :" << root->weight << endl;
	_InOrder(root->rightchild);
}
 
//删除哈夫曼树
void Huffman::_del(hfTNode* root)
{
	if (root == nullptr) 
		return;
	if (root->leftchild) 
		_del(root->leftchild);
	if (root->rightchild) 
		_del(root->rightchild);
}
 
void Huffman::_build(hfTNode* root, string str)
{
	if (IsLeaf(root) && root->ch >= 0) {
		cout << str << "    ";
		map[st[root->ch]] = str;
		return;
	}
	if(root->leftchild) _build(root->leftchild, str + '0');
	if(root->rightchild) _build(root->rightchild, str + '1');
}

int main() {
	string sample = "AAAAACCCCCCBBBBDDDFFE";
	Huffman hf(sample);
	vector<int> des;
	hf.GetFreq(des);
	for (int i = 0; i < des.size(); ++i) {
		cout << des[i] << " ";
	}
	hf.BuildTree();
	cout << endl;
	hf.PreOrder();
	cout << endl << endl;
	hf.InOrder();
	hf.BuildCode();
	cout << endl << endl;
	hf.GetCodeList();
 
	cout << endl << endl;
	string res=hf.Compress(sample);
	cout << hf.Expend(res);
	
	return 0;
}
