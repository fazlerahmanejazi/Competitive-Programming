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
    lli T, k, x, curr, m ;
    bool opp ;
    vlli len ;
    curr=1 ;
    while(curr<=10e18 && curr>=0)
      {
        len.pb(curr) ;
        curr=2*curr+1 ;
      }
    cin>> T ;
    while(T--)
      {
        cin>> k ;
        opp=false ;
        while(k>3)
          {
            x=lower_bound(all(len), k)-len.begin() ;
            m=(len[x]+1)/2 ;
            if(k==m)
              {
                if(opp) cout<< "c" << endl ;
                else cout<< "a" << endl ;
                break ;
              }
            else
              {
                k=(len[x]/2)-(k-(m+1)) ;
                opp=!opp ;
              }
          }
        if(k==3)
          {
            if(opp) cout<< "a" << endl ;
            else cout<< "c" << endl ;
          }
        else if(k<=2)
          {
            if(opp) cout<< "c" << endl ;
            else cout<< "a" << endl ;
          }
      }
  }
