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
    int n ;
    cin>> n ;
    string s ;
    cin>> s ;
    if(n==8) cout<< "vaporeon" ;
    else if(n==6) cout<< "espeon" ;
    else
      {
        if(s[0]=='j' || s[1]=='o' || s[3]=='t') cout<< "jolteon" ;
        else if(s[0]=='f' || s[3]=='r') cout<< "flareon" ;
        else if(s[0]=='u' || s[1]=='m' || s[2]=='b') cout<< "umbreon" ;
        else if(s[0]=='l' || s[1]=='e' || s[3]=='f') cout<< "leafeon" ;
        else if(s[0]=='g' || s[3]=='c') cout<< "glaceon" ;
        else cout<< "sylveon" ;
      }
  }
