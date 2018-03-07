//递归实现
//虽然OJ可以过，但是部分数据不完善 
#include <iostream>
#include <string>
using namespace std;
//预处理位数和字母 
string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string wei[10] = {"", "shi", "bai", "qian", "wan", "shi", "bai", "qian", "yi", "shi"};

void read_out(int n, int wz, int before){
	
	//...
	if(n == 0)return;
	int now = n % 10;
	read_out( n/10 , wz + 1, now);
	if( (before == 0) && ( now == 0) ){
		
	}
	else{
		
		if( now == 1 && ( wz == 5 || wz == 1)){;}
		else {
			if( n/10 )cout << " ";
			cout << num[now];
			cout << " ";
		}
		if(now)cout << wei[wz];
	}
	
	//...
		
}

int main(){
	int x;
	cin >> x;
	read_out(x, 0, 0);
	return 0;
}
