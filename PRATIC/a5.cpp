// ���彲 
#include <iostream>
using namespace std;

// 1. ���Լ��...շת����� 
int gcd(int x, int y){
	
	if( y == 0 )return x;
	return gcd( y , x % y); 

} 

// 2. ��С������
int f(int x, int y){
	return x * y / gcd(x, y);
} 

// 3. �� a�� n���ݶ� pȡģ 

// 4 . ��� n�������Ƕ��� 
//    ����ɸ�� 
int whatn(){
	return 0;
}  

// 5. �� n��m ����װ������򵽵ĸ���

// 6. ��ɮ����
//    �������⣺ ��ķ��Ϸ  (ʹ�ö�����) 

int main(){
	
	cout << gcd(60, 70);
	return 0;
	
}
