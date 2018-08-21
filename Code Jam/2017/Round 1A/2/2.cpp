#include <bits/stdc++.h>
using namespace std ;

int ans, temp, n, p, maxm, k ;
vector<int> serving, record ;
vector<vector<int> > packages ;
bool avail[1000][1000] ;

bool valid(int x, int i)
  {
    double l, u ;
    if(k==-1) k=x/serving[i] ;
    l=(k*serving[i])*0.9 ;
    u=(k*serving[i])*1.1 ;
    if(x>=l && x<=u) return true ;
    l=((k+1)*serving[i])*0.9 ;
    u=((k+1)*serving[i])*1.1 ;
    if(x>=l && x<=u) return true ;
    return false ;
  }

void backtrack(int t, int cnt)
  {
    if(cnt==n)
      {
        ans++ ;
        for(int i=0 ; i<record.size() ; i++)
          avail[i][record[i]]=false ;
      }
    if(t==n) return ;
    for(int i=0 ; i<p ; i++)
      {
          if(t==0) k=-1 ;
          if(valid(packages[t][i], t) && avail[t][i])
            {
              record.push_back(i) ;
              backtrack(t+1, cnt+1) ;
              record.pop_back() ;
            }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> p ;
        ans=0 ;
        serving.assign(n, 0) ;
        packages.clear() ;
        packages.resize(n) ;
        memset(avail, 1, sizeof avail) ;
        for(int i=0 ; i<n ; i++)
          cin>> serving[i] ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<p ; j++)
            {
              cin>> temp ;
              packages[i].push_back(temp) ;
              maxm=max(temp, maxm) ;
            }
        //for(int i=0 ; i<n ; i++)
          //sort(packages[i].begin(), packages[i].end()) ;
        k=-1 ;
        backtrack(0, 0) ;
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
