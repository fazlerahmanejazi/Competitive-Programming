#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, m, k, x, cycle, notPos, check ;
priority_queue<int> pq ;
vi p ;
vvi d ;
vector<set<int>> adj ;
vb visit ;

void solve(int l, int r, int idx)
  {
    int prev=l, u, v ;
    for(int i=l ; i<=r ; i++)
      if(d[i][idx]!=d[prev][idx])
        {
          if(i-prev>1 && idx+1<m) solve(prev, i-1, idx+1) ;
          u=d[prev][idx] ; v=d[i][idx] ;
          adj[u].insert(v) ;
          prev=i ;
        }
    if(r-prev>=1) solve(prev, r, idx+1) ;
  }

void dfs(int u)
  {
    visit[u]=true ;
    if(!pq.empty())
      {
        int x=-pq.top() ;
        pq.pop() ;
        p[u]=x ;
      }
    else notPos=1 ;
    for(auto v:adj[u])
      if(!visit[v]) dfs(v) ;
      else cycle=1 ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k >> m ;
    d.resize(n+1) ;
    p.assign(k+1, 0) ;
    adj.resize(k+1) ;
    visit.assign(k+1, false) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> x ;
          d[i].pb(x) ;
        }
    solve(0, n-1, 0) ;
    for(int i=1 ; i<k ; i++) pq.push(-i) ;
    /*for(int i=0 ; i<m ; i++)
      for(auto s:start[i])
        if(!visit[s])
          {
            dfs(s) ;
            if(!check) pq.push(0), check++ ;
          }
    */
    for(int j=0 ; j<m ; j++)
      {
        if(j==1 && m!=1) pq.push(0), check++ ;
        for(int i=0 ; i<n ; i++)
          if(!visit[d[i][j]])
            {
              int s=d[i][j] ;
              dfs(s) ;
            }
      }
    for(int i=0 ; i<k ; i++)
      if(!visit[i])
        dfs(i) ;
    if(notPos || cycle) cout<< -1 ;
    else
      {
        map<int, int> cnt ;
        for(int i=0 ; i<k ; i++)
          {
            cnt[p[i]]++ ;
            if(cnt[p[i]]>1)
              {
                cout<< -1 ;
                return 0 ;
              }
          }
        for(int i=0 ; i<k ; i++) cout<< p[i] << " " ;
      }
  }
