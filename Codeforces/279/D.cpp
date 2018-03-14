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

lli a1, b1, a2, b2, t1, t2, p, ans=INF ;
map<lli, tuple<lli, lli, lli>> X, Y ;

void solve(lli a, lli b, lli t, map<lli, tuple<lli, lli, lli>> &Z)
  {
    if(Z.find(a*b)!=Z.end() && get<2>(Z[a*b])<=t) return ;
    Z[a*b]=mt(a, b, t) ;
    if(!(a%2)) solve(a/2, b, t+1, Z) ;
    if(!(b%2)) solve(a, b/2, t+1, Z) ;
    if(!(a%3)) solve(2*a/3, b, t+1, Z) ;
    if(!(b%3)) solve(a, 2*b/3, t+1, Z) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> a1 >> b1 >> a2 >> b2 ;
    solve(a1, b1, 0, X) ;
    solve(a2, b2, 0, Y) ;
    for(auto i:X)
      {
        p=i.fi ;
        if(Y.find(p)!=Y.end() && get<2>(X[p])+get<2>(Y[p])<ans)
          {
            tie(a1, b1, t1)=X[p] ;
            tie(a2, b2, t2)=Y[p] ;
            ans=t1+t2 ;
          }
      }
    if(ans==INF) cout<< -1 ;
    else cout<< ans << endl << a1 << " " << b1 << endl << a2 << " " << b2 ;
  }
