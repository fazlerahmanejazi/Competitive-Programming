#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cout<< 100000 << endl ;
    vector<int> a ;
    for(int i=1 ; i<=100000 ; i++) a.push_back(1000000000-i) ;
    random_shuffle(a.begin(), a.end()) ;
    random_shuffle(a.begin(), a.end()) ;
    random_shuffle(a.begin(), a.end()) ;
    for(int i=0 ; i<99999 ; i++) cout<< a[i] << ' ' ;
    cout<< a[99999] << endl ;
  }
