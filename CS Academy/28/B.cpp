#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, x, ans, curr, y, res ;
    bool check ;
    cin>> n ;
    vector<int> a ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.push_back(x) ;
      }
    ans=0 ;
    res=1 ;
    curr=a[0] ;
    for(int i=1 ; i<n ; i++)
      {
        curr=curr^a[i] ;
        if(curr!=0) res++ ;
        else
          {
            curr=a[i] ;
            res=1 ;
          }
        ans=max(ans, res) ;
      }
    cout<< ans ;
  }
