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

int n, x, len ;
bool pos ;
vi dp ;

int next(int len, int s)
  {
    int l=s, m, r=n-1, curr ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=(dp[m]-dp[s])+(m-s-1) ;
        if(curr==len) return m ;
        else if(curr<len) l=m+1 ;
        else r=m-1 ;
      }
    return -1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    string qq ;
    getline(cin, qq) ;
    while(T--)
      {
        string temp, s ;
        s="" ;
        stringstream ss ;
        getline(cin, temp) ;
        dp.clear() ;
        pos=false ;
        ss<< temp ;
        while(ss>> temp)
          {
            s+=temp ;
            dp.pb(s.length()) ;
          }
        n=dp.size() ;
        for(int i=0 ; i<n ; i++)
          {
            len=dp[i]+i ;
            x=i ;
            while(1)
              {
                x=next(len, x) ;
                if(x==n-1) pos=true ;
                if(x==-1) break ;
              }
          }
        if(pos || dp.size()==1) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
