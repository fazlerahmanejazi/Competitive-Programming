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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, x, y, x1, x2, y1, y2, d, mxD=INF ;
        vlli prev, curr, ans ;
        map<lli, vector<lli>> p ;
        cin>> n ;
        for(int i=0 ; i<n ; i++) cin>> x >> y, p[x].pb(y) ;
        auto it1=p.begin(), it2=p.begin() ;
        it2++ ;
        while(it2!=p.end())
          {
            vector<pair<lli, lli>> temp ;
            curr=(*it2).se ;
            prev=(*it1).se ;
            x1=(*it1).fi ;
            x2=(*it2).fi ;
            for(auto i:prev) temp.pb(mp(i, x1)) ;
            for(auto i:curr) temp.pb(mp(i, x2)) ;
            sort(all(temp)) ;
            for(int i=1 ; i<temp.size() ; i++)
              {
                tie(y1, x1)=temp[i-1] ;
                tie(y2, x2)=temp[i] ;
                d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ;
                if(d<mxD)
                  {
                    mxD=d ;
                    ans.clear() ;
                    ans.pb(d) ; ans.pb(x1) ; ans.pb(y1) ; ans.pb(x2) ; ans.pb(y2) ;
                  }
              }
            it1++ ;
            it2++ ;
          }
        it1=p.begin() ;
        while(it1!=p.end())
          {
            vlli temp ;
            curr=(*it1).se ;
            for(auto i:curr) temp.pb(i) ;
            sort(all(temp)) ;
            x1=x2=(*it1).fi ;
            for(int i=1 ; i<temp.size() ; i++)
              {
                y1=temp[i-1] ;
                y2=temp[i] ;
                d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ;
                if(d<mxD)
                  {
                    mxD=d ;
                    ans.clear() ;
                    ans.pb(d) ; ans.pb(x1) ; ans.pb(y1) ; ans.pb(x2) ; ans.pb(y2) ;
                  }
              }
            it1++ ;
          }
        for(auto i:ans) cout<< i << " " ;
        cout<< endl ;
      }
  }
