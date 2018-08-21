#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, m, k, u, v, x, curr ;
    bool ground=false ;
    cin>> n >> m >> k ;
    vector<bool> hole(n+1, false) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> x ;
        hole[x]=true ;
      }
    curr=1 ;
    if(hole[1]) ground=true ;
    for(int i=0 ; i<k ; i++)
      {
        cin>> u >> v ;
        if(!ground)
          {
            if(curr==u)
              {
                curr=v ;
                if(hole[v]) ground=true ;
              }
            else if(curr==v)
              {
                curr=u ;
                if(hole[u]) ground=true ;
              }
          }
        else break ;
      }
    cout<< curr ;
  }
