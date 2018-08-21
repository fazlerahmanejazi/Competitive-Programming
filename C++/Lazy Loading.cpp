#include <bits/stdc++.h>
using namespace std ;

int main()
{ ifstream file;
  file.open("lazy_loading.txt");
  ofstream file2;
  file2.open("output.txt") ;
  ios_base::sync_with_stdio (false) ;
  int T, n, k, count, L, U ;
  file>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  { count=0 ;
    file>> n ;
    int items[n] ;
    for(int i=0 ; i<n ; i++)
     file>> items[i] ;
    sort(items, items+n) ;
    U=n-1 ;
    L=0 ;
    while(U>=L)
    {
      if(50%items[U]==0) k=(50/items[U])-1 ;
      else k=50/items[U] ;

      if(k+1<=U-L+1)
      {
        count++ ;
        L=L+k ;
        U=U-1 ;
      }
      else break ;
    }
    file2<< "Case #"<<tc<< ": " << count << endl ;
  }
 return 0 ;
}
