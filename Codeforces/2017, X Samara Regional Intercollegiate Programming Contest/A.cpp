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

int n, bal ;
string s ;
vector<string> a ;
vector<pair<int, int>> b[3] ;

int get(string s, int t)
  {
    int res=0, tot=0 ;
    for(auto c:s)
      {
        if(c=='(') tot++ ;
        else tot-- ;
        res=min(res, tot) ;
      }
    if(t==1) return tot ;
    else return res ;
  }

void rev(string &s)
  {
    reverse(all(s)) ;
    for(auto &c:s)
      if(c=='(') c=')' ;
      else c='(' ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> s ;
        a[i]=s ;
        bal=get(s, 1) ;
        if(bal>0) b[0].pb(mp(-get(s, 2), i)) ;
        else if(bal<0) rev(s), b[2].pb(mp(get(s, 2), i)) ;
        else b[1].pb(mp(get(s, 2), i)) ;
      }
    s="" ;
    for(int i=0 ; i<3 ; i++) sort(all(b[i])) ;
    for(int i=0 ; i<3 ; i++) for(auto j:b[i]) s+=a[j.se] ;
    if(!get(s, 2) && !get(s, 1))
      {
        cout<< "YES" << endl ;
        for(int i=0 ; i<3 ; i++) for(auto j:b[i]) cout<< j.se << " " ;
      }
    else cout<< "NO" ;
  }
