//�ݹ龭������ 
#include <iostream>
#include <string>
using namespace std;

int max(int x, int y){
	return x > y ? x : y;
}

//1. ��n������ȡm�������Żأ��ж�������
int f(int n, int m){
	if(n < m) return 0;
	if(n == m) return 1;
	if(m == 0) return 1;
	
	return f(n - 1, m - 1) + f(n - 1, m);//�ֽ��������� 
} 

//2. ��n��Ԫ�ص�ȫ���� �磺����abc ��� abc acb bac bca cab cba 
//�Ƚ�����Ȼ��ֲ����󲻳��������� 
void f2(string s, int k){
	char t;
	for( int i = k; i < s.length(); i++ ){	
		t = s[k];
		s[k] = s[i];
		s[i] = t;
		f2(s, k + 1);
		if( (k + 1) == s.length() )cout << s << "\n";	
	}	
} 

//3. ������������󹫹������еĳ��� 
//�ɼ��㣬���ǿ����͵ͣ���Ҫ�Ż� 
int f3(string s1, string s2){
	
	//...
	if( s1.length() == 0 || s2.length() == 0 )return 0;
	if(s1[0] == s2[0])return f3( s1.substr(1), s2.substr(1) ) + 1;
	else {
		return max(f3( s1.substr(1), s2 ), f3( s1, s2.substr(1) ));
	}
	//...
	
}

//main
int main(){
	int n;
	//n = f(10, 3);					//1 
	//f2("abcd", 0);				//2 
	n = f3("kabcdefg", "xacdfg");	//3 
	cout << n; 
	return 0;
}
