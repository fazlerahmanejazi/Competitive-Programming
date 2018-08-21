#include <iostream>
#include <string>
using namespace std ;

int main()
{
 int n,m ;
 string x[3000], y[3000], z[3000] ;
 cin>> n >> m ;
 for(int i=0 ; i<m ; i++)
 {
   cin>> x[i] >> y[i] ;
 }
 for(int i=0 ; i<n ; i++)
 {
   cin>> z[i] ;
 }
 int a=0 ;
 while(a<n)
 {
   for(int i=0 ; i<m ; i++)
   { if(x[i]==z[a])
      {
        if(x[i].length()>=y[i].length()) cout<< x[i] << ' ' ;
        else cout<< y[i] << ' ' ;
      }
   }
 }
 return 0;
}
