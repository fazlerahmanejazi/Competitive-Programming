#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n, check, count, temp ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        count=-1 ;
        check=n ;
        vector<int> a(n+1), b(n+1), dump, weight(n+1) ;
        vector<bool> avail(n+1, true) ;
        vector<vector<int > > rows ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> temp ;
            weight[temp]=i+1 ;
          }
        for(int i=0 ; i<n ; i++)
          cin>> b[i] ;
        while(check)
          {
            rows.push_back(dump) ;
            count++ ;
            for(int i=0 ; i<n ; i++)
              {
                if(avail[b[i]])
                  {
                    rows[count].push_back(b[i]) ;
                    avail[b[i]]=false ;
                    temp=weight[b[i]] ;
                    check-- ;
                    for(int j=i+1 ; j<n ; j++)
                      {
                        if(weight[b[j]]>temp && avail[b[j]])
                          {
                            rows[count].push_back(b[j]) ;
                            avail[b[j]]=false ;
                            temp=weight[b[j]] ;
                            check-- ;
                          }
                      }
                    break ;
                  }
              }
          }
        cout<< rows.size() << endl ;
        for(int i=0 ; i<rows.size() ; i++)
          {
            cout<< rows[i].size() ;
            for(int j=0 ; j<rows[i].size() ; j++)
              {
                cout<< " " << rows[i][j] ;
              }
            cout<< endl ;
          }
      }
  }
