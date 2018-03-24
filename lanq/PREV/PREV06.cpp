#include<iostream>
using namespace std;

char str1[1000];
char str2[1000];
int times = 0;

void change(int i){
	if(str1[i] != '*' && str1[i] != 'o' || i == 999)return;
	if(str1[i] == str2[i]){
		change(i+1);
	}else{
		if(str1[i] == '*')str1[i] = 'o';
		else str1[i] = '*';i++;
		if(str1[i] == '*')str1[i] = 'o';
		else str1[i] = '*';
		times++;
		change(i);
	}
}

int main(){
	cin >> str1 >> str2;
	change(0);
	cout << times;
	return 0;
}
