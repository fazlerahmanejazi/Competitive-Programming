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
    int a, b, x, idx=0 ;
    cin>> a >> b >> x ;
    string s ;
    if(a>b) s="0", a-- ;
    else s="1", b-- ;
    while(x)
      {
        if(s[idx]=='0') s+='1', b-- ;
        else s+='0', a-- ;
        x-- ;
        idx++ ;
      }
    for(int i=0 ; i<s.length() ; i++)
      {
        cout<< s[i] ;
        if(a && s[i]=='0') while(a) cout<< '0', a-- ;
        if(b && s[i]=='1') while(b) cout<< '1', b-- ;
      }
  }
