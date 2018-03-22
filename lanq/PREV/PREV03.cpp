//暴力解决，不管什么数，都需要执行1000万次 
#include <iostream>
using namespace std;

bool num[10];//true: Weixuan; false: Yixuan
int N;

int cal(int x){	
	int a, b, c, t;
	int sum = 0;
	for(int i = 10; i <= 10000000; i *= 10){
		c = x%i; t = x/i;
		for(int j = 10; j <= 10000000; j *= 10){
			a = t/j;
			if(a == 0 )break;
			b = t%j;
			if( b%c == 0 && N == (a + b / c) ){
				sum++;
			}
		}
	}
	return sum;
}

int A_N(int n, int w){
	if(w == 9){
		return cal(n);
	}
	int sum = 0;
	for(int i = 1; i <= 9; i++){
		if(num[i]){
			int t;
			num[i] = false;
			t = n * 10 + i;
			sum += A_N(t, w+1);
			num[i] = true;
		}
	}
	return sum;
} 

int main(){
	for(int i = 0; i < 10; i++)num[i] = true;
	cin >> N;	
	cout << A_N(0, 0);
	return 0;
} 
