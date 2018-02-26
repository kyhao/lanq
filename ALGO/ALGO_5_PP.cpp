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
}Ver[maxn];

void Init()  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
{
    for(int i = 1; i <= n; i++)
    {
        Ver[i].vex = i;
        Ver[i].firarc = NULL;
    }
}

void Insert(int a, int b, int w)  //β�巨��������aΪ��㣬bΪ�յ㣬ȨΪw�ıߣ�Ч�ʲ���ͷ�壬���ǿ���ȥ�ر�
{
    arcnode * q = new arcnode(b, w);
    if(Ver[a].firarc == NULL)
        Ver[a].firarc = q;
    else
    {
        arcnode * p = Ver[a].firarc;
        if(p->vertex == b)
        {
            if(p->weight > w)
                p->weight = w;
            return ;
        }
        while(p->next != NULL)
        {
            if(p->next->vertex == b)
            {
                if(p->next->weight > w)
                    p->next->weight = w;
                return ;
            }
            p = p->next;
        }
        p->next = q;
    }
}
void Insert2(int a, int b, int w)   //ͷ�巨��Ч�ʸ��ߣ�������ȥ�ر�
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

#define INF 0xfffff    //Ȩֵ����
//int parent[maxn];   //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����
//bool visited[maxn]; //�����ж϶����Ƿ��Ѿ������·�����У�����˵�Ƿ����ҵ����·��
//node d[maxn];      //Դ�㵽ÿ�����������룬�����ΪԴ�㵽���ж�������·��
priority_queue<node> q; //���ȶ���stlʵ��
void Dijkstra(int s, int parent[], bool visited[], node d[])    //Dijkstra�㷨������Դ����
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
        if(visited[u])   //ע����һ������⣬����ܶ಻��Ҫ�Ĳ���
            continue;
        visited[u] = true;
        arcnode * p = Ver[u].firarc;
        //�ɳڲ���
        while(p != NULL)    //�������������ڵĶ��㣬�����ɳڲ��������¹�����룬ѹ����С�
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
    int m, a, b, c, st, ed;
    //printf("�����붥�����ͱ�����\n");
    scanf("%d%d", &n, &m);
    //printf("��������Լ�Ȩֵ��a, b, c)\n");
    Init();     //����ǰ�����ʼ��
    int* parent = new int[n+1];
    bool* visited = new bool[n+1];
    node* d = new node[n+1];
    while(m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        Insert2(a, b, c);   //����ͼע��洢������
        Insert2(b, a, c);
    }
    //printf("�����������յ㣺\n");
    //scanf("%d%d", &st, &ed);
    Dijkstra(1, parent, visited, d);
    for(int i = 2; i <= n; i++){
    	printf("%d", d[i].w);
    	if( i+1 <= n)printf("\n");
    }
    /*
    if(d[ed].w != INF)
        printf("���·��ȨֵΪ��%d\n", d[ed].w);
    else
        printf("�����ڴӶ���%d������%d�����·����\n", st, ed);
	*/
    return 0;
}
