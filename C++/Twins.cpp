#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    int n ;
    int s[110] ; // As MS Visual C++ does not allow runtime allocation fo array size.
	cin>> n ;
	for(int i=0 ; i<n ; i++ )
	{ cin>> s[i] ;	}
	
	sort(s,s+n) ;
	
	int a,b,c=0 ;
	
	for(int i=0 ; i<n ; i++)
	{ b+=s[i] ;  	}

    for(int i=0 ; i<n ; i++)
    {   a+=s[n-i-1] ;
        b-=s[n-i-1] ;
        c=i+1 ;
        if(a>b) break ;
    	
	}
cout<< c ;
}
