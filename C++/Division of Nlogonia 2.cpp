#include <iostream>
using namespace std;

int main()
{  int x, y ;
   int n ;
   int dx, dy;
   cin>> n;
   while(n!=0)
  {
 	cin>> dx >> dy ;
 	for(int i ; i<n ; i++)
 	 { 	cin>> x >> y ;
 		if(x==dx || y==dy) cout<< "divisa" ;
 		if(x>dx) { if(y>dy) cout<< "NE" ;
 		           else cout<< "SE" ; }
		else {     if(y<dy) cout<< "SO" ;
 		           else cout<< "NO" ; }
   } cin>> n ;
 }   return 0; }
