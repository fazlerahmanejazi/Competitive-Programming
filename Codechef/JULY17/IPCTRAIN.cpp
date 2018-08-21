#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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

int T, N, D, d, t, s ;
lli ans, x ;
pii q ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> N >> D ;
        vector<vpii> day(D+1) ;
        priority_queue<pii> pq ;
        for(int i=0 ; i<N ; i++)
          {
            cin>> d >> t >> s ;
            day[d].pb(mp(s, t)) ;
          }
        ans=0 ;
        for(int i=1 ; i<=D; i++)
          {
            if(!day[i].empty())
              for(int j=0 ; j<day[i].size() ; j++)
                pq.push(day[i][j]) ;
            if(!pq.empty())
              {
                q=pq.top() ; pq.pop() ;
                if(q.se>1) pq.push(mp(q.fi, q.se-1)) ;
              }
          }
        while(!pq.empty())
          {
            q=pq.top() ; pq.pop() ;
            x=q.se ; s=q.fi ;
            ans+=(x*s) ;
          }
        cout<< ans << endl ;
      }
  }
