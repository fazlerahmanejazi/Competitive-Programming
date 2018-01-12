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

lli T, n, mi=inf, l, r, m, f1, f2, ans ;
vlli a, b ;

void init()
  {
    a.clear() ; b.clear() ;
    a.resize(n+1) ; b.resize(n+1) ;
  }

lli check(lli x)
  {
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      {
        if(a[i]<=x) res+=1LL*(x-a[i]) ;
        else res+=1LL*(b[i]+x-a[i]) ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        for(int i=0 ; i<n ; i++) cin>> b[i] ;
        for(int i=0 ; i<n ; i++)
          {
            a[i]%=b[i] ;
            mi=min(mi, b[i]) ;
          }
        ans=INF ;
        if(mi==1) ans=check(0) ;
        else if(mi>=100000)
          {
            ans=min(check(0), check(mi-1)) ;
          }
				else
					{
						for(int i=0 ; i<mi ; i++)
							ans=min(check(i), ans) ;
					}
        cout<< ans << endl ;
      }
  }
