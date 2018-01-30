// 第四讲 浮点数注意事项 
#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int i = 3;
	float f = 0.3; 
	float f1 = f / 0;
	cout << (0 - f1) << "\n";
	cout << ( 1 / -f1 );
	return 0;
}
