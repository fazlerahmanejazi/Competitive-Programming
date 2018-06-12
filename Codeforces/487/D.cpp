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

#define ld long double

lli n, l, w, x, v, ans, curr ;
ld pos, L, R ;
vector<pair<ld, ld>> intervals ;
set<pair<ld, ld>> temp ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> l >> w ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> v ;
        pos=1.0*x+l/2.0 ;
        if(pos<0)
          {
            if(v>0)
              {
                L=(-pos/(v+w)) ;
                R=INF ;
                intervals.pb(mp(L, R)) ;
              }
            else if(w!=-v)
              {
                L=(-pos/(-v+w)) ;
                R=INF ;
                intervals.pb(mp(L, R)) ;
              }
          }
        else
          {
            if(v<0)
              {
                L=(pos/(-v+w)) ;
                R=INF ;
                intervals.pb(mp(L, R)) ;
              }
            else if(w!=v)
              {
                L=(pos/(w-v)) ;
                R=INF ;
                intervals.pb(mp(L, R)) ;
              }
          }
      }
    sort(all(intervals)) ;
    for(auto i:intervals)
      {
        temp.insert(mp(i.se, i.fi)) ;
        auto it=temp.begin() ;
        while(it!=temp.end())
          if((*it).fi<i.fi) it=temp.erase(it) ;
          else break ;
        ans+=temp.size()-1 ;
      }
    cout<< ans ;
  }
