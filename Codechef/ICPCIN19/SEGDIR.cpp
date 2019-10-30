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
    int t ;
    cin>> t ;
    while(t--)
      {
        lli n, l, r, v, cnt ;
        cin>> n ;
        bool pos=true ;
        map<lli, vector<pair<lli, lli>>> seg ;
        vector<pair<lli, lli>> temp1 ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> l >> r >> v ;
            seg[v].pb(mp(l, r)) ;
          }
        for(auto i:seg)
          {
            temp1=i.se ;
            if(temp1.size()>1)
              {
                vector<pair<lli, lli>> temp2 ;
                cnt=0 ;
                for(auto j:temp1)
                  {
                    temp2.pb(mp(j.fi, 1)) ;
                    temp2.pb(mp(j.se+1, -1)) ;
                  }
                sort(all(temp2)) ;
                for(auto j:temp2)
                  {
                    if(j.se==1) cnt++ ;
                    else cnt-- ;
                    if(cnt>2) pos=false ;
                  }
              }
          }
        if(pos) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
