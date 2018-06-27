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

int N, t ;

bool check(vi b)
  {
    if(b[1]<b[0]) return false ;
    for(int i=3 ; i<N ; i+=2) if(b[i]<b[i-2] || b[i]<b[i-1]) return false ;
    return true ;
  }

map<int, int> cnt ;

void perform(vi b)
  {
    vb taken(N+1, false) ;
    vpii seg ;
    for(int i=1 ; i<N ; i+=2) seg.pb(mp(b[i-1], b[i])) ;
    sort(all(seg)) ;
    for(int i=0 ; i<seg.size() ; i++)
      if(!taken[i])
        {
          int l, r ;
          tie(l, r)=seg[i] ;
          taken[i]=true ;
          for(int j=i+1 ; j<seg.size() ; j++)
            if(seg[j].fi<r)
              {
                taken[j]=true ;
                r=max(r, seg[j].se) ;
              }
          cnt[r]++ ;
          cnt[l]-- ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> N ;
    t=0 ;
    vi a ;
    for(int i=1 ; i<=N ; i++) a.pb(i) ;
    do {
      if(check(a))
        {
          //for(auto i:a) cout<< i << " " ;
          //cout<< endl ;
          //t++ ;
          perform(a) ;
        }
    } while(next_permutation(all(a))) ;
    for(auto i:cnt) cout<< i.se << " " ;
    //cout<< t << endl ;
  }
