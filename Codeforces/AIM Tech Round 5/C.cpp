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

lli n, xx1, yy1, xx2, yy2, x, y, t, cnt ;
vector<tuple<lli, lli, lli, lli>> rec ;
set<pair<lli, lli>> temp ;

lli check()
  {
    lli res=0 ;
    vector<pair<lli, lli>> a ;
    for(auto i:temp) a.pb(mp(i.fi, 1)), a.pb(mp(i.se+1, -1)) ;
    sort(all(a)) ;
    for(auto i:a)
      if(i.se==1)
        {
          res++ ;
          if(res>=n-1) return i.fi ;
        }
      else res-- ;
    return -inf ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> xx1 >> yy1 >> xx2 >> yy2 ;
        rec.pb(mt(xx1, yy1, yy2, 1)) ;
        rec.pb(mt(xx2+1, yy1, yy2, -1)) ;
      }
    sort(all(rec)) ;
    for(auto i:rec)
      {
        tie(x, yy1, yy2, t)=i ;
        if(t==1)
          {
            cnt++ ;
            temp.insert(mp(yy1, yy2)) ;
            if(cnt>=n-1)
              {
                y=check() ;
                if(y!=-inf)
                  {
                    cout<< x << " " << y ;
                    return 0 ;
                  }
              }
          }
        else cnt--, temp.erase(mp(yy1, yy2)) ;
      }
  }
