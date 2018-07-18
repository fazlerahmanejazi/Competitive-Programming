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
    int n, k, ans=0, p=0 ;
    cin>> n >> k ;
    vi b(n) ;
    vpii a ;
    for(int i=0 ; i<n ; i++) cin>> b[i], a.pb(mp(b[i], i)) ;
    sort(all(a)) ;
    reverse(all(a)) ;
    for(int i=0 ; i<k ; i++)
      {
        for(int j=0 ; j<n ; j++)
          if(mp(b[j], j)==a[i])
            b[j]=-1 ;
        ans+=a[i].fi ;
      }
    cout<< ans << endl ;
    for(int i=0 ; i<n && k>1 ; i++)
      if(b[i]==-1)
        {
          cout<< i-p+1 << " " ;
          p=i+1 ;
          k-- ;
        }
    cout<< n-p ;
  }
