//K���� LλK���� 
#include <iostream>
using namespace std;

#define BASE 1000000007 

int cal(const int& k, const int& l, int** n, int col){
	
	//...
	int i, j;
	
	if(col == l){
		int sum = 0;
		for(i = 1; i < k; i++){
			sum = ( sum % BASE + n[i][col - 1] % BASE ) % BASE;
		}
		return sum;	
	}
	for(i = 0; i < k; i++){
		for(j = 0; j < k; j++){
			if( (j-i)!=1 && (i-j)!=1 ){
				n[i][col] = ( n[i][col] % BASE + n[j][col - 1] % BASE ) % BASE;
			} 
		}		
	}

	return cal(k, l, n, col + 1);
	//...
	//return 0;
}

// Lλ K���� 
int main(){
	int K, L, i, j;
	cin >> K >> L;
	
	int** num = new int*[K];
	for(i = 0; i < K; i++){
		num[i] = new int[L];
		for(j = 0; j < L; j++)
		num[i][j] = 0;
	}
	
	for(i = 0; i < K; i++)num[i][0] = 1;
	cout << cal(K, L, num, 1);
	
	return 0;
}

/*
K��L�� 
ÿһ������һ������������λ�� 
�� 8����10�� 
  10 9 8 7 6 5 4 3 2 1 
0                  7 1 
1                  6 1 
2                  6 1 
3                  6 1 
4                  6 1 
5                  6 1 
6                  6 1 
7                  7 1     
ÿһ��λ�ü�¼��һ���Ŀ�����
ÿһ��Ϊһ������Ļ��֣��ʵݹ����Ϊ���� 
*/

