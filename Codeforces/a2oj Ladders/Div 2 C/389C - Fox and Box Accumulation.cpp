#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, c=0, temp ;
    cin>> n ;
    vector<int> a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(a.begin(), a.end()) ;
    list<int> s(a.begin(), a.end()) ;
    list<int>::iterator it ;
    while(!s.empty())
      {
        c++ ;
        it=s.begin() ;
        it=s.erase(it) ;
        temp=1 ;
        while(it!=s.end())
          {
            if(*it>=temp)
              {
                temp++ ;
                it=s.erase(it) ;
              }
            else it++ ;
          }
      }
    cout<< c ;
  }
