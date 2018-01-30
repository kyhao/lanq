/* 高精度加法 在BASIC_30基础上更新 */ 
/*其中算法可改进*/
#include <iostream>
#include <vector> 
#include <string>
using namespace std;

class b_int{
private:
	int BASE = 10;
	//int WIDTH = 8;
	
public:	
	vector<int> num;
	//b_int(long long value  = 0){ *this = value; }
	
	b_int operator = (const string& value){
		num.clear();
		int f = 0;
		for( int i = (value.length() - 1); i >= 0 ; i--){
			num.push_back(value[i] - '0');
		}
		while(!num[num.size() - 1] && num.size() != 1){
			num.pop_back();
		}
		return *this;
	}
	
	// >>有问题 
	/*
	istream& operator >> (istream &in){
		string s;
		if(!(in >> s)) return in;
		*this = s;
		return in;
	}
	*/
	
	/* 重复运算，该部分可以改进，根据加法部分的代码改进*/ 
	/* 
	b_int operator = (long long value){
		num.clear();
		do{
			num.push_back(value % BASE);
			value /= BASE;
		}while(value > 0);
		return *this;
	}
	
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
			ans.num[i] = t % 10;
			c = t / 10;
		}
		while(c){
			ans.num.push_back(c % 10);
			c /= 10;
		}
		return ans;
	}
	
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
			ans.num[i] = t % 10;
			c = t / 10;
		}
		while(c){
			ans.num.push_back(c % 10);
			c /= BASE;
		}
		return ans;
	}*/ 
	
	/* 技巧非常好 值得学习*/
	b_int operator + (const b_int& v){
		b_int sum;
		sum.num.clear();
		for( int i = 0, c = 0;;i++){
			if(i >= v.num.size() && i >= this->num.size() && c == 0 )break;
			int x = c;
			if(i < this->num.size()) x += this->num[i];
			if(i < v.num.size()) x += v.num[i];
			sum.num.push_back(x % BASE);
			c = x / BASE;
		}
		return sum;
	}
	
};

/*
b_int fac(int n){
	if(n == 0)return b_int(1);
	if(n == 1)return b_int(1);
	return fac(n - 1) * n;
}
*/

int main(){
	string s1, s2;
	b_int x, y, sum;
	cin >> s1 >> s2;
	x = s1;
	y = s2;
	sum = x + y;
	for( int i = (sum.num.size() - 1); i >= 0; i--){
		cout << sum.num[i];
	}
	return 0;
} 
