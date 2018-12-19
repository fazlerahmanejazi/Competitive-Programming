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
    while(T--)
      {
        int n, x, l, r, a[100] ;
        memset(a, 0, sizeof a) ;
        bool pos=true ;
        string s ;
        cin>> s ;
        n=s.length() ;
        s='#'+s ;
        for(int i=1 ; i<=n ; i++)
          if(s[i]!='.')
            {
              x=s[i]-'0' ;
              l=max(i-x, 1) ;
              r=min(i+x, n) ;
              for(int j=l ; j<=r ; j++) a[j]++ ;
            }
        for(int i=1 ; i<=n ; i++) if(a[i]>1) pos=false ;
        if(pos) cout<< "safe" << endl ;
        else cout<< "unsafe" << endl ;
      }
  }
