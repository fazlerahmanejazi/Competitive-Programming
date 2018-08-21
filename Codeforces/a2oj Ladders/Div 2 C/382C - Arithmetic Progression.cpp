#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, d, c, prev ;
    bool check=true ;
    cin>> n ;
    vector<int> a(n) ;
    set<long long int> ans ;
    set<long long int>::iterator it ;
    cin>> a[0] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> a[i] ;
        if(a[i]!=a[i-1]) check=false ;
      }
    if(check && n!=1)
      {
        cout<< 1 << endl << a[0] ;
        return 0 ;
      }
    sort(a.begin(), a.end()) ;
    if(n==1) cout<< -1 ;
    else if(n==2)
      {
        d=a[1]-a[0] ;
        ans.insert(a[0]-d) ;
        ans.insert(a[1]+d) ;
        if(d%2==0) ans.insert((a[0]+a[1])/2) ;
        it=ans.begin() ;
        cout<< ans.size() << endl ;
        while(it!=ans.end())
          {
            cout<< *it << " " ;
            it++ ;
          }
      }
    else
      {
        map<int, bool> taken ;
        prev=d=a[1]-a[0] ;
        taken[d]=true ;
        c=1 ;
        for(int i=2 ; i<n ; i++)
          if(a[i]-a[i-1]!=d && !taken[a[i]-a[i-1]])
            {
              c++ ;
              d=a[i]-a[i-1] ;
              taken[d]=true ;
            }
        if(c>2) cout<< 0 ;
        else if(c==2)
          {
            d=min(prev, d) ;
            for(int i=1 ; i<n ; i++)
              if(a[i]-a[i-1]!=d)
                {
                  a.insert(a.begin()+i, a[i-1]+d) ;
                  prev=a[i-1]+d ;
                  break ;
                }
            for(int i=1 ; i<=n ; i++)
              if(a[i]-a[i-1]!=d)
                {
                  cout<< 0 ;
                  return 0 ;
                }
            cout<< 1 << endl ;
            cout<< prev ;
          }
        else
          {
            cout<< 2 << endl ;
            cout<< a[0]-d << " " << a[n-1]+d ;
          }
      }
  }
