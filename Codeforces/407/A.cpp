#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, k, days, temp ;
    cin>> n >> k ;
    vector<int> pebbles(n) ;
    for(int i=0 ; i<n ; i++)
        cin>> pebbles[i] ;
    temp=0 ;
    for(int i=0 ; i<n ; i++)
        temp+=ceil(float(pebbles[i])/k) ;
    days=((temp+1)/2) ;
    cout<< days ;
  }
