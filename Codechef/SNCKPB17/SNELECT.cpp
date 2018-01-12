#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, cs, cm ;
    string s ;
    cin>> T ;
    while(T--)
      {
        cin>> s ;
        s='*'+s ;
        cs=cm=0 ;
        for(int i=1 ; i<s.length() ; i++)
          {
            if(s[i]=='m' && s[i-1]=='s') s[i-1]='*' ;
            else if(s[i]=='m' && s[i+1]=='s') s[i+1]='*' ;
          }
        for(int i=1 ; i<s.length() ; i++)
          if(s[i]=='m') cm++ ;
          else if(s[i]=='s') cs++ ;
        if(cm>cs) cout<< "mongooses" << endl ;
        else if(cm==cs) cout<< "tie" << endl ;
        else cout<< "snakes" << endl ;
      }
  }
