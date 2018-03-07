//递归经典问题 2 
//没有考虑效率 
#include <iostream>
#include <string>
using namespace std;

// 1. 求反串 
void f1(string s1){
	
	if( s1.length() == 0 )return ;
	f1( s1.substr(1) );
	cout << s1[0];
	
} 

// 2. 求杨辉三角第 m 层 第 n 个元素是什么。
int f2(int m, int n){
	
	if( m == 0 ) return 1;
	if( n == 0 || m == n) return 1;
	return f2( m - 1 , n) + f2( m - 1 , n - 1);
	
}  

// 3. 3个A 2个B 有多少种排列 
int f3(int a, int b){
	//...
	if(a == 0 || b == 0)return 1;
	return f3( a - 1, b) + f3( a, b - 1);
	//...
} 

// 4. 整数划分问题
// 重点！！！！！！！！！！！！！！！！！！！ 
void f4(int n, int* a, int c){
	
	if( n == 0){
		for(int i = 0; i < c; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = n; i > 0; i--){
		if( c > 0 && i > a[c-1]) continue;
		a[c] = i;
		f4(n - i, a, c + 1);
	}
			
} 

// 5. 公司记账问题 

int main(){
	string s = "abcdef";
	int ans = 0;
	int a[100];
	//f1(s);
	//ans = f2(3, 2);
	//ans = f3(3, 2);
	f4(6, a, 0);
		
	//cout << ans;
	return 0;
}
