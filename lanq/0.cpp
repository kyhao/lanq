#include<bits/stdc++.h>  
using namespace std;  
int a[8];  
int main()  
{  
    int cnt = 0;  
    for(int i = 0;i < 8;i ++)  
    a[i] = i + 1;  
    do{  
        int t1,t2,t3,t4;  
        int q1,q2,q3,q4;  
        t1 = a[0] * 10 + a[1];  
        t2 = a[2] * 10 + a[3];  
        t3 = a[4] * 10 + a[5];  
        t4 = a[6] * 10 + a[7];  
          
        q1 = a[1] * 10 + a[0];  
        q2 = a[3] * 10 + a[2];  
        q3 = a[5] * 10 + a[4];  
        q4 = a[7] * 10 + a[6];  
        if((t1*t1 + t2*t2 + t3*t3 + t4*t4) == (q1*q1 + q2*q2 + q3*q3 + q4*q4))  {
        	cout << a[0]<< " " << a[1] << "\n"; 
        	cnt ++;
        }  
         
    }while(next_permutation(a,a+8));  
    cout << cnt / 48;  
    return 0;  
}  
