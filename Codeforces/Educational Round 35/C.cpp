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
    vi a(3) ;
    cin>> a[0] >> a[1] >> a[2] ;
    sort(all(a));
    bool pos=false ;
    if(a[0]==1) pos=true ;
    if(a[0]==2 && a[1]==2) pos=true ;
    if(a[0]==3 && a[1]==3 && a[2]==3) pos=true ;
    if(a[0]==2 && a[1]==4 && a[2]==4) pos=true ;
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
