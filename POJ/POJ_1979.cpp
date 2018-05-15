//OJ: G++ : 732K 32MS
//OJ: C++ : 240K 47MS
#include <iostream>
#include <vector>
using namespace std;

int W, H, sx, sy;
char room[20][20];
bool used[20][20];
char dx[] = {0, 0, 1, -1};
char dy[] = {1, -1, 0, 0};
int sum;

void search(int x, int y){
	if(x<0 || y<0 || x >= H || y >= W)return;
	if(used[x][y] == true)return;
	if(room[x][y] == '#')return;
	sum++;
	used[x][y] = true;
	for(int i = 0; i < 4; i++){
		search(x+dx[i], y+dy[i]);
	}
}

void init(){
	sum = 0;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> room[i][j];
			used[i][j] = false;
			if(room[i][j] == '@'){
				sx = i;sy =j;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	while(1){
		cin >> W >> H;
		if(W == 0 && H == 0)break;
		init();
		search(sx, sy);
		cout << sum << "\n";
	}
	
	return 0;
}
