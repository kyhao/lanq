//OJ: C++ : 240K 266MS
//OJ: G++ : 720K 360MS
#include <iostream>
using namespace std;

int w, h, sx, sy;
int board[20][20];
int step;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans;

void go(int x, int y){
	if(step > 10)return;
 	for(int i = 0; i < 4; i++){	
		int tx = x, ty = y;
		if(board[x+dx[i]][y+dy[i]] == 1 )continue;
		for(int j = 0; j < 20; j++){
			tx += dx[i]; ty += dy[i];
			if(tx < 0 || ty < 0 || tx >= h || ty >= w)break;
			if(board[tx][ty] == 1){
				board[tx][ty] = 0;
				step++;
				go(tx-dx[i], ty-dy[i]);
				board[tx][ty] = 1;
				step--;
				break;
			}
			if(board[tx][ty] == 3){
				step++;
				if(step < ans)ans = step;
				step--;
				return;
			}
		}
	}
}

void init(){
	step = 0;ans = 99999999;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> board[i][j];
			if(board[i][j] == 2){
				sx = i; sy = j;
			}
		}
	}
} 

int main(){
	ios::sync_with_stdio(false);
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0)break;
		init();
		go(sx, sy);
		if(ans > 10)ans = -1;
		cout << ans << "\n";
	}
	return 0;
}
