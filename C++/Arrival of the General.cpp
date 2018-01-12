#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{
	int n ;
	cin>> n ;
	int a[n] ;

	for(int i=0 ; i<n ; i++)
	{
		cin>> a[i] ;
	}
	
	int min=101, max=0 ;
	int m,M ;
	
	for(int i=0 ; i<n ; i++)
	{
		if(a[i]>max) {	max=a[i] ; M=i+1 ;}
		if(a[i]<min) {	min=a[i] ; m=i+1 ;}
	}
	
	if(M<m) 
	{
	    M=M-1 ; m=n-m ;
	    cout<< M+m ;
	}
	
	if(M>m) 
	{
	   M=M-1 ; m=n-m ;
	   cout<< M+m-1 ;
	}
	
	if(M==m) cout<< 0 ;
	
	return 0;
}
