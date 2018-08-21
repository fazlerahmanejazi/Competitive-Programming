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
    lli n, x, y, cnt=0, tot=0, ans=INF ;
    string s ;
    cin>> n >> x >> y >> s ;
    for(int i=0 ; i<n ; i++)
      if(s[i]=='0') cnt++ ;
      else if(cnt) cnt=0, tot++ ;
    if(cnt) tot++ ;
    for(lli i=0 ; i<tot ; i++) ans=min(ans, i*x+y*(tot-i)) ;
    if(ans==INF) ans=0 ;
    cout<< ans ;
  }
