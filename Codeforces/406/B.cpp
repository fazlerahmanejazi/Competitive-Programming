#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, m, k, temp ;
    cin>> n >> m ;
    bool check=true, decide=false ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> k ;
        check=true ;
        map<int, bool> traitor ;
        map<int, bool> prev ;
        for(int j=0 ; j<k ; j++)
          {
            cin>> temp ;
            if(!prev[temp])
              {
                if(traitor[abs(temp)]) check=false ;
                else traitor[abs(temp)]=true ;
                prev[temp]=true ;
              }
          }
        if(check) decide=true ;
      }
    if(decide) cout<< "YES" ;
    else cout<< "NO" ;
    return 0 ;
  }
