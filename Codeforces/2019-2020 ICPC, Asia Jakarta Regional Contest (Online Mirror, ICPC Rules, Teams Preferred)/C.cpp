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
    int n, q, r1, c1, r2, c2, R1, R2, C1, C2 ;
    cin>> n >> q ;
    vi r(n+1, 0), c(n+1, 0) ;
    for(int i=1 ; i<=n ; i++) cin>> r[i], r[i]%=2, r[i]+=r[i-1] ;
    for(int i=1 ; i<=n ; i++) cin>> c[i], c[i]%=2, c[i]+=c[i-1] ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> r1 >> c1 >> r2 >> c2 ;
        R1=min(r1, r2) ;
        R2=max(r1, r2) ;
        C1=min(c1, c2) ;
        C2=max(c1, c2) ;
        bool pos=false ;
        if((r[R2]-r[R1-1])==R2-R1+1 && (c[C2]-c[C1-1])==C2-C1+1) pos=true ;
        if((r[R2]-r[R1-1])==0 && (c[C2]-c[C1-1])==0) pos=true ;
        if((r[R2]-r[R1-1])==R2-R1+1 && (c[C2]-c[C1-1])==0) pos=true ;
        if((r[R2]-r[R1-1])==0 && (c[C2]-c[C1-1])==C2-C1+1) pos=true ;
        if(pos) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
