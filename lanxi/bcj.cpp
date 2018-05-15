//并查集实现 
#include<iostream>
using namespace std;

#define MAX_N 1000;

int par[MAX_N];
int rank[MAX_N];

//查询/同时进行简化 
int find(int x){
	if(par[x] == x){
		return x;
	}else {
		return par[x] = find(par[x]);	//递归查询，同时进行路径压缩 
	}
}

//合并x,y节点的所属集合 
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)return;
	
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y])rank[x]++;
	}
	
}

//判断是否属于同集合 
bool same(int x, int y){
	return find(x) == find(y);
} 

int main(){
	
	return 0;
}
