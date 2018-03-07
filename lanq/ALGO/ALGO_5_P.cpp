#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define maxn 200001//��󶥵����
int n;       //�������
struct arcnode  //�߽��
{
    int vertex;     //���ͷ������ڵĶ�����
    int weight;     //����������ıߵ�Ȩֵ
    arcnode * next; //ָ����һ���ڽӵ�
    arcnode() {}
    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
};
struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
{
    int vex;    //��ǰ������
    arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
};

void Init(vernode* Ver)  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
{
    for(int i = 1; i <= n; i++)
    {
        Ver[i].vex = i;
        Ver[i].firarc = NULL;
    }
}
void Insert(int a, int b, int w, vernode* Ver)  //ͷ�巨
{
    arcnode * q = new arcnode(b, w);
    if(Ver[a].firarc == NULL)
        Ver[a].firarc = q;
    else
    {
        arcnode * p = Ver[a].firarc;
        q->next = p;
        Ver[a].firarc = q;
    }
}
struct node     //����ڵ㣬����id�͵�Դ����Ĺ�����룬���ȶ�����Ҫ������
{
    int id;     //Դ����id�͹������
    int w;
    friend bool operator<(node a, node b)   //��Ҫʵ����С�ѣ����������У������Ҫ������������ض������ȼ�����СΪ��
    {
        return a.w > b.w;
    }
};

#define INF 0xfffff
priority_queue<node> q;
void Dijkstra(int s, int parent[], bool visited[], node d[], vernode* Ver)    //Dijkstra�㷨������Դ����
{
    for(int i = 1; i <= n; i++) //��ʼ��
    {
        d[i].id = i;
        d[i].w = INF;           //���������INF
        parent[i] = -1;         //ÿ�����㶼�޸��׽ڵ�
        visited[i] = false;     //��δ�ҵ����·
    }
    d[s].w = 0;                 //Դ�㵽Դ�����·ȨֵΪ0
    q.push(d[s]);               //ѹ�������
    while(!q.empty())           //�㷨�ĺ��ģ����п�˵������˲���
    {
        node cd = q.top();      //ȡ��С������붥��
        q.pop();
        int u = cd.id;
        if(visited[u])   //����ܶ಻��Ҫ�Ĳ���
            continue;
        visited[u] = true;
        arcnode * p = Ver[u].firarc;
        while(p != NULL)    //�����ɳڲ�����
        {
            int v = p->vertex;
            if(!visited[v] && d[v].w > d[u].w+p->weight)
            {
                d[v].w = d[u].w+p->weight;
                parent[v] = u;
                q.push(d[v]);
            }
            p = p->next;
        }
    }
}

int main()
{
    int m, a, b, c;
    scanf("%d%d", &n, &m);
	vernode* Ver = new vernode[n+1];
    Init(Ver);
    int* parent = new int[n+1];
    bool* visited = new bool[n+1];
    node* d = new node[n+1];     
    while(m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        Insert(a, b, c, Ver);
    }
    Dijkstra(1, parent, visited, d, Ver);
    for(int i = 2; i <= n; i++){
    	printf("%d", d[i].w);
    	if( i+1 <= n)printf("\n");
    }
    return 0;
}
