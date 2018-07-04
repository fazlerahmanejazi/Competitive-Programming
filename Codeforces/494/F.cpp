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

lli n, b=31, c=71, ans, tot, x, y, z, p1[400400], p2[400400] ;
vlli a ;
string s ;
vector<lli> H ;
map<tuple<lli, lli, lli>, lli> cnt ;

void init()
  {
    p1[0]=p2[0]=1 ; ;
    for(int i=1 ; i<400400 ; i++) p1[i]=(p1[i-1]*b)%mod ;
    for(int i=1 ; i<400400 ; i++) p2[i]=(p2[i-1]*c)%mod ;
  }

lli getHash(string s)
  {
    lli H1=0, H2=0 ;
    for(int i=1 ; i<s.length() ; i++)
      {
        H1=(H1+(s[i]-'a')*p1[i])%mod ;
        H2=(H2+(s[i]-'a')*p2[i])%mod ;
      }
    return H1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    cin>> n ;
    ans=n-1 ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s ;
        ans+=s.length() ;
        a.pb(s.length()) ;
        H.pb(getHash(s)) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        x=y=0 ;
        for(int j=i ; j<n ; j++)
          {
            x+=H[j] ;
            y+=a[j] ;
            cnt[mt(x, y, j-i)]++ ;
          }
      }
    tot=ans ;
    for(auto i:cnt)
      if(i.se>=2)
        {
          tie(x, y, z)=i.fi ;
          ans=min(ans, tot-2*y+2) ;
          cout<< ans << endl ;
        }
    cout<< ans ;
  }
