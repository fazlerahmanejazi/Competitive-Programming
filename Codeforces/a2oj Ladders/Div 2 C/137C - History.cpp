#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, a, b, c=0, maxM ;
    vector<pair<int, int>> date ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b ;
        date.push_back(make_pair(a, b)) ;
      }
    sort(date.begin(), date.end()) ;
    maxM=date[0].second ;
    for(int i=1 ; i<n ; i++)
      {
        if(date[i].second<maxM) c++ ;
        else maxM=date[i].second ;
      }
    cout<< c ;
  }
