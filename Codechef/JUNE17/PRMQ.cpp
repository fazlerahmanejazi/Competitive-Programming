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

int n, q, L, R, X, Y, maxElement=-1, c, u, idx ;
vi  a, fac, tree, ans ;
vector<vpii> data ;
vector<vector<tuple<int, int, int, bool>>> query ;
bool check ;

void init()
  {
    fac.resize(u+1) ;
    data.resize(u+1) ;
    tree.assign(n+1, 0) ;
    ans.assign(q+1, 0) ;
    query.resize(u+1) ;
  }

void sieve()
  {
    for(int i=1 ; i<=u ; i++)
      fac[i]=i ;
    for (int i=2 ; i<=sqrt(u)+1 ; i++)
      for(int j=i ; j<=u ; j+=i)
        if(fac[j]==j)
          fac[j]=i ;
  }

void solve()
  {
    for(int i=0 ; i<n ; i++)
      {
        c=a[i] ;
        while(c!=1)
          {
            if(data[fac[c]].empty() || data[fac[c]].back().fi!=i) data[fac[c]].pb(mp(i, 1)) ;
            else data[fac[c]].back().se++ ;
            c=c/fac[c] ;
          }
      }
  }

int sum(int i)
  {
    int temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1)
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<n ; i=(i|(i+1)))
      tree[i]+=val ;
  }

int getSum(int l, int r)
  {
    return sum(r)-sum(l-1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        maxElement=max(maxElement, a[i]) ;
      }
    u=maxElement+1 ;
    cin>> q ;
    init() ; sieve() ; solve() ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> L >> R >> X >> Y ;
        query[min(X-1, u)].pb(mt(i, L-1, R-1, false)) ;
        query[min(Y, u)].pb(mt(i, L-1, R-1, true)) ;
      }
    for(int i=0 ; i<=u ; i++)
      {
        for(int j=0 ; j<data[i].size() ; j++)
          update(data[i][j].fi, data[i][j].se) ;
        for(int j=0 ; j<query[i].size() ; j++)
          {
            tie(idx, L, R, check)=query[i][j] ;
            if(check) ans[idx]+=getSum(L, R) ;
            else ans[idx]-=getSum(L, R) ;
          }
      }
    for(int i=0 ; i<q ; i++)
      cout<< ans[i] << endl ;
  }
