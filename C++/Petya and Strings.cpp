#include<iostream>

using namespace std ;

int main()
{
	string a,b ;
	cin>> a >> b ;
	int p=0 ;
	
	for(int i=0 ; i<a.length() ; i++)
	{
		a[i]=tolower(a[i]);
		b[i]=tolower(b[i]);		
	}
	
	for(int i=0 ; i<a.length() ; i++)
	{
		if((int)a[i]>(int)b[i]) p++ ;
		if((int)b[i]>(int)a[i]) p-- ;		
	}
	
if(p>0) cout<< "1"	;
if(p<0) cout<< "-1" ;
if(p==0) cout<< "0" ;
	
return 0 ;	
	
}
