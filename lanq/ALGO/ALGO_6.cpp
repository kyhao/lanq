#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_Node 10001
#define MAX_Edge 100001

struct E{
	int s;
	int e;
	int val;
}edge[MAX_Edge];
int node[MAX_Node][3];	//[][0]:值; [][1]使用标记; [][2]所属树; 
int n, p;

bool cmp(const E &a, const E &b){
	return a.val < b.val;
}

int kruscal(){
	int sum = 0;
	sort(edge+1, edge+p+1, cmp);
	for(int i = 1, ne = 1; ne < n; i++){		
		if( node[edge[i].s][1] == 0 && node[edge[i].e][1] == 0 ){
			node[edge[i].s][1] = 1;
			node[edge[i].e][1] = 1;
			node[edge[i].e][2] = node[edge[i].s][2];
		}else if( node[edge[i].s][1] == 1 && node[edge[i].e][1] == 0 ){
			node[edge[i].e][1] = 1;
			node[edge[i].e][2] = node[edge[i].s][2];
		}else if( node[edge[i].s][1] == 0 && node[edge[i].e][1] == 1 ){
			node[edge[i].s][1] = 1;
			node[edge[i].s][2] = node[edge[i].e][2];
		}else if( node[edge[i].s][1] == 1 && node[edge[i].e][1] == 1 ){			
			if( node[edge[i].s][2] != node[edge[i].e][2] ){
				int temp = node[edge[i].s][2];
				for(int j = 1; j <= MAX_Node; j++){								//太耗时 
					if( node[j][2] == temp)node[j][2] = node[edge[i].e][2];
				};
			}else{
				continue;
			}
		}
		sum += edge[i].val;
		ne++;
	}
	return sum;
}

int main(){
	int min = 2000;
	int temp;
	ios::sync_with_stdio(false);
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		cin >> node[i][0];
		node[i][2] = i;node[i][1] = 0;
		if(node[i][0]<min)min = node[i][0];
	}
	for(int i = 1; i <= p; i++){
		cin >> edge[i].s >> edge[i].e >> temp;
		edge[i].val = node[edge[i].s][0] + node[edge[i].e][0] + temp*2;
	}
	cout << kruscal() + min;
	return 0;
} 
