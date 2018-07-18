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

lli n, k, P, Q, x, a[10] ;

#define debug(x) cerr<< #x << "=" << x << endl

void solve(lli idx, vlli p)
  {
    if(idx>n || p.size()==k)
      {
        if(p.size()==k) for(int i=1 ; i<p.size()-1 ; i++) a[p[i]]++ ;
        return ;
      }
    solve(idx+1, p) ;
    p.pb(idx) ;
    solve(idx+1, p) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    vlli p ;
    solve(1, p) ;
    for(int i=1 ; i<=n ; i++) cout<< a[i] << "," ;
  }
