#include <bits/stdc++.h>
using namespace std ;

#define f first ;
#define s second ;
using pii = pair<int, int> ;
using vi = vector<int> ;

int main()
 {
  ios_base::sync_with_stdio (false) ;
  int T, c, n, k, m, temp, a, b, visit ;
  cin>> T ;
  while(T--)
    {
      cin>> n >> k ;
      vector<pii> data ;
      vector<vi> islands(n+1) ;
      vector<bool> ingredients(k+1, false) ;
      c=visit=0 ;
      for(int i=0 ; i<n ; i++)
        {
          cin>> m ;
          data.push_back(make_pair(m, i+1)) ;
          for(int j=0 ; j<m ; j++)
            {
              cin>> temp ;
              islands[i+1].push_back(temp) ;
            }
        }
      sort(data.begin(), data.end()) ;
      reverse(data.begin(), data.end()) ;
      for(int i=0 ; i<n ; i++)
        {
          a=data[i].s ;
          bool check=true ;
          visit++ ;
          for(int j=0 ; j<islands[a].size() ; j++)
            {
              b=islands[a][j] ;
              if(!ingredients[b])
                {
                  ingredients[b]=true ;
                  check=false ;
                  c++ ;
                }
            }
          if(check) visit-- ;
          if(c==k) break ;
        }
      if(visit<n && c==k) cout<< "some" << endl ;
      else if(visit==n && c==k) cout<< "all" << endl ;
      else cout<< "sad" << endl ;
    }
  }
