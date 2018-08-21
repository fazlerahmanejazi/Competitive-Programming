#include <bits/stdc++.h>
using namespace std ;

#define f first
#define s second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, u, v, ans=-1, x, y, z ;
    pair<int, int> temp ;
    cin>> n ;
    vector<int> a(n+1), degree(n+1, 0) ;
    vector<vector<int> > adj(n+1) ;
    vector<bool> visit(n+1, false) ;
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
        data.push_back(make_pair(degree[i], i)) ;
    sort(data.begin(), data.end()) ;
    priority_queue<pair<int, int>> pq ;
    for(int i=0 ; i<n ; i++)
      if(data[i].f==1)
          pq.push(make_pair(a[i], i)) ;
    while(!pq.empty())
      {
        temp=pq.top() ;
        pq.pop() ;
        y=temp.f ;
        x=temp.s ;
        if(!visit[temp.s])
          {
            visit[temp.s]=true ;
            if(a[y]>ans) ans=a[y] ;
            for(int j=0 ; j<adj[y].size() ; j++)
              {
                z=adj[y][j] ;
                pq.push(make_pair(a[z], z)) ;
                a[z]++ ;
                for(int k=0 ; k<adj[z].size() ; k++)
                    a[adj[z][k]]++ ;
              }
          }
      }
    ans=ans-2 ;
    cout<< ans ;

  }
