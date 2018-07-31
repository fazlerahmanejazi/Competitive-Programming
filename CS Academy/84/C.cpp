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

lli n, x, y, m ;
vlli a ;
set<lli> sticks ;
vpii ans ;
priority_queue<lli, vector<lli>, greater<lli>> pq ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        if(x%2)
          {
            if(sticks.find(x)!=sticks.end()) sticks.erase(x) ;
            else sticks.insert(x) ;
          }
        else ans.pb(mp(x, x/2)) ;
      }
    if((sticks.size())%2) return cout<< -1, 0 ;
    for(auto i:sticks) pq.push(i) ;
    while(!pq.empty())
      {
        x=pq.top() ; pq.pop() ;
        if(!(x%2))
          {
            ans.pb(mp(x, x/2)) ;
            continue ;
          }
        if(x%2 && pq.empty()) return cout<< -1, 0 ;
        y=pq.top() ; pq.pop() ;
        if(x==y) continue ;
        ans.pb(mp(y, x)) ;
        pq.push(y-x) ;
      }
    cout<< ans.size() << endl ;
    for(auto i:ans) cout<< i.fi << " " << i.se << endl ;
  }
