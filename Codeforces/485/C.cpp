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
    lli n, ans=INF ;
    cin>> n ;
    vector<pair<lli, lli>> a(n) ;
    vlli m(n+1, INF) ;
    for(int i=0 ; i<n ; i++) cin>> a[i].fi ;
    for(int i=0 ; i<n ; i++) cin>> a[i].se ;
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        if(a[j].fi>a[i].fi)
          m[i]=min(m[i], a[j].se) ;
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        if(a[j].fi>a[i].fi && a[i].se+a[j].se+m[j]<ans)
          ans=a[i].se+a[j].se+m[j] ;
    if(ans==INF) cout<< -1 ;
    else cout<< ans ;
  }
