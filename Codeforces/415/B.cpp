#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, f, s, b ;
    long long int ans=0 ;
    cin>> n >> f ;
    vector<pair<long long int, pair<int, int>>> data ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s >> b ;
        data.push_back(make_pair(min(2*s, b), make_pair(s, b))) ;
      }
    sort(data.begin(), data.end()) ;
    reverse(data.begin(), data.end()) ;
    for(int i=0 ; i<n ; i++)
      {
        s=data[i].second.first ; b=data[i].second.second ;
        if(i<f) ans+=min(2*s, b) ;
        else ans+=min(s, b) ;
      }
    cout<< ans ;
  }
