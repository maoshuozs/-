#include<iostream>
using namespace std;
#define MAXNUM 100
//��������ͼ 
typedef struct{
	char Vex[MAXNUM];				//����� 
	int arcs[MAXNUM][MAXNUM];		//�ڽӾ��� 
	int vnum,arcnum;				//ʵ������Ķ������ͱ��� 
}GraphUDG;

int visited[10];					//�����ж��Ƿ񾭹� 
//��λ
int Locate(GraphUDG G,char v){
	for(int i = 0;i < G.vnum;i++){
		if(G.Vex[i] == v){
			return i;
		}
	}
	return -1;
} 

//��������ͼ
int CreateGraph(GraphUDG &G){
	cout << "��������ͼ����������ͼG�Ķ������ͱ�����";
	cin >> G.vnum >> G.arcnum;
	int i,j,k;
	char v1,v2;
	
	//��ʼ������� 
	for(i = 0;i < G.vnum;i++){
		cout << "�������" << i << "�������ֵ��";
		cin >> G.Vex[i];
	}
	
	//��ʼ���ڽӾ��� 
	for(i = 0;i < G.vnum;i++){
		for(j = 0;j < G.vnum;j++){
			G.arcs[i][j] = 0;
		}
	}
	 
	for(k = 0;k < G.arcnum;k++){
		cout << "�������" << k << "���ߵĶ���1 ����2(�Կո���Ϊ���)��";
		cin >> v1 >> v2;
		i = Locate(G,v1);
		j = Locate(G,v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
	}
	return 1;
} 

//��ӡ�������� 
void PrintV(GraphUDG G){
	cout << "��������:" << endl;
	for(int i = 0; i < G.vnum;i++){
		cout << G.Vex[i] << " ";
	}
	cout << endl;
}

//��ӡ�ڽӾ���
void PrintG(GraphUDG G){
	cout << "�ڽӾ���:" << endl;
	int i,j;
	for(i = 0;i < G.vnum;i++){
		for(j = 0;j < G.vnum;j++){
			cout << G.arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
} 

//������ȱ���
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
	int v;							//���ڱ������ĸ����㿪ʼ 
	cout << "--------�����ʾ--------" << endl;
	CreateGraph(G);
	PrintV(G);
	PrintG(G);
	cout << "�����������������ͼ�Ľ����" << endl;
	cin >> v;
	DFS(G,v);
	return 0;
}
