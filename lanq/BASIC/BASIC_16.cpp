//�ֽ���������ע��˼�� 
#include <iostream>
using namespace std;

void chout(int n){
	cout << n << "=";
    if( n < 2) return;                //С��2�������Ϸ�����nΪ���������������
    for(int i = 2; i*i<=n; i++)        //����n���Ӷ�
    {        
        while( n % i == 0 )
        {
            n=n/i;
            cout << i ;
            if( n!=1 )cout << "*";
        }
    }
    if( n != 1 )cout << n;        //��nΪ����
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
