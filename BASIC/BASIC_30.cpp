/* 乘法高精度 */ 
#include <iostream>
#include <vector> 
using namespace std;

class b_int{
private:
	int BASE = 10;
	//int WIDTH = 8;
	
public:	
	vector<long long> num;
	b_int(long long value  = 0){ *this = value; }
	
	/*赋值操作 = */
	b_int operator = (long long value){
		num.clear();
		do{
			num.push_back(value % BASE);
			value /= BASE;
		}while(value > 0);
		return *this;
	}
	
	/* b_int * b_int */ 
	b_int operator * (const b_int& value){
		b_int ans;
		for( int i = 0; i < value.num.size(); i++ ){
			if(ans.num.size()){
				for( int j = 0; j < this->num.size(); j++ ){
					if(j + i < ans.num.size()){
						ans.num[j + i] += this->num[j] * value.num[i];
					}else{
						ans.num.push_back( this->num[j] * value.num[i] );
					}
				}
			}else{
				for( int j = 0; j < this->num.size(); j++){
					ans.num.push_back( this->num[j] * value.num[i] );
				}
			}
		}
		int c = 0;
		int t = 0;
		for( int i = 0; i < ans.num.size(); i++){
			t = c + ans.num[i];
			ans.num[i] = t % BASE;
			c = t / BASE;
		}
		while(c){
			ans.num.push_back(c % BASE);
			c /= BASE;
		}
		return ans;
	}
	
	/* b_int * int */ 
	b_int operator * (int& value){
		b_int ans;
		ans.num.clear(); 
		for( int j = 0; j < this->num.size(); j++){
			ans.num.push_back( this->num[j] * value );
		}	
					
		int c = 0;
		int t = 0;
		for( int i = 0; i < ans.num.size(); i++){
			t = c + ans.num[i];
			ans.num[i] = t % BASE;
			c = t / BASE;
		}
		while(c){
			ans.num.push_back(c % BASE);
			c /= BASE;
		}
		return ans;
	}
	
};

// 阶乘运算 
b_int fac(int n){
	if(n == 0)return b_int(1);
	if(n == 1)return b_int(1);
	return fac(n - 1) * n;
}


int main(){
	int n;
	cin >> n;
	b_int x = fac(n);
	for( int i = (x.num.size() - 1); i >= 0; i--){
		cout << x.num[i];
	}
	return 0;
} 
