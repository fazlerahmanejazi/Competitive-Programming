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

lli n, b=31, p2[400400], hsh[400400], hsh2[400400] ;
string s, r ;

void hash_init()
  {
    p2[0]=1 ;
    for(int i=1 ; i<400400 ; i++) p2[i]=(p2[i-1]*b)%mod ;
    for(int i=1 ; i<=n ; i++)
      {
        hsh[i]=(hsh[i-1]+(s[i]-'a')*p2[i])%mod ;
        hsh2[i]=(hsh2[i-1]+(r[i]-'a')*p2[i])%mod ;
      }
  }

lli get_hsh(int l, int r)
  {
    return ((hsh[r]-hsh[l-1]+mod)*p2[n-l])%mod ;
  }

lli get_hsh2(int l, int r)
  {
    return ((hsh2[r]-hsh2[l-1]+mod)*p2[n-l])%mod ;
  }

bool is_pal(int l,int r)
  {
    return get_hsh(l, r)==get_hsh2(n-r+1, n-l+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int ans=0 ;
        cin>> s ;
        s=s+s ;
        n=s.length() ;
        r=s ;
        reverse(r.begin(), r.end()) ;
        s='#'+s ;
        r='#'+r ;
        hash_init() ;
        for(int i=1 ; i<=n/2 ; i++) if(is_pal(i, i+n/2-1)) ans++ ;
        cout<< ans << endl ;
      }
  }
