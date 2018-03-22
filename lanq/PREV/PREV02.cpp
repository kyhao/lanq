#include <iostream>
using namespace std;

char k[64][64];
int n, l;
//改变数组函数 
void change(int x, int y, char b_z){
	if(x>l || y >l)return;
	if(b_z == '.'){
		k[x][y] = '$';
		change(x+1, y+1, '$');
	}
	if(b_z == '$'){
		k[x][y] = '.';
		change(x+1, y+1, '.');
	}
}
//输出的代码太丑，可以进行改进 
void show(){
	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= l; j++){
			cout << k[i][j];
		}
		for(int j = 1; j < l; j++){
			cout << k[i][l - j];
		}
		cout << "\n";
	}
	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= l; j++){
			cout << k[l-i][j];
		}
		for(int j = 1; j < l; j++){
			cout << k[l-i][l - j];
		}
		if(i+1 < l)cout << "\n";
	}
}

int main(){
	cin >> n;
	l = 3+2*n;
	for(int i = 1; i <= l; i++){
		change(i, 1, '.');
		change(1, i, '.');
	}
	change(1, 2, '$');
	change(2, 1, '$');
	k[1][1] = '.';
	show();

	return 0;
}
