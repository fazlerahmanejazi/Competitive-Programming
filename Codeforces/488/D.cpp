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

int n, m, x, y, cnt, ans ;
bool check=true ;
vpii a, b, A, B ;
vi cntA(30, 0), cntB(30, 0) ;

int get(pii p, pii q)
  {
    map<int, int> cnt ;
    cnt[p.fi]++ ; cnt[p.se]++ ;
    cnt[q.fi]++ ; cnt[q.se]++ ;
    if(cnt.size()==4) return 0 ;
    else if(cnt.size()==3) return 1 ;
    return 2 ;
  }

int common(pii p, pii q)
  {
    map<int, int> cnt ;
    cnt[p.fi]++ ; cnt[p.se]++ ;
    cnt[q.fi]++ ; cnt[q.se]++ ;
    if(cnt[p.fi]==2) return p.fi ;
    if(cnt[p.se]==2) return p.se ;
    if(cnt[q.fi]==2) return q.fi ;
    if(cnt[q.se]==2) return q.se ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, a.pb(mp(x, y)) ;
    for(int i=0 ; i<m ; i++) cin>> x >> y, b.pb(mp(x, y)) ;
    for(auto p1:a)
      {
        map<int, int> temp ;
        for(auto p2:b) if(get(p1, p2)==1) temp[common(p1, p2)]++ ;
        if(temp.size()==1) A.pb(p1) ;
        else if(temp.size()>1) check=false ;
      }
    for(auto p1:b)
      {
        map<int, int> temp ;
        for(auto p2:a) if(get(p1, p2)==1) temp[common(p1, p2)]++ ;
        if(temp.size()==1) B.pb(p1) ;
        else if(temp.size()>1) check=false ;
      }
    set<int> ans ;
    for(auto p1:A) for(auto p2:B) if(get(p1, p2)==1) ans.insert(common(p1, p2)) ;
    if(ans.size()>1 && check) cout<< 0 ;
    else if(ans.size()==1 && check) cout<< *(ans.begin()) ;
    else cout<< -1 ;
  }
