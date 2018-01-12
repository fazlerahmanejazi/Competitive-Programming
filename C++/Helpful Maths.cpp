#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>

using namespace std ;

int main()
{
	string s;
	cin>> s ;
	int x = s.length() ;
	char a[x] ;
	for(int i=0 ; i<x ; i++)
	{  a[i]=s[i] ;
	}
	sort(a,a+x);
	for(int i=x/2 ; i<x ; i++)
	{ cout<< a[i] ;
	if(i<(x-1)) cout<< "+" ;
	}
	return 0 ;
}
