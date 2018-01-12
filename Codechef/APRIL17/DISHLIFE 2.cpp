#include <bits/stdc++.h>
using namespace std ;

int main()
 {
  ios_base::sync_with_stdio (false) ;
  int T, n, k, m, temp ;
  cin>> T ;
  while(T--)
    {
      cin>> n >> k ;
      vector<vector<int> > islands(n+10) ;
      set<int> ingredients ;
      map<int, int> cnt ;
      bool check=false, some=false ;
      for(int i=1 ; i<=n ; i++)
        {
          cin>> m ;
          for(int j=0 ; j<m ; j++)
            {
              cin>> temp ;
              islands[i].push_back(temp) ;
              cnt[temp]++ ;
              ingredients.insert(temp) ;
            }
        }
      if(ingredients.size()==k)
        {
          for(int i=1 ; i<=n ; i++)
            {
              check=true ;
              for(int j=0 ; j<islands[i].size() ; j++)
                  if(cnt[islands[i][j]]==1)
                    check=false ;
              if(check) some=true ;
            }
          if(some) cout<< "some" << endl ;
          else cout<< "all" << endl ;
        }
      else cout<< "sad" << endl ;
    }
  }
