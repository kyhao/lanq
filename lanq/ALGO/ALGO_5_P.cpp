#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define maxn 200001//最大顶点个数
int n;       //顶点个数
struct arcnode  //边结点
{
    int vertex;     //与表头结点相邻的顶点编号
    int weight;     //连接两顶点的边的权值
    arcnode * next; //指向下一相邻接点
    arcnode() {}
    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
};
struct vernode      //顶点结点，为每一条邻接表的表头结点
{
    int vex;    //当前定点编号
    arcnode * firarc;   //与该顶点相连的第一个顶点组成的边
};

void Init(vernode* Ver)  //建立图的邻接表需要先初始化，建立顶点结点
{
    for(int i = 1; i <= n; i++)
    {
        Ver[i].vex = i;
        Ver[i].firarc = NULL;
    }
}
void Insert(int a, int b, int w, vernode* Ver)  //头插法
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
struct node     //顶点节点，保存id和到源顶点的估算距离，优先队列需要的类型
{
    int id;     //源顶点id和估算距离
    int w;
    friend bool operator<(node a, node b)   //因要实现最小堆，按升序排列，因而需要重载运算符，重定义优先级，以小为先
    {
        return a.w > b.w;
    }
};

#define INF 0xfffff
priority_queue<node> q;
void Dijkstra(int s, int parent[], bool visited[], node d[], vernode* Ver)    //Dijkstra算法，传入源顶点
{
    for(int i = 1; i <= n; i++) //初始化
    {
        d[i].id = i;
        d[i].w = INF;           //估算距离置INF
        parent[i] = -1;         //每个顶点都无父亲节点
        visited[i] = false;     //都未找到最短路
    }
    d[s].w = 0;                 //源点到源点最短路权值为0
    q.push(d[s]);               //压入队列中
    while(!q.empty())           //算法的核心，队列空说明完成了操作
    {
        node cd = q.top();      //取最小估算距离顶点
        q.pop();
        int u = cd.id;
        if(visited[u])   //避免很多不必要的操作
            continue;
        visited[u] = true;
        arcnode * p = Ver[u].firarc;
        while(p != NULL)    //进行松弛操作。
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
