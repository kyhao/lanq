#include <iostream>
using namespace std;

int main(){
	int n, m, i, j, k, x, sum[30];
	cin >> n >> m;
	//��̬����ռ�洢����matrix��ans 
	int **matrix = new int*[n];
	int **ans = new int*[n];
	for( i = 0; i < n; i++ ){
		matrix[i] = new int[n];
		ans[i] = new int[n];
		for( j = 0; j < n; j++ ){
			cin >> matrix[i][j];
			ans[i][j] = 0;
		}
		ans[i][i] = 1;
	}
	//���� m���� 
	for( k = 0; k < m; k++){
		//һ�γ˷� n�� * n�� 
		 for( i = 0; i < n; i++){
		 	for( j = 0; j < n; j++){
				//����������30 
				 sum[j] = 0;
				 for( x = 0; x < n; x++){
				 	sum[j] += ( ans[i][x] * matrix[x][j] );
				 }
				 //ans[i][j] = sum; 
		 	}
		 	for( j = 0; j < n; j++){
		 		ans[i][j] = sum[j];
		 	}
		 } 
	}
	//������
	for( i = 0; i < n; i++ ){
		for( j = 0; j < n; j++ ){
			cout << ans[i][j];
			if(( j + 1) < n)cout << " ";
		}
		if( (i + 1) < n)cout << "\n";
	}
	return 0;
}
