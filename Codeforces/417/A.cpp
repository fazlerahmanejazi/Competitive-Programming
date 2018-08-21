#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

#define k 4

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int l[5], s[5], r[5], p[5] ;
    bool possible=false ;
    for(int i=0 ; i<4 ; i++)
      cin>> l[i] >> s[i] >> r[i] >> p[i] ;
    for(int i=0 ; i<4 ; i++)
      {
        if(l[i] && p[(i+3+k)%k]) possible=true ;
        if(l[i] && p[i]) possible=true ;
      }
    for(int i=0 ; i<4 ; i++)
      {
        if(r[i] && p[(i+1+k)%k]) possible=true ;
        if(r[i] && p[i]) possible=true ;
      }
    for(int i=0 ; i<4 ; i++)
      {
        if(s[i] && p[(i+2+k)%k]) possible=true ;
        if(s[i] && p[i]) possible=true ;
      }
    if(possible) cout<< "YES" ;
    else cout<< "NO" ;
  }
