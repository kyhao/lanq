#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_ 100100
#define MAX 0x7fffffff
#define max(a,b) ((a>b)?(a):(b))

struct point {
    int u,v,cap;
} edge[MAX_*10];

bool cmp(const point a,const point b){
        return a.cap < b.cap;
}

int d[MAX_], p[MAX_];
int fa[MAX_];

int M, n, m;

void add(int from, int to, int cap) {
    edge[M].u = from;
    edge[M].v = to;
    edge[M].cap = cap * 2 + p[from] + p[to];
    M++;
}

int find(int x){
    if(fa[x] == x)return fa[x];
    return fa[x] = find(fa[x]);
}

void kruscal(){
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
        d[i] = 0;
    }
    int u, v, fu,fv, sum = 0;
    for(int i = 0; i < M; ++i){
        u = edge[i].u;
        v = edge[i].v;      
        fu = find(u);
        fv = find(v);
        if(fu == fv)continue;
        printf("%d -> %d\n", u, v); 
        sum += edge[i].cap;
        fa[fu] = fv;
        d[u] ++;
        d[v] ++;
    }
    int tmp = MAX;
    for(int i = 1; i <= n; ++i){
        if(tmp > p[i])tmp = p[i];
    }
    printf("%d\n",sum + tmp);
}
int main() {
    int i;
    int s,t,c;
    while(~scanf("%d%d",&n,&m)) {
        M = 0;
        for(i = 1; i <= n; ++i ){
            scanf("%d",&p[i]);
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d",&s,&t,&c);
            add(s,t,c);
        }
        sort(edge, edge + M, cmp);
        kruscal();
    }
    return 0;
}
