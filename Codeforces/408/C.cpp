#include <bits/stdc++.h>
using namespace std ;

#define f first
#define s second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, u, v, ans=-1, x, y, z ;
    cin>> n ;
    vector<int> a(n+1), degree(n+1, 0) ;
    vector<vector<int> > adj(n+1) ;
    vector<pair<int, int> > data ;
    for(int i=1 ; i<=n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
        degree[u]++ ;
        degree[v]++ ;
      }
    for(int i=1 ; i<=n ; i++)
        data.push_back(make_pair(degree[i], a[i])) ;
    sort(data.begin(), data.end()) ;
    for(int i=0 ; i<n ; i++)
      {
        y=data[i].s ;
        if(a[y]>ans) ans=a[y] ;
        for(int j=0 ; j<adj[y].size() ; j++)
          {
            z=adj[y][j] ;
            a[z]++ ;
            for(int k=0 ; k<adj[z].size() ; k++)
                a[adj[z][k]]++ ;
          }
      }
    cout<< ans ;

  }
