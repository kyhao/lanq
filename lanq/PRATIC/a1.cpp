//递归练习 
#include <iostream>
using namespace std;

//输出0-n
void f(int n){
	if(n > 0)f(n - 1);
	cout << n; 
}

//输出begin-end 
void f2(int begin, int end){
	cout << begin;
	if(begin < end) f2( begin + 1, end );
}

//计算数组和 
//1. a[begin] + (begin+1) ... 结束
//2. (a[0]...end-1) + a[end]
//3. 折半求和 mid = (begin + end) / 2 
int sum(int* a, int l){
	if(l == 1) return a[0];
	return sum(a, l - 1) + a[l - 1];
}

int main(){
	//f1(10);
	//f2(2, 10);
	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << sum(x, 10);
	return 0;
}
