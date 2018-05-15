//���鼯ʵ�� 
#include<iostream>
using namespace std;

#define MAX_N 1000;

int par[MAX_N];
int rank[MAX_N];

//��ѯ/ͬʱ���м� 
int find(int x){
	if(par[x] == x){
		return x;
	}else {
		return par[x] = find(par[x]);	//�ݹ��ѯ��ͬʱ����·��ѹ�� 
	}
}

//�ϲ�x,y�ڵ���������� 
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

//�ж��Ƿ�����ͬ���� 
bool same(int x, int y){
	return find(x) == find(y);
} 

int main(){
	
	return 0;
}
