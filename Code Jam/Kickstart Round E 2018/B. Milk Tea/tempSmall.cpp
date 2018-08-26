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

#define countBit(n) __builtin_popcountll(n)
#define checkBit(n, i) (((n)>>(i))&1)
#define setBit(n, i) (n|=(1<<i))

int get(string s)
  {
    int l=s.length(), x=0 ;
    for(int i=0 ; i<l ; i++) if(s[l-i-1]-'0') setBit(x, i) ;
    return x ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int n, m, p, curr, ans=inf, x ;
        string r ;
        vector<int> friends, forbidden ;
        cin>> n >> m >> p ;
        for(int i=0 ; i<n ; i++) cin>> r, friends.pb(get(r)) ;
        for(int i=0 ; i<m ; i++) cin>> r, forbidden.pb(get(r)) ;
        for(int i=0 ; i<(1<<p) ; i++)
          {
            curr=0 ;
            for(auto j:forbidden) if(i==j) curr=-1 ;
            if(curr==-1) continue ;
            for(auto j:friends) curr+=countBit(i^j) ;
            ans=min(ans, curr) ;
          }
        cout<< "Case #"<< tc << ": "<< ans << endl ;
      }
  }
