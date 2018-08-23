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
    int n, m, idx1=-1, idx2=-1 ;
    bool pos=true, check=false ;
    string s, t ;
    cin>> n >> m >> s >> t ;
    if(n-1>m) return cout<< "NO", 0 ;
    for(auto i:s) if(i=='*') check=true ;
    if(check)
      {
        for(int i=0 ; i<n ; i++)
          if(s[i]!='*') pos&=(s[i]==t[i]) ;
          else
            {
              idx1=i ;
              break ;
            }
        for(int i=0 ; i<n ; i++)
          if(s[n-i-1]!='*') pos&=(s[n-i-1]==t[m-i-1]) ;
          else
            {
              idx2=m-i-1 ;
              break ;
            }
        for(int i=idx1 ; i<=idx2 ; i++) if(t[i]<'a' || t[i]>'z') pos=false ;
      }
    else pos&=(s==t) ;
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
