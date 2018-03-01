#include <iostream>
#include <queue>
using namespace std;

#define INF 10000

struct side{						//边 
	int s;						//边的起点 
	int e;						//边的终点 
	int v;						//边的权值 	
	friend bool operator<(side a, side b){	//用于判断优先队列 
		return a.v > b.v;
	}
};

//kruskal算法应用 
priority_queue<side> e;
int kruskal(int* node_val, bool* node_flag, int n){
	int sum = 0;
	bool iscircle = false;	//圆圈标识位 
	int* tree = new int[n+1];	//用于每个节点归属树的标识。
	//for(int j = 0; j < n+1; j++){
	//	tree[j] = -1;
	//}
	for(int i = 0; i < n-1; ){
		//判断是否成环
		//cout << "flag1: " << node_flag[e.top().s] << " " << node_flag[e.top().e] << "\n";
		if( node_flag[e.top().s] || node_flag[e.top().e] ){
			
			if( !node_flag[e.top().s] && node_flag[e.top().e] ){
				tree[e.top().s] = tree[e.top().e];iscircle = false;
			}else
			if( node_flag[e.top().s] && !node_flag[e.top().e] ){
				tree[e.top().e] = tree[e.top().s];iscircle = false;
			}else
			if( node_flag[e.top().s] && node_flag[e.top().e]){
				if( tree[e.top().s] == tree[e.top().e]){
					iscircle = true;
				}else{
					int t1 = tree[e.top().s];
					for(int k1 = 0; k1 < n + 1; k1++){
						if(tree[k1] == t1)tree[k1] = tree[e.top().e];
					}
					iscircle = false;
				}
			}
		}else{
			tree[e.top().s] = i;
			tree[e.top().e] = i;
			iscircle = false;
		}
		//处理成环和不成环结果 
		if(iscircle){	
			//cout << "NO: " << e.top().s << " -> " << e.top().e << " " << e.top().v << "\n";	
			e.pop();
		}else{
			cout << "OK: " << e.top().s << " -> " << e.top().e << " " << e.top().v << "\n";
			sum += node_val[e.top().s] + ( e.top().v * 2 ) + node_val[e.top().e];	//起点值+边权值*2+终点值
			node_flag[e.top().s] = true;		// 标记已选节点
			node_flag[e.top().e] = true;		// 标记已选节点
			//cout << "flag2: " << node_flag[e.top().s] << " " << node_flag[e.top().e] << "\n";
			e.pop();
			i++;
		}
	}
	delete[] tree;
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, min = INF;
	cin >> n >> m;
	//存储点权值 ,点的标记 
	int* node_val = new int[n+1];
	bool* node_flag = new bool[n+1];	//标记加入的点集，用于判断是否成环 
	for(int i = 1; i <= n; i++){
		cin >> node_val[i];
		node_flag[i] = false;
		if( node_val[i] < min) min = node_val[i];
	}
	//存储边的源点和终端和权值
	//priority_queue<side> e;
	side x;
	for(int i = 0; i < m; i++){
		cin >> x.s >> x.e >> x.v;
		e.push(x);
	}	
	cout << kruskal(node_val, node_flag, n) + min;	
	return 0;
} 
