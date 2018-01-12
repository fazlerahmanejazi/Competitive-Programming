#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    int n, k ;
    cin>> n >> k ;
    vi a(n), b(k), c(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<k ; i++)
      cin>> b[i] ;
    sort(all(b)) ;
    reverse(all(b)) ;
    int idx=0 ;
    for(int i=0 ; i<n ; i++)
      if(a[i]==0)
        a[i]=b[idx++] ;
    for(int i=0 ; i<n ; i++)
      c[i]=a[i] ;
    sort(all(c)) ;
    for(int i=0 ; i<n ; i++)
      if(a[i]!=c[i])
        {
          cout<< "Yes" ;
          return 0 ;
        }
    cout<< "No" ;
  }
