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

int n, k, ans=inf, d ;
string s, r="", temp ;

int cost(int x)
  {
    int res=0 ;
    vi p ;
    for(int i=0 ; i<n ; i++) p.pb(abs(s[i]-'0'-x)) ;
    sort(all(p)) ;
    for(int i=0 ; i<k ; i++) res+=p[i] ;
    return res ;
  }

string construct(int x)
  {
    string r ;
    r=s ;
    vector<tuple<int, int, int>> p ;
    for(int i=0 ; i<n ; i++)
      if(s[i]-'0'-x) p.pb(mt(abs(s[i]-'0'-x), x-s[i]+'0', (s[i]-'0'-x)*i/abs(s[i]-'0'-x))) ;
      else p.pb(mt(0, 0, i)) ;
    sort(all(p)) ;
    for(int i=0 ; i<k ; i++) r[abs(get<2>(p[i]))]=(char)(x+'0') ;
    return r ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k >> s ;
    for(int i=0 ; i<=9 ; i++) ans=min(ans, cost(i)) ;
    for(int i=0 ; i<=9 ; i++)
      if(cost(i)==ans)
        {
          temp=construct(i) ;
          if(r=="") r=temp ;
          if(temp<r) r=temp ;
        }
    construct(d) ;
    cout<< ans << endl ;
    cout<< r ;
  }
