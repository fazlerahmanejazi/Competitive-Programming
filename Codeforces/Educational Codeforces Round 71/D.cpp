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

lli n, x, y, tot=1, M=998244353, curr=1, ansA=1, ansB=1, ansAB=1, ans, cntA[300300], cntB[300300], fact[300300] ;
vector<pair<lli, lli>> a ;
map<pair<lli, lli>, lli> cntAB ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        cntA[x]++ ;
        cntB[y]++ ;
        cntAB[mp(x, y)]++ ;
        a.pb(mp(x, y)) ;
      }
    sort(all(a)) ;
    fact[0]=fact[1]=1 ;
    for(lli i=2 ; i<=n ; i++) fact[i]=(fact[i-1]*i)%M ;
    tot=fact[n] ;
    for(int i=1 ; i<=n ; i++)
      {
        ansA=(ansA*fact[cntA[i]])%M ;
        ansB=(ansB*fact[cntB[i]])%M ;
      }
    for(auto i:cntAB) ansAB=(ansAB*fact[i.se])%M ;
    for(int i=1 ; i<n ; i++) if(a[i].se<a[i-1].se) ansAB=0 ;
    ans=(tot-ansA-ansB+ansAB+M+M+M)%M ;
    cout<< ans ;
  }
