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

lli l, r, ans=0, posL, posR ;
vlli num ;

void generate(lli n, int c)
  {
    if(c>10) return ;
    num.pb(n) ;
    generate(10*n+4, c+1) ;
    generate(10*n+7, c+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    generate(0, 0) ;
    sort(all(num)) ;
    cin>> l >> r ;
    posL=lower_bound(all(num), l)-num.begin() ;
    posR=lower_bound(all(num), r)-num.begin() ;
    ans=(min(num[posL], r)-l+1)*num[posL] ;
    for(int i=posL+1 ; i<posR ; i++)
      ans+=(num[i]-num[i-1])*num[i] ;
    if(num[posL]<r) ans+=(r-max(num[posR-1], l))*num[posR] ;
    cout<< ans ;
  }
