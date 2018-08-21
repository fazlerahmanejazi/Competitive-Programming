#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    lli h, w, x, y, z, mini, maxm, ans=INF ;
    cin>> h >> w ;
    for(lli i=1 ; i<=h/2 ; i++)
      {
        x=h-i ;
        y=w/2 ;
        z=w-(w/2) ;
        mini=INF ;
        maxm=-INF ;
        mini=min(mini, z*x) ; maxm=max(maxm, z*x) ;
        mini=min(mini, y*x) ; maxm=max(maxm, y*x) ;
        mini=min(mini, i*w) ; maxm=max(maxm, i*w) ;
        ans=min(ans, abs(mini-maxm)) ;
        mini=INF ;
        maxm=-INF ;
        x=h-i ;
        y=x/2 ;
        z=x-(x/2) ;
        mini=min(mini, z*w) ; maxm=max(maxm, z*w) ;
        mini=min(mini, i*w) ; maxm=max(maxm, i*w) ;
        mini=min(mini, y*w) ; maxm=max(maxm, y*w) ;
        ans=min(ans, abs(mini-maxm)) ;
      }
    for(lli i=1 ; i<=w/2 ; i++)
      {
        x=w-i ;
        y=h/2 ;
        z=h-(h/2) ;
        mini=INF ;
        maxm=-INF ;
        mini=min(mini, z*x) ; maxm=max(maxm, z*x) ;
        mini=min(mini, y*x) ; maxm=max(maxm, y*x) ;
        mini=min(mini, i*h) ; maxm=max(maxm, i*h) ;
        ans=min(ans, abs(mini-maxm)) ;
        mini=INF ;
        maxm=-INF ;
        x=w-i ;
        y=x/2 ;
        z=x-(x/2) ;
        mini=min(mini, z*h) ; maxm=max(maxm, z*h) ;
        mini=min(mini, i*h) ; maxm=max(maxm, i*h) ;
        mini=min(mini, y*h) ; maxm=max(maxm, y*h) ;
        ans=min(ans, abs(mini-maxm)) ;
      }
    cout<< ans ;
  }
