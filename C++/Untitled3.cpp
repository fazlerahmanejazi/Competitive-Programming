#include <bits/stdc++.h>
using namespace std ;

int main()
{ ifstream file;
  file.open("lazy_loading.txt");
  ofstream file2;
  file2.open("output2.txt") ;
  ios_base::sync_with_stdio (false) ;
  int T, n, k, count ;
  file>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  { count=0 ;
    file>> n ;
    vector<int> items(n) ;
    for(int i=0 ; i<n ; i++)
     file>> items[i] ;
    sort(items.begin(), items.end()) ;
    while(1)
    {
      if(50%items[items.size()-1]==0) k=(50/items[items.size()-1])-1 ;
      else k=50/items[items.size()-1] ;

      if(k+1<=items.size())
      {
        count++ ;
        items.erase(items.begin(), items.begin()+k) ;
        items.pop_back() ;
      }
      else break ;
    }
    file2<< "Case #"<<tc<< ": " << count << endl ;
  }
 return 0 ;
}
