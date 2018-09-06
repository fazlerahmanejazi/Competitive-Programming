#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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

int n, u, v, x, num=1 ;
bool notPos ;
vi a, par ;
vb visit ;
queue<int> q ;
vector<multiset<int>> adj ;

void bfs(int start)
  {
    if(start!=1)
      {
        notPos=true ;
        return ;
      }
    visit[start]=true ;
    q.push(start) ;
    while(!q.empty())
      {
        u=q.front() ; q.pop() ;
        for(auto V:adj[u])
          {
            if(num>=n) return ;
            if(V==par[u]) continue ;
            v=a[num] ;
            if(adj[u].find(v)==adj[u].end())
              {
                notPos=true ;
                return ;
              }
            else
              {
                if(visit[v])
                  {
                    notPos=true ;
                    return ;
                  }
                num++ ;
                visit[v]=1 ;
                par[v]=u ;
                q.push(v) ;
              }
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    a.resize(n+1) ;
    par.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=1 ; i<n ; i++) cin>> u >> v, adj[u].insert(v), adj[v].insert(u) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    bfs(a[0]) ;
    if(notPos) cout<< "No" ;
    else cout<< "Yes" ;
  }
