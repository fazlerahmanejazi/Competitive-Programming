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
    int n, m, ans=0 ;
    cin>> n >> m ;
    vi a(n), b(m) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<m ; i++) cin>> b[i] ;
    for(int i=0 ; i<m-n+1 ; i++)
      {
        int chk=1 ;
        for(int j=0 ; j<n ; j++) if(a[j]==b[j+i]) chk=0 ;
        if(chk) ans++ ;
      }
    cout<< ans ;
  }
