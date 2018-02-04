#include <iostream>
#include <vector>
using namespace std;

class b_int{
	
public:	
	b_int(int n = 0){
		num.clear();
		for(;n;){
			num.push_back( n % 1000 );
			n /= 1000;
		}		
	}
	
	b_int operator*(int n){
		b_int ans;
		int c = 0;
		int t;
		for(int i = 0; i < this->num.size(); i++){
			t = num[i] * n + c;
			ans.num.push_back( t % 1000 );
			c = t / 1000;
		}
		while(c){
			ans.num.push_back( c % 1000);
			c /= 1000;
		}
		return ans;
	}
	vector<int> num;
	
};

int main(){
	int n, lol;
	b_int ans;
	cin >> n;
	if( ( n % 2 ) == 0 ){
		lol = 3;
	}else{
		lol = 2;
	}
	b_int num(n);
	ans = num * ( n - 1 ) * ( n - lol );
	for(int i = ans.num.size() - 1; i >= 0; i--){
		if(ans.num[i] < 10)cout << "00";
		else if(ans.num[i] < 100 )cout << "0";
		cout << ans.num[i];
	}
}
