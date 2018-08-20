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

int n, u, v ;
vi a, cnt(705, 0) ;
vvi adj(705) ;
vb visit(705, false) ;
queue<int> q ;

void bfs(int s)
  {
    visit[s]=true ;
    q.push(s) ;
    while(!q.empty())
      {
        u=q.front() ; q.pop() ;
        for(auto v:adj[u])
          if(!visit[v] && cnt[v]<3 && cnt[u]<3)
            {
              q.push(v) ;
              visit[v]=true ;
              cnt[v]++ ;
              cnt[u]++ ;
            }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    set<int> s ;
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        if(__gcd(a[i], a[j])!=1)
          {
            s.insert(a[i]) ;
            s.insert(a[j]) ;
          }
    if(s.size()!=n) cout<< "NO" ;
    else cout<< "YES" ;
  }
