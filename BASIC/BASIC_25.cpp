#include <iostream>
using namespace std; 

int main(){
	int m, n, i, j;
	cin >> m >> n;
	
	//����m��n�е����� 
	int **p = new int*[m];
	for( i = 0; i <= m; i++ ){
		p[i] = new int[n];
	}
	
	//���� 
	for( i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			cin >> p[i][j];
		}		
	}
	
	//��� 
	int size = m * n;
	int l = 1, r = n - 1, t = 0, b = m - 1;	//�������±߽� 
	int x = 0, y = 0, f = 1, start = 1;				//x y �α� f��־λ 
	for( i = 0; i < size; i++){
		cout << p[x][y];
		if( (i + 1) < size)cout << " ";
		if( x == t - 1 && y == l){ f = 1; l++; }	//��1 
		if( x == b && y == l - 1){ f = 2; b--; }	//��2 
		if( x == b + 1 && y == r){ f = 3; r--; }	//��3 
		if( x == t && y == r + 1){ f = 4; t++; }	//��4 
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
