//BASIC_27
#include <iostream>
using namespace std;

//���� nάm�������ʹ�ö�̬���䣬ʹ��delete_a���տռ䡣 
int **copy_a(const int& n, int **m_t){
	int **m = new int*[n];
	for(int i = 0; i < n; i++){
		m[i] = new int[n];
		for(int j = 0; j < n; j++){
			m[i][j] = m_t[i][j];
		}
	}
	return m;
}
//ɾ��nάm������󣬱�֤�ڴ治����� 
void delete_a(int **m, const int& n){
	for(int j = 0; j < n; j++)delete[] m[j];
	delete[] m;
}
//�ų� m���������x��y���С��С�б ��� 
int** change_m(int **m_t, int x, int y, const int& n){	
	int **m = copy_a(n, m_t);
	for( int i = 0; i < n; i++){
		m[i][y] = 0;
		m[x][i] = 0;
		if( (x + i) < n ){	//�ж��ұ߽� 
			if( (y + i) < n )m[x + i][y + i] = 0;
			if( (y - i) >= 0 )m[x + i][y - i] = 0;
		}
		if( (x - i) >= 0 ){	//�ж���� 
			if( (y + i) < n )m[x - i][y + i] = 0;
			if( (y - i) >= 0 )m[x - i][y - i] = 0;
		}	
	}
	return m;
}
//��ѯnάm�����n�ʺ����⡣ 
int search_m(int **m, const int& n, int line, int deep){
				
	int sum = 0;
	for(int i = 0; i < n; i++){
		//�����line�е�i��Ԫ�ؿɷţ����Է��� 
		if( m[line][i] == 1){		
			if(deep == n || line == n - 1){
				//��������ȴﵽ���nʱ����ɹ������ؼ�һ����¼����� 
				return 1;
			}
			int** mx = change_m(m, line, i, n);			
			sum += search_m(mx , n, line + 1, deep + 1);	//�����ۼ� 
	
			delete_a(mx, n);
		}
	}
	return sum;
}

int main(){
	int n;
	cin >> n;
	int **m = new int*[n];
	for(int i = 0; i < n; i++){
		m[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin >> m[i][j];
		}
	}
	cout << search_m(m, n, 0, 1);
	delete_a(m, n);	
	return 0;
} 
