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
    string s ;
    char w ;
    int a, b, aR, bR, m ;
    while(cin>> s)
      {
        a=b=m=0 ; aR=bR=5 ;
        for(int i=0 ; i<10 && !m ; i++)
          {
            if(!(i%2)) a=(s[i]=='1')?a+1:a, aR-- ;
            else b=(s[i]=='1')?b+1:b, bR-- ;
            if(aR+a<b) w='B', m=i+1 ;
            if(bR+b<a) w='A', m=i+1 ;
          }
        for(int i=11 ; i<20 && !m ; i+=2)
          {
            a=(s[i-1]=='1')?1:0, aR-- ;
            b=(s[i]=='1')?1:0, bR-- ;
            if(a>b) w='A', m=i+1 ;
            if(b>a) w='B', m=i+1 ;
          }
        if(!m) cout<< "TIE" << endl ;
        else cout<< "TEAM-" << w << " " << m << endl ;
      }
  }
