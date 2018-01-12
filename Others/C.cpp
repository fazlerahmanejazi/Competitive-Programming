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
    int n, x, ans=inf, mx=-inf, res=0, curr ;
    cin>> n ;
    vi a(n+1), cnt(n+1, 0), check(n+1, 0) ;
    set<int> prev ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        prev.insert(a[i]) ;
        auto last=prev.end() ; last-- ;
        auto x=prev.upper_bound(a[i]) ;
        if(x==prev.end()) check[a[i]]=1, res++ ;
        else if(*x==*last) cnt[*last]++ ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        curr=res+cnt[i]+((check[i])?-1:0) ;
        if(curr>mx) mx=curr, ans=i ;
      }
    cout<< ans ;
  }
