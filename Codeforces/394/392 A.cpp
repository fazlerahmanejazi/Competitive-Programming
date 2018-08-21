#include <bits/stdc++.h>
 using namespace std ;

 int main()
 {
   ios_base::sync_with_stdio (false) ;
   int a, b ;
   cin>> a >> b ;
   if(a==0 && b==0) { cout<<"NO" ; return 0 ; }
   if(abs(b-a)>1) cout<< "NO" ;
   else cout<< "YES" ;
   return 0 ;
 }
