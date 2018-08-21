#include<iostream>
#include<string>
#include<cstdio>

using namespace std ;

int main()
{
	string a,b ;
	cin>> a >> b ;
	int p=0, q=0 ;
	
	for(int i=0 ; i<a.length() ; i++)
	{
		a[i]=tolower(a[i]);
		b[i]=tolower(b[i]);		
	}
	
if(a.compare(b)>0) cout<< "1" ;
else if(b.compare(a)>0) cout<< "-1" ;
	 else cout<< "0" ;
	
return 0 ;	
	
}
