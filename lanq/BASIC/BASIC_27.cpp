//BASIC_27
#include <iostream>
using namespace std;

//复制 n维m数组矩阵，使用动态分配，使用delete_a回收空间。 
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
//删除n维m数组矩阵，保证内存不溢出。 
void delete_a(int **m, const int& n){
	for(int j = 0; j < n; j++)delete[] m[j];
	delete[] m;
}
//排除 m矩阵数组的x，y的行、列、斜 相关 
//为了满足2n皇后，黑皇后点改为 1 
int** change_m(int **m_t, int x, int y, const int& n){	
	int **m = copy_a(n, m_t);
	for( int i = 0; i < n; i++){
		m[i][y] = 0;
		m[x][i] = 0;
		if( (x + i) < n ){	//判断右边界 
			if( (y + i) < n )m[x + i][y + i] = 0;
			if( (y - i) >= 0 )m[x + i][y - i] = 0;
		}
		if( (x - i) >= 0 ){	//判断左边 
			if( (y + i) < n )m[x - i][y + i] = 0;
			if( (y - i) >= 0 )m[x - i][y - i] = 0;
		}	
	}
	m[x][y] = 1; 	//黑皇后的位置 
	return m;
}
//查询n维m矩阵的n皇后问题。 queen为1为n皇后，2为2n皇后问题 
//m_r 用于传递原图，在进入第二层皇后还原图使用 
int search_m(int **m, const int& n, int line, int deep, int queen, int** m_r){
//m为计算矩阵，n:矩阵大小，line：m矩阵计算开始行，deep：当前深度，queen：第n皇后, m_r：原矩阵			
	int sum = 0;
	for(int i = 0; i < n; i++){
		//如果第line行第i列元素可放，尝试放入 
		if( m[line][i] == 1){		
			if(deep == n || line == n - 1){
				//当搜索深度达到最大n时，则成功。返回加一，记录输出。
				if(queen == 2){
					for( int j = 0;j < n;j++){
						for( int k = 0; k < n; k++){
							m[j][k] = m[j][k] ? 0 : 1;
							if(m_r[j][k] == 0)m[j][k] = 0;	//还原第二层图 
						}
					}
					return search_m(m, n, 0, 1, 1, m);
				}
				if(queen == 1){
					return 1;
				}
			}
			int** mx = change_m(m, line, i, n);			
			sum += search_m(mx , n, line + 1, deep + 1, queen, m_r);	//数据累加 
	
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
	cout << search_m(m, n, 0, 1, 2, m);
	delete_a(m, n);	
	return 0;
} 
