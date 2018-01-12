#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, m, k, d, f, t, c, cntA, cntD, diff, l, r ;
lli ans=INF, curr ;
vi days ;
vector<tuple<int, int, int, int>> data ;
vector<set<int>> arrive, depart ;
vlli dpA, dpD ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> d >> f >> t >> c ;
        data.pb(mt(d, f, t, c)) ;
        days.pb(d) ;
      }
    arrive.resize(n+1) ; depart.resize(n+1) ;
    dpA.assign(m+1, INF) ; dpD.assign(m+1, INF) ;
    sort(all(data)) ; sort(all(days)) ;
    curr=0 ;
    for(int i=0 ; i<m ; i++)
      {
        tie(d, f, t, c)=data[i] ;
        if(f)
          {
            if(!arrive[f].size()) arrive[f].insert(c), curr+=c, cntA++ ;
            else curr-=*(arrive[f].begin()), arrive[f].insert(c), curr+=*(arrive[f].begin()) ;
            if(cntA==n) dpA[i]=min(dpA[i], curr) ;
          }
      }
    curr=0 ;
    for(int i=m-1 ; i>=0 ; i--)
      {
        tie(d, f, t, c)=data[i] ;
        if(t)
          {
            if(!depart[t].size()) depart[t].insert(c), curr+=c, cntD++ ;
            else curr-=*(depart[t].begin()), depart[t].insert(c), curr+=*(depart[t].begin()) ;
            if(cntD==n) dpD[i]=min(dpD[i], curr) ;
          }
      }
    for(int i=0 ; i<m ; i++)
      {
        l=i ;
        r=upper_bound(all(days), days[l]+k)-days.begin() ;
        if(r!=m)
          {
            curr=dpA[l]+dpD[r] ;
            ans=min(curr, ans) ;
          }
      }
    if(ans==INF) cout<< -1 ;
    else cout<< ans ;
  }
