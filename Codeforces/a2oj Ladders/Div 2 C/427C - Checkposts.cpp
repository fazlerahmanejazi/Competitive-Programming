#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007

int n, m, a, b, s, cnt, minM ;
long long int ans, ways=1 ;
vector<bool> visit;
vector<int> price, postvisit ;
vector<vector<int>> adj, adj_rev ;

void dfs_rev(int t)
  {
    visit[t]=true ;
    for(int i=0 ; i<adj_rev[t].size() ; i++)
      if(visit[adj_rev[t][i]]!=true)
        dfs_rev(adj_rev[t][i]) ;
    postvisit.push_back(t) ;
  }

void dfs(int t)
  {
    visit[t]=true ;
    if(price[t]==minM) cnt++ ;
    else if(price[t]<minM)
      {
        cnt=1 ;
        minM=price[t] ;
      }
    for(int i=0 ; i<adj[t].size() ; i++)
      if(visit[adj[t][i]]!=true)
        dfs(adj[t][i]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n ;
    price.resize(n+1) ;
    adj.resize(n+1) ;
    adj_rev.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<=n ; i++)
      cin>> price[i] ;
    cin>> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b ;
        adj[a].push_back(b) ;
        adj_rev[b].push_back(a) ;
      }
    for(int i=1 ; i<=n ; i++)
      if(visit[i]==false)
        dfs_rev(i) ;
    visit.assign(n+1, false) ;
    for(int i=0 ; i<n ; i++)
      {
        s=postvisit[n-i-1] ;
        if(!visit[s])
          {
            minM=inf ;
            cnt=1 ;
            dfs(s) ;
            cnt%=mod ;
            ways=(ways*cnt)%mod ;
            ans+=minM ;
          }
      }
    cout<< ans << " " << ways ;
  }
