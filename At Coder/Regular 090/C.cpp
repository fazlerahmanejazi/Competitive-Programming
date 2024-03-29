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
    int n, k, x, tot, ans=0 ;
    cin>> n >> k ;
    vi cnt(n+1, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        cnt[x]++ ;
      }
    vpii a ;
    for(int i=1 ; i<=n ; i++)
      if(cnt[i])
        a.pb(mp(cnt[i], i)) ;
    sort(all(a)) ;
    tot=a.size() ;
    if(tot>k)
      {
        x=tot-k ;
        for(int i=0 ; i<x ; i++) ans+=a[i].fi ;
      }
    cout<< ans ;
  }
