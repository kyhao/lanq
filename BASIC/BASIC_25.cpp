#include <iostream>
using namespace std; 

int main(){
	int m, n, i, j;
	cin >> m >> n;
	
	//申请m行n列的数组 
	int **p = new int*[m];
	for( i = 0; i <= m; i++ ){
		p[i] = new int[n];
	}
	
	//输入 
	for( i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			cin >> p[i][j];
		}		
	}
	
	//输出 
	int size = m * n;
	int l = 1, r = n - 1, t = 0, b = m - 1;	//左右上下边界 
	int x = 0, y = 0, f = 1, start = 1;				//x y 游标 f标志位 
	for( i = 0; i < size; i++){
		cout << p[x][y];
		if( (i + 1) < size)cout << " ";
		if( x == t - 1 && y == l){ f = 1; l++; }	//点1 
		if( x == b && y == l - 1){ f = 2; b--; }	//点2 
		if( x == b + 1 && y == r){ f = 3; r--; }	//点3 
		if( x == t && y == r + 1){ f = 4; t++; }	//点4 
		//cout << x << " " << y << "\n";
		//cout << l << " " << r << "\n";
		switch(f){
			case 1: x++; break;
			case 2: y++; break;
			case 3: x--; break;
			case 4: y--; break;
		}
	} 
	
	return 0;
}
