#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{
	int n  ;
	cin>> n ;
	int a,max,min,M,m ;
	for(int i=1 ; i<=n ; i++)
	{
		cin>> a ;
		if(i==1)
		{
			max=a ;
			min=a ;
			M=i ;
			m=i ;
		}
		
		else
		{
			if(a>max) {max=a ; M=i ;}
			if(a<=min) {min=a ; m=i ;} // Notice the less than or equal to sign with min and think.
		}
	}
	
	if(M<m) 
	{
		cout<< M-1+n-m ;
	}
	
		if(M>m) 
	{
		cout<< M-2+n-m ;
	}
	
		if(M==m) 
	{
		cout<< "0" ;
	}
	return 0;
}
