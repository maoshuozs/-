#include<iostream>
using namespace std;
#define MAXNUM 100
//定义无向图 
typedef struct{
	char Vex[MAXNUM];				//顶点表 
	int arcs[MAXNUM][MAXNUM];		//邻接矩阵 
	int vnum,arcnum;				//实际输入的顶点数和边数 
}GraphUDG;

int visited[10];					//负责判断是否经过 
//定位
int Locate(GraphUDG G,char v){
	for(int i = 0;i < G.vnum;i++){
		if(G.Vex[i] == v){
			return i;
		}
	}
	return -1;
} 

//创建无向图
int CreateGraph(GraphUDG &G){
	cout << "创建无向图请输入无向图G的顶点数和边数：";
	cin >> G.vnum >> G.arcnum;
	int i,j,k;
	char v1,v2;
	
	//初始化顶点表 
	for(i = 0;i < G.vnum;i++){
		cout << "请输入第" << i << "个顶点的值：";
		cin >> G.Vex[i];
	}
	
	//初始化邻接矩阵 
	for(i = 0;i < G.vnum;i++){
		for(j = 0;j < G.vnum;j++){
			G.arcs[i][j] = 0;
		}
	}
	 
	for(k = 0;k < G.arcnum;k++){
		cout << "请输入第" << k << "条边的顶点1 顶点2(以空格作为间隔)：";
		cin >> v1 >> v2;
		i = Locate(G,v1);
		j = Locate(G,v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
	}
	return 1;
} 

//打印顶点数组 
void PrintV(GraphUDG G){
	cout << "顶点数组:" << endl;
	for(int i = 0; i < G.vnum;i++){
		cout << G.Vex[i] << " ";
	}
	cout << endl;
}

//打印邻接矩阵
void PrintG(GraphUDG G){
	cout << "邻接矩阵:" << endl;
	int i,j;
	for(i = 0;i < G.vnum;i++){
		for(j = 0;j < G.vnum;j++){
			cout << G.arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
} 

//深度优先遍历
void DFS(GraphUDG G,int v){
	int i;
	cout << G.Vex[v] << " ";
	visited[v] = 1;
	for(i = 0;i < G.vnum;i++){
		if(G.arcs[v][i] != 0 && (!visited[i])){
			DFS(G,i);
		}
	}
} 

int main(){
	GraphUDG G;
	int v;							//用于遍历从哪个顶点开始 
	cout << "--------数组表示--------" << endl;
	CreateGraph(G);
	PrintV(G);
	PrintG(G);
	cout << "深度优先搜索该无向图的结果：" << endl;
	cin >> v;
	DFS(G,v);
	return 0;
}
