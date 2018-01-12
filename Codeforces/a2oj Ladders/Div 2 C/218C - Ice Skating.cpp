#include <bits/stdc++.h>
using namespace std ;

#define x first
#define y second

int n, x, y, c ;
vector<bool> visit ;
vector<pair<int, int>> point ;

void dfs(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<n ; i++)
      if(!visit[i] && (point[i].x==point[t].x || point[i].y==point[t].y))
        dfs(i) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        point.push_back(make_pair(x, y)) ;
      }
    visit.assign(n+1, false) ;
    for(int i=0 ; i<n ; i++)
      if(!visit[i])
        {
          dfs(i) ;
          c++ ;
        }
    cout<< c-1 ;
  }
