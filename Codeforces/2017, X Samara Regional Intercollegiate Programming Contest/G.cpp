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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, x, y ;
    cin>> n ;
    string s ;
    vector<pair<int, string>> a(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> s, a[i]=mp(0, s) ;
    cin>> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> x >> y ;
        a[x]=mp(a[y].fi+1, a[y].se) ;
      }
    for(int i=0 ; i<a[1].fi ; i++) cout<< "I_love_" ;
    cout<< a[1].se ;
  }
