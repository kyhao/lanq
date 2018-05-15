#include <iostream>
#include <queue>
using namespace std;

int earth[300][300];
int f[300][300];
int M, Xi, Yi, Ti, step;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
struct Node{
	int x;
	int y;
};
queue<Node> li[2];
bool ok;

void getnext(int x, int y, int t){
	if(t>1)t=0;
	int x1, y1;Node node;
	for(int i = 1; i < 5; i++){
		x1 = x+dx[i]; y1 = y+dy[i];
		if(x1 < 0 || y1 < 0 || x1 >= 300 || y1>=300)continue;
		if(earth[x1][y1] == -1){
			ok = true;
			return;
		}
		if(step+1 < earth[x1][y1] && f[x1][y1] == false){
			f[x1][y1] = true;
			//cout << x << " " << y << "\n";
			node.x = x1; node.y = y1;
			li[t].push(node);
		}
		
	}
}

//广度优先 
void bfs(int t){
	if(t>1)t=0;
	if(ok){
		cout << step;return;
	}
	if(li[t].empty()){
		cout << -1;return;
	}
	Node node;
	while(li[t].size() != 0){
		node = li[t].front();
		li[t].pop();
		getnext(node.x, node.y, t+1);
		if(ok)break;
	}
	step++;
	bfs(++t);
	
}

void init(){
	for(int i = 0; i < 300; i++){
		for(int j = 0; j < 300; j++)earth[i][j] = -1;
	}
	int x1, y1;
	cin >> M;step = 0;
	for(int i = 0; i < M; i++){
		cin >> Xi >> Yi >> Ti;
		for(int j = 0; j < 5; j++){
			x1 = Xi+dx[j]; y1 = Yi+dy[j];
			if(x1<0 || y1 <0 || x1 >= 300 || y1 >=300)continue;
			if( earth[x1][y1] == -1){
				earth[x1][y1] = Ti;
			}else{
				if(Ti < earth[x1][y1])earth[x1][y1] = Ti; 
			}
		}
	}
	Node node;node.x = 0; node.y = 0;
	li[0].push(node);f[0][0] = true;ok = false;
}

int main(){
	ios::sync_with_stdio(false);
	init();
	bfs(0);	
	return 0;
}
