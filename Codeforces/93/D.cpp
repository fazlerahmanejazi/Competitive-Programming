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

lli n, b=31, p2[1000010], hsh[1000010] ;
vi idx ;
string s, ans="Just a legend" ;

void hash_init()
  {
    p2[0]=1 ;
    for(int i=1 ; i<1000010 ; i++) p2[i]=(p2[i-1]*b)%mod ;
    for(int i=1 ; i<=n ; i++) hsh[i]=(hsh[i-1]+(s[i]-'a')*p2[i])%mod ;
  }

lli get_hsh(int l, int r)
  {
    return ((hsh[r]-hsh[l-1]+mod)*p2[n-l])%mod ;
  }

bool check(int x)
  {
    return get_hsh(1, x)==get_hsh(n-x+1, n) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    s='#'+s ;
    hash_init() ;
    for(int i=2 ; i<=n ; i++) if(s[i]==s[1]) idx.pb(i) ;
    for(int i=n-1 ; i>=1 ; i--)
      if(check(i))
        for(auto j:idx)
          if(j+i-1<n && get_hsh(1, i)==get_hsh(j, j+i-1))
            {
              ans="" ;
              for(int k=1 ; k<=i ; k++) ans+=s[k] ;
              cout<< ans ;
              return 0 ;
            }
    cout<< ans ;
  }
