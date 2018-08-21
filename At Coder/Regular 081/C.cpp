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
    lli n, ans=-1 ;
    cin>> n ;
    vlli a(n) ;
    map<lli, int> cnt ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        cnt[a[i]]++ ;
      }
    vector<pair<lli, lli>> sticks ;
    for(auto x:cnt)
      sticks.pb(mp(x.fi, x.se)) ;
    sort(all(sticks)) ;
    reverse(all(sticks)) ;
    for(auto x:sticks)
      {
        if(x.se>=4 && ans==-1)
          {
            cout<< x.fi*x.fi ;
            return 0 ;
          }
        else if(x.se>=2 && ans==-1)
          {
            ans=x.fi ;
          }
        else if(x.se>=2)
          {
            ans*=x.fi ;
            cout<< ans ;
            return 0 ;
          }
      }
    cout<< 0 ;
  }
