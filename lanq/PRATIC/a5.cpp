// 第五讲 
#include <iostream>
using namespace std;

// 1. 最大公约数...辗转相除法 
int gcd(int x, int y){
	
	if( y == 0 )return x;
	return gcd( y , x % y); 

} 

// 2. 最小公倍数
int f(int x, int y){
	return x * y / gcd(x, y);
} 

// 3. 求 a的 n次幂对 p取模 

// 4 . 求第 n个素数是多少 
//    采用筛法 
int whatn(){
	return 0;
}  

// 5. 求 n，m 个包装最大不能买到的个数

// 6. 高僧斗法
//    博弈问题： 尼姆游戏  (使用二进制) 

int main(){
	
	cout << gcd(60, 70);
	return 0;
	
}
