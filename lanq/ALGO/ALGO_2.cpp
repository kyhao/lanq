//ALGO_2
//2018-2-10 
#include <iostream>
#include <vector>
using namespace std;
//每一位保存的基数 
#define BASE 1000 
//大数类 
class b_int{	
public:	
	b_int(int n = 0){
		num.clear();
		for(;n;){
			num.push_back( n % BASE );
			n /= BASE;
		}		
	}
	
	b_int operator*(int n){
		b_int ans;
		int c = 0;
		int t;
		for(int i = 0; i < this->num.size(); i++){
			t = num[i] * n + c;
			ans.num.push_back( t % BASE );
			c = t / BASE;
		}
		while(c){
			ans.num.push_back( c % BASE);
			c /= BASE;
		}
		return ans;
	}
	vector<int> num;
	
};

int main(){
	int n, x;
	b_int ans;
	cin >> n;
	//处理三个连续数字 
	if( n%2 ){
		x = 2;
	}else if( n%3 ){
		x = 3;
	}else{
		n = n - 1;
		x = 2;
	}
	//计算乘法 
	b_int num(n);
	ans = num * ( n - 1 ) * ( n - x );
	for(int i = ans.num.size() - 1; i >= 0; i--){
		if(ans.num[i] < 10)cout << "00";
		else if(ans.num[i] < 100 )cout << "0";
		cout << ans.num[i];
	}
	
	return 0; 
}
