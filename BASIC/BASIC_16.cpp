//分解质因数，注意思想 
#include <iostream>
using namespace std;

void chout(int n){
	cout << n << "=";
    if( n < 2) return;                //小于2的数不合法，若n为质数则输出它本身
    for(int i = 2; i*i<=n; i++)        //根号n复杂度
    {        
        while( n % i == 0 )
        {
            n=n/i;
            cout << i ;
            if( n!=1 )cout << "*";
        }
    }
    if( n != 1 )cout << n;        //当n为质数
}

int main()
{
    int a, b;
    cin >> a >> b;
    for( int i = a; i <= b; i++ ){
    	chout(i);
    	if( i < b)cout << "\n";
    }
    return 0;
}
