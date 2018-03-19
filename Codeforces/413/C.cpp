#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, c, d, b, p ;
    vector<int> beauty ;
    pair<int, int> temp ;
    double x ;
    char t ;
    cin>> n >> c >> d ;
    vector<pair<double, pair<int, int>>> C, D ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> b >> p >> t ;
        x=(double)p/b ;
        if(t=='C') C.push_back(make_pair(x, make_pair(b, p))) ;
        else D.push_back(make_pair(x, make_pair(b, p))) ;
      }
    sort(C.begin(), C.end()) ;
    sort(D.begin(), D.end()) ;
    for(int i=0 ; i<C.size() ; i++)
      {
        temp=C[i].second ;
        if(temp.second<=c)
          {
            beauty.push_back(temp.first) ;
            c=c-temp.second ;
          }
      }
    for(int i=0 ; i<D.size() ; i++)
      {
        temp=D[i].second ;
        if(temp.second<=d)
          {
            beauty.push_back(temp.first) ;
            d=d-temp.second ;
          }
      }
    sort(beauty.begin(), beauty.end()) ;
    if(beauty.size()<2) cout<< 0 ;
    else cout<< beauty[beauty.size()-1]+beauty[beauty.size()-2] ;
  }
