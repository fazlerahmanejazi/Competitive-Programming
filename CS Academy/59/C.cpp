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
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;int n ;
    string curr ;
    vector<string> s(3005) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> s[i] ;
    curr=s[1] ;
    vi pos ;
    pos.pb(0) ;
    for(int i=2 ; i<=n ; i++)
      {
        char c='z' ;
        for(int j=0 ; j<pos.size() ; j++)
          {
            if(s[i][pos[j]]<c) c=s[i][pos[j]] ;
            if(s[i][pos[j]+1]<c) c=s[i][pos[j]+1] ;
          }
        pos.clear() ;
        for(int j=0 ; j<i ; j++) if(s[i][j]==c) pos.pb(j) ;
        curr+=c ;
      }
    cout<< curr ;
  }
