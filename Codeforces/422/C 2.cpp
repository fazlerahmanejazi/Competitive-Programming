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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x, l, r, c, l1, l2, c1, c2, d1, d2, r1, r2 ;
    lli ans=2*INF, curr ;
    vector<vector<tuple<int, int, int>>> vouc ;
    set<int> check ;
    set<int>::iterator it ;
    cin>> n >> x ;
    vouc.resize(2*100000+1) ;
    map<int, bool> done ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r >> c ;
        vouc[r-l+1].pb(mt(l, r, c)) ;
        check.insert(r-l+1) ;
      }
    it=check.begin() ;
    while(it!=check.end())
      {
        d1=*it ;
        if(done[d1]) continue ;
        for(int i=0 ; i<vouc[d1].size() ; i++)
          {
            tie(l1, r1, c1)=vouc[d1][i] ;
            d2=x-d1 ;
            if(d2<0) d2=0 ;
            for(int j=0 ; j<vouc[d2].size() ; j++)
              {
                tie(l2, r2, c2)=vouc[d2][j] ;
                if((l2>l1 && r2>r1 && l2>r1) || (l1>l2 && r1>r2 & l1>r2))
                  {
                    if((lli)c1+(lli)c2<ans)
                      ans=c1+c2 ;
                  }
              }
          }
        done[d1]=true ;
        it++ ;
      }
    if(ans!=2*INF) cout<< ans ;
    else cout<< -1 ;
  }
