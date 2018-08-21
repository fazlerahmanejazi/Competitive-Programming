#include <iostream>
using namespace std;

int main()
{  int x, y ;
   int n ;
   int dx, dy;
   while(1)
  { cin>> n ;
 	if(n==0) break ;
 	cin>> dx >> dy ;
 	for(int i ; i<n ; i++)
 	 { 	cin>> x >> y ;
 		if(x==dx || y==dy) cout<< "divisa" ;
 		if(x>dx) { if(y>dy) cout<< "NE" ;
 		           else cout<< "SE" ; }
		else {     if(y<dy) cout<< "SO" ;
 		           else cout<< "NO" ; }
   } }   return 0; }
   
