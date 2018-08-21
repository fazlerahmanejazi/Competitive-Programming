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
    int n, q, x, y, z, pos ;
    string s ;
    vi idx[2] ;
    cin>> s ;
    n=s.length() ;
    for(int i=0 ; i<n ; i++)
      if(s[i]=='0') idx[0].pb(i+1) ;
      else idx[1].pb(i+1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> x >> y >> z ;
        pos=lower_bound(all(idx[z]), x)-idx[z].begin() ;
        if(pos+y-1>=idx[z].size()) cout<< -1 << endl ;
        else cout<< idx[z][pos+y-1] << endl ;
      }
  }
