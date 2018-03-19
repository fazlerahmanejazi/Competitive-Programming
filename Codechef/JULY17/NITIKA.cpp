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
    int T, idx1, idx2 ;
    string s, ans, x, y ;
    char c ;
    cin>> T ;
    getline(cin, s) ;
    while(T--)
      {
        getline(cin, s) ;
        idx1=0 ;
        for(int i=s.length()-1 ; i>=0 ; i--)
          if(s[i]==' ')
            {
              idx1=i+1 ;
              break ;
            }
          else s[i]=tolower(s[i]) ;
        s[idx1]=toupper(s[idx1]) ;
        ans=s.substr(idx1, -1) ;
        if(!idx1)
          {
            cout<< ans << endl ;
            continue ;
          }
        idx2=0 ;
        for(int i=idx1-2 ; i>=0 ; i--)
          if(s[i]==' ')
            {
              idx2=i+1 ;
              break ;
            }
        c=toupper(s[idx2]) ;
        x=c ;
        y=". " ;
        ans=x+y+ans ;
        if(!idx2)
          {
            cout<< ans << endl ;
            continue ;
          }
        c=toupper(s[0]) ;
        x=c ;
        y=". " ;
        ans=x+y+ans ;
        cout<< ans << endl ;
      }
  }
