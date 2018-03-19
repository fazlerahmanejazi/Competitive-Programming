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

int N, ans ;
vi res ;

void solve(int idx, int n)
  {
    if(n>N || n<1) return ;
    if(n==1)
      {
        res.pb(idx+n) ;
        return ;
      }
    int m=(n+1)/2 ;
    res.pb(idx+m) ;
    solve(idx, m-1) ;
    solve(m+idx, n-m) ;
    res.pb(idx+m) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> N ;
    solve(0, N) ;
    cout<< res.size() << endl ;
    for(int i=0 ; i<res.size() ; i++) cout<< res[i] << " " ;
  }
